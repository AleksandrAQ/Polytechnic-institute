/*
Autor - Golishev Roman, 22.09.2014

2.	Разработайте программу, которая
a.	Заполняет list<int> 15 случайными значениями от 1 до 20, список может содержать от 0 до 20 значений (обязательно проверить на длине списка 0, 1. 2, 3, 4, 5, 7, 14)
b.	Выводит содержимое списка в следующем порядке: первый элемент, последний элемент, второй элемент, предпоследний элемент, тритий элемент и т.д.

Например если список содержит:
1 2 3 4 5 6 7 8
то вывод будет иметь вид 
1 8 2 7 3 6 4 5


*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <list>

using namespace std;

void fill_rand(list<int> &l, int n, int range)
{	
	list<int>::iterator it = l.begin();
	for (int i = 0; i<n; i++)
	{
		*it = rand()%range;
		it++;
	}
}

void print_all(list<int> &l)
{
	cout<<"Size is "<<l.size()<<endl;
	cout<<"---------------"<<endl;
	for (list<int>::iterator i = l.begin(); i!= l.end(); i++)
	{
		cout<<*i<<endl;
	}

	cout<<"---------------"<<endl;
	cout<<endl;
}

void sym_print(list<int>::iterator itb, list<int>::iterator ite)
{
	if (itb!=ite)
	{
		cout<<*itb<<endl;
		cout<<*ite<<endl;

		if (++itb!=ite)
		{
			sym_print(itb,--ite);
		}
	}
	else cout<<*itb<<endl;
}

int main()
{
	list<int> l(20);
	fill_rand(l, 0, 20);
	print_all(l); 

	cin.get();

	l.clear();
	l.resize(20);
	fill_rand(l, 1, 20);
	print_all(l);

	cin.get();

	l.clear();
	l.resize(20);
	fill_rand(l, 2, 20);
	print_all(l);

	cin.get();

	l.clear();
	l.resize(20);
	fill_rand(l, 3, 20);
	print_all(l);

	cin.get();

	l.clear();
	l.resize(20);
	fill_rand(l, 4, 20);
	print_all(l);

	cin.get();

	l.clear();
	l.resize(20);
	fill_rand(l, 5, 20);
	print_all(l);

	cin.get();

	l.clear();
	l.resize(20);
	fill_rand(l, 7, 20);
	print_all(l);

	cin.get();

	l.clear();
	l.resize(20);
	fill_rand(l, 14, 20);
	print_all(l);

	l.clear();

	for (int i = 0; i<21; i++)
	{
		l.push_back(i);
	};

	sym_print(l.begin(),--l.end());
	cout<<endl;
	while (!l.empty())
	{
		cout<<l.front()<<endl;;
		l.pop_front();
		if(!l.empty())
		{
			
			cout<<l.back()<<endl;
			l.pop_back();
		}
	}

	return 0;

}