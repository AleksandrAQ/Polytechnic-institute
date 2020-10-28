#include <iostream>
#include <vector>

#include <stdlib.h>
#include <ctime>

using namespace std;

template <typename T>
void sort(vector<T> &v)
{
	for (int i=0; i<v.size()-1; i++)
	{
		for (int j = i+1; j<v.size(); j++)
		{
			if (v[i]>v[j])
			{
				int curr = v[i];
				v[i] = v[j];
				v[j] = curr;
			}
		}
	};
};

template <typename T>
void printall(vector<T> v)
{
	for (int i=0; i<v.size(); i++)
	{
		cout<<v[i]<<endl;
	};
};


template <typename T>
void fillrand(vector <T> &v, int n)
{
	for (int i = 0; i < n; i++)
	{
		v.push_back(rand() %n);
	};
};

int main (int argc, char** argv)
{// начальное время
    // здесь должен быть фрагмент кода, время выполнения которого нужно измерить
	vector<int> v;
	int n = atoi(argv[1]);


	fillrand(v, n);
	cout<<"Begin"<<endl;
  unsigned int start_time =  clock();
	sort(v);

  unsigned int end_time = clock(); // конечное время
  unsigned int search_time = end_time - start_time;

  cout<<search_time<<endl;

	return 0;
}
