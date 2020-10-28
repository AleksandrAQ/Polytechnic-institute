/*
Автор - Голышев Роман, 23.09.14

1.	Разработать программу, которая, используя только стандартные алгоритмы и функторы, 
умножает каждый элемент списка чисел с плавающей  точкой на число PI

*/

#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

float random_float()
{
	return rand()/100;
}

// умножение на ПИ
float mult_by_pi(float const &x)
{
	return M_PI*x;
}

void print_float(float const &x)
{
	cout<<x<<endl;
}

int main ()
{
	vector<float> v(10);
	vector<float> v_pi(10);

	generate(v.begin(), v.end(), random_float);
	for_each(v.begin(), v.end(), print_float);
	transform(v.begin(), v.end(), v_pi.begin(), mult_by_pi);
	cout<<"-----------------"<<endl;
	for_each(v_pi.begin(), v_pi.end(), print_float);

	return 0;
}