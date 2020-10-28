/*
Autor - Golishev Roman, 22.09.2014

6)	Напишите функцию void fillRandom(double* array, int size) 
заполняющую массив случайными значениями в интервале от -1.0 до 1.0.
 Заполните с помощью заданной функции вектора размером 5,10,25,50,100 и
  отсортируйте его содержимое (с помощью любого разработанного ранее алгоритма 
модифицированного для сортировки действительных чисел) 
*/

#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

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
				T curr = v[i];
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
		v.push_back((rand()%1000/double(1000))*2 - 1);
	};
};

int main ()
{
	vector<vector<double>> v(5);
	srand(time(0));

	fillrand(v[0],5);
	fillrand(v[1],10);
	fillrand(v[2],25);
	fillrand(v[3],50);
	fillrand(v[4],100);

	cout<<"Begin"<<endl;
	for(auto i: v)
	{
		sort(i);
		printall<double>(i);
		cin.get();
	};

	return 0;
}
