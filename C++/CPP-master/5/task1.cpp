/*
Автор - Голышев Роман, 23.09.14
Выполнить ВСЕ задания

1.	Написать программа, которая выполняет следующие действия:

a.	Заполняет vector<DataStruct> структурами DataStruct, при этом key1 и key2, генерируются случайным образом в диапазоне от -5 до 5, str заполняется из таблицы (таблица содержит 10 произвольных строк, индекс строки генерируется случайным образом)
b.	Выводит полученный вектор на печать
c.	Сортирует вектор следующим образом:
i.	По возрастанию key1
ii.	Если key1 одинаковые, то по возрастанию key2
iii.	Если key1 и key2 одинаковые, то по возрастанию длинны строки str
d.	Выводит полученный вектор на печать

DataStruct определена следующим образом:
typedef struct
{
    int       key1;
    int       key2;
    string  str;
} DataStruct;

*/

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <time.h>

using namespace std;

typedef struct 
{
	int key1;
	int key2;
	string str;
} DataStruct;

bool less_then(DataStruct a, DataStruct b)
{
	 if (a.key1<b.key1)
	 	return true;
	 if ((a.key2<b.key2)&&(a.key1 == b.key1))
	 	return true;
	 if ((a.str.length()<b.str.length())&&(a.key2==b.key2)&&(a.key1 == b.key1))
	 	return true;
	 return false;
};

DataStruct new_Datastruct(vector<string> table)
{
	DataStruct temp;
	temp.key1 = rand()%11 - 5;
	temp.key2 = rand()%11 - 5;
	temp.str = table[rand()%table.size()];
	return temp;
};

void reading(ifstream& f, vector<string> &table)
{
	string ss;

	while(getline(f,ss))
	{
		table.push_back(ss);
	}
};

void print_elem(DataStruct &d)
{
	cout<<d.key1<<" "<<d.key2<<" "<<" "<<d.str<<endl; 
};

void sort(vector<DataStruct> &v)
{
	for (int i = 0; i<v.size(); i++)
	{
		for (int j=i+1; j<v.size(); j++)
		{
			if (less_then(v[i],v[j])){
				DataStruct temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
	}
};

void printall(vector<DataStruct> v)
{
	for (vector<DataStruct>::iterator it = v.begin(); it!=v.end(); it++)
	{
		print_elem(*it);
	}
};

int main ()
{
	srand(time(0));
	int n = 20;

	vector<string> table;
	vector<DataStruct> v;
	ifstream f; 
	f.open("text.txt");

	reading(f,table);

	for (int i = 0; i<n; i++)
	{
		v.push_back(new_Datastruct(table)); 
	};

	cout<<"Unsorted"<<endl<<"----------------------"<<endl;
	printall(v);
	sort(v);

	cout<<endl<<"Sorted"<<endl<<"----------------------"<<endl;
	printall(v);
	return 0;
}