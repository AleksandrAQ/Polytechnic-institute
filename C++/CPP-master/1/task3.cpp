#include <iostream>
#include <vector>

#include <stdlib.h>
#include <ctime>

using namespace std;

template <typename T>
void sort(vector<T> &v)
{
	for (auto i=v.begin(); i!=v.end(); i++)
	{
		for (auto j = i+1; j!=v.end(); j++)
		{
			if ((*i)>(*j))
			{
				T curr = *i;
				*i = *j;
				*j = curr;
			}
		}
	};
};

template <typename T>
void printall(vector<T> v)
{
	for (auto i=v.begin(); i!=v.end(); i++)
	{
		cout<<*i<<endl;
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
{

	vector<int> v;
	int n = atoi(argv[1]);

	fillrand(v, n);
	cout<<"Begin"<<endl;
	unsigned int start_time = clock();
	sort(v);

	unsigned int end_time = clock(); // конечное время
	unsigned int search_time = end_time - start_time;

	cout<<search_time<<endl;
	return 0;
}
