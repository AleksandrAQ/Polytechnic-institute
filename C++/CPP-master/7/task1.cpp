/*
Автор - Голышев Роман, 23.09.14

1.	Разработать функтор,  позволяющий собирать статистику о последовательности 
целых чисел (послед может содержать числа от -500 до 500).
Функтор после обработки последовательности алгоритмом for_each должен предоставлять следующую статистику:
a.	Максимальное число в последовательности
b.	Минимальное число в последовательности
c.	Среднее чисел в последовательности
d.	Количество положительных чисел
e.	Количество отрицательных чисел
f.	Сумму нечетных элементов последовательности
g.	Сумму четных элементов последовательности
h.	Совпадают ли первый и последний элементы последовательности.


*/

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class functor{
public:
	int n;//количество
	int max,min;
	float average; // среднее
	int less_then_zero, more_then_zero;
	int even, odd;
	int first,last;


public:
	//functor():n(0), max(0), min(10), average(0), less_then_zero(0), more_then_zero(0), even(0), odd(0), first(0), last(0){};
	functor(){
		n = 0;
		max = 0;
		min = 10;
		average = 0; 
		less_then_zero = 0; 
		more_then_zero = 0; 
		even = 0;
		odd = 0;
		first = 0; 
		last = 0;
	};
	~functor(){};

	void operator()(int const &x){
		if (n==0)
			first=x;
		n++;

		last = x;

		if (x>max)
			max = x;
		if (x<min)
			min = x;

		average = ((average*(n-1))+x)/n;

		if (x<0)
			less_then_zero++;
		if (x>0)
			more_then_zero++;

		if (x % 2 == 1)
			odd++;
		else if (x)
				even++;
	}

	void print_data()
	{
		cout<<"max is "<<max<<endl;
		cout<<"min is "<<min<<endl;
		cout<<"average is "<<average<<endl;
		cout<<"less_then_zero is "<<less_then_zero<<endl;
		cout<<"more_then_zero is "<<more_then_zero<<endl;
		cout<<"even is "<<even<<endl;
		cout<<"odd is "<<odd<<endl;
		cout<<"first is "<<first<<endl;
		cout<<"last is "<<last<<endl;
	}
};

void print_int(int const &x)
{
	cout<<x<<endl;	
}

int main()
{
	functor f;
	std::vector<int> v;
	for (;v.size()<200;)
		v.push_back((rand()%1000) - 500);
	for_each(v.begin(),v.end(),print_int);
	f = for_each(v.begin(), v.end(), f);
	f.print_data();

	return 0;
}