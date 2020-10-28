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

int main (void)
{
	vector<int> v;
	int n;


	cin>>n;
	fillrand(v, n);
	cout<<"Begin"<<endl;
	sort(v);
	printall(v);

	return 0;
}