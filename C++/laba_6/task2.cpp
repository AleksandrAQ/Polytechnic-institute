/*
Autor - Golishev Roman, 22.09.2014
2.	Написать программу, которая выполняет следующие действия (все операции должны выполняться с помощью стандартных алгоритмов):
a.	Заполняет вектор геометрическими фигурами. Геометрическая фигура может быть треугольником, квадратом, прямоугольником или пяти угольником. Структура описывающая геометрическую фигуру  определена ниже, 
b.	Подсчитывает общее количество вершин всех фигур содержащихся в векторе (так треугольник добавляет к общему числу 3, квадрат 4 и т.д.)
c.	Подсчитывает количество треугольников, квадратов и прямоугольников в векторе
d.	Удаляет все пятиугольники 
e.	На основании этого вектора создает vector<Point>, который содержит координаты одной из вершин (любой) каждой фигуры, т.е. первый элемент этого вектора содержит координаты одной из вершину первой фигуры, второй элемент этого вектора содержит координаты одной из вершину второй фигуры и т.д.
f.	Изменяет вектор так, чтобы он содержал в начале все треугольники, потом все квадраты, а потом прямоугольники.
g.	Распечатывает вектор после каждого этапа работы
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

// точка
typedef struct 
{
	int x,y;
}Point;

typedef  struct 
{
    int vertex_num;      
    vector<Point> vertexes;   
} Shape;

// создание точки со случайными координатами
Point rand_point()
{
	Point p;
	p.x = rand()%100;
	p.y = rand()%100;
	return p;
}

// создание фигуры со случайным количеством углов
Shape rand_shape()
{
	Shape s;
	s.vertex_num = 1 + rand()%5; //опеределение кол-ва углов
	s.vertexes.clear();

	// заполнение вектора случайными точками
	for (int i = 0; i<s.vertex_num; i++)
	{
		s.vertexes.push_back(rand_point());
	};
	return s;
}

//распечатка точки
void print_point(Point const &p)
{
	cout<<" ("<<p.x<<", " <<p.y<<") ";
}

//распечатка параметров фигуры
void print_shape(Shape const &s)
{
	cout<<s.vertex_num<<".  ";
	for_each(s.vertexes.begin(),s.vertexes.end(),print_point);
	cout<<endl;
}

// функция, возвращающая кол-во углов
int vertex_num(Shape const &s){return s.vertex_num;}
bool vert_num_is_5(Shape &s){return (s.vertex_num==5);}
bool vert_num_is_4(Shape &s){return (s.vertex_num==4);}
bool vert_num_is_3(Shape &s){return (s.vertex_num==3);}
bool vert_num_is_2(Shape &s){return (s.vertex_num==2);}
bool vert_num_is_1(Shape &s){return (s.vertex_num==1);}
// функция для сравнения по кол-ву вершин
bool shape_vertex_comp(Shape const &l, Shape const &r){return (l.vertex_num<r.vertex_num);}

// получение случайной точки фигуры
Point get_rand_point(Shape const &s)
{
	return(s.vertexes[rand()%(s.vertex_num)]);
}


int tot_sum = 0;
void get_summ(Shape const &s)
{
	tot_sum += s.vertex_num;
}

int main()
{

	print_shape(rand_shape());
	vector<Shape> v;
	vector<Point> pv;
	vector<int>   numbs(5, 0);

	// заплонение вектора и распечатка
	cout<<"Initial figures"<<endl;
	while (v.size()<5)
		v.push_back(rand_shape()); 
	for_each(v.begin(),v.end(),print_shape);
	cout<<"|------------------|"<<endl<<endl;


	// подсчет элементов и углов
	cout<<"Number of elements"<<endl;
	cout<<"5.  "<<count_if(v.begin(),v.end(), vert_num_is_5)<<endl;
	cout<<"4.  "<<count_if(v.begin(),v.end(), vert_num_is_4)<<endl;
	cout<<"3.  "<<count_if(v.begin(),v.end(), vert_num_is_3)<<endl;
	cout<<"2.  "<<count_if(v.begin(),v.end(), vert_num_is_2)<<endl;
	cout<<"1.  "<<count_if(v.begin(),v.end(), vert_num_is_1)<<endl;
	cout<<"|------------------|"<<endl<<endl;

	// подсчёт вершин
	cout<<"Number of elements"<<endl;
	for_each(v.begin(), v.end(), get_summ);
	cout<<tot_sum<<endl<<endl;

	// сортировка по количеству вершин
	cout<<"Sorted figures"<<endl;
	sort(v.begin(),v.end(),shape_vertex_comp);
	for_each(v.begin(),v.end(),print_shape);
	cout<<"|------------------|"<<endl<<endl;

	// выбор случайных точек 
	cout<<"Random points from figures"<<endl;
	pv.resize(v.size());
	transform(v.begin(), v.end(), pv.begin(), get_rand_point);
	for_each(pv.begin(), pv.end(), print_point);
	cout<<endl;
	cout<<"|------------------|"<<endl<<endl;

	//for(auto it = v.begin(); it!=v.end();)
	//v.erase(v.begin(), v.end(), vert_num_is_5);
	v.erase(remove_if(v.begin(), v.end(), vert_num_is_5), v.end());


	for_each(v.begin(),v.end(),print_shape);

	return 0;
}