/*
Автор - Голышев Роман, 23.09.14

2.	Разработать программу, которая:
a.	Реализует иерархию геометрических фигур состоящую из:
i.	Класс Shape.
1.	Содержит информацию о положении центра фигуры (координаты x и y).
2.	Содердит метод IsMoreLeft, позволяющий определить расположена ли данная фигура левее (определяется по положению центра) чем фигура переданная в качестве аргумента
3.	Содердит метод IsUpper, позволяющий определить расположена ли данная фигура выше (определяется по положению центра) чем фигура переданная в качестве аргумента
4.	Определяет чисто виртаульную функцию рисования Draw (каждая фигура в реализации этой функци должна выводить на стандартный вывод свое название и положение цента)
ii.	Класс Circle производный от класса Shape
1.	Реализует Draw
iii.	Класс Triangle производный от класса Shape
1.	Реализует Draw
iv.	Класс Square производный от класса Shape
1.	Реализует Draw
b.	Содержит список list<Shape*>, заполенный указателями на различные фигуры
c.	С помощью стандартных алгоритмов и адаптеров выводит (Draw) все фигуры
d.	С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра слева-направо (имется в виду, что в начале списка должны идти фигуры находящиеся левее, координата x ) и выводит фигуры (Draw)
e.	С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра справа-налево и выводит фигуры
f.	С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра сверху-вниз и выводит фигуры
g.	С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра снизу-вверх и выводит фигуры

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

struct Point
{
	int x_,y_;
	Point():x_(0), y_(0) {};
	Point(int x, int y): x_(x), y_(y){};

	~Point(){};

	int getX(){return x_;}
	int getY(){return y_;}
};

class Shape{

public:
	Shape(){center.x_ = 0; center.y_ = 0;};
	Shape(int x, int y){center.x_ = x; center.y_ = y;};
	~Shape(){};

	// используем ссылки, чтобы сравнение проходило корректно.
	bool IsMoreLeft(Shape *s) {
		return (center.getX()<s->center.x_);
	}

	bool IsUpper(Shape * s){
		return (this->center.getY()>s->center.y_);
	}

	virtual void Draw(){//пока оставим пустым, мб не понадобиться
		//cout<<center.getX()<<" "<<center.getY();
	};

	Point center;
};

class Circle: public Shape{

public:
	Circle(){center.x_ = 0; center.y_ = 0;};
	Circle(int x, int y){center.x_ =  x; center.y_ = y;};;
	~Circle(){};
	virtual void Draw(){
		cout<<"Circle "<<center.getX()<<" "<<center.getY()<<endl;
	}
};

class Square: public Shape{

public:
	Square(){center.x_ = 0; center.y_ = 0;};
	Square(int x, int y){center.x_ = x; center.y_ = y;};;
	~Square(){};
	virtual void Draw(){
		cout<<"Sqare "<<center.getX()<<" "<<center.getY()<<endl;
	}

};

class Triangle: public Shape{

public:
	Triangle(){center.x_ = 0; center.y_ = 0;};
	Triangle(int x, int y){center.x_ = x; center.y_ = y;};;
	~Triangle(){};
	virtual void Draw(){
		cout<<"Triangle "<<center.getX()<<" "<<center.getY()<<endl;
	}
};


int main()
{
	list <Shape*> l;
	l.push_back(new Square(10,10));
	l.push_back(new Triangle(10,15));
	l.push_back(new Square(16,15));
	l.push_back(new Circle(10,15));
	l.push_back(new Square(58,60));
	for_each(l.begin(), l.end(), mem_fun(&Shape::Draw));
	cout<<"------------------------------"<<endl;
	
	l.sort(mem_fun(&Shape::IsMoreLeft));
	for_each(l.begin(), l.end(), mem_fun(&Shape::Draw));
	cout<<"------------------------------"<<endl;

	l.sort(not2(mem_fun(&Shape::IsMoreLeft)));
	for_each(l.begin(), l.end(), mem_fun(&Shape::Draw));
	cout<<"------------------------------"<<endl;

	l.sort(not2(mem_fun(&Shape::IsUpper)));
	for_each(l.begin(), l.end(), mem_fun(&Shape::Draw));
	cout<<"------------------------------"<<endl;

	l.sort(mem_fun(&Shape::IsUpper));
	for_each(l.begin(), l.end(), mem_fun(&Shape::Draw));
	cout<<"------------------------------"<<endl;

	return 0;
}
