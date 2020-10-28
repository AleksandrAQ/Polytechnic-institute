/*
Autor - Golishev Roman, 22.09.2014

ЗАдание: 4)	Прочитайте во встроенный массив С 
содержимое текстового файлы, скопируйте данные в 
вектор одной строкой кода (без циклов и алгоритмов STL)
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;



int main()
{
	ifstream  f;
	f.open("text.txt");

	char m[20];
	f>>m;

	cout<<m<<endl;

	vector<char> v(m, m + strlen(m));
 
	cout<<&v[0]<<endl;

	f.close();
	return 1;
}