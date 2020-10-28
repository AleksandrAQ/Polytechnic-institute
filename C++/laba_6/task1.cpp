/*
Автор - Голышев Роман, 23.09.14
Выполнить ВСЕ задания

1.	Написать программу, которая выполняет следующие действия:
a.	Читает содержимое текстового файла
b.	Выделяет слова, словом считаются последовательность символов разделенных пробелами и/или знаками табуляции и/или символами новой строки
c.	Вывести список слов присутствующий в тексте без повторений (имеется в виду, что одно и то же слово может присутствовать в списке только один раз)

*/
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//процедура для чтения строк из текстового файла в вектор
string reading(ifstream& f)
{
	string sr = "";
	string ss = "";

	while(getline(f,ss))
	{
		sr = sr + ss+'\n';
	}
	return sr;
}

// разбиение строки на слова
vector<string> str_to_words(string s, string liters)
{
	vector<string> v;

	int last_pos = 0; //последняя позиция поиска
	int first_liter 	= s.find_first_of(liters, last_pos); //первая буква слова
	int first_not_liter = s.find_first_not_of(liters, first_liter); //позиция, перед которой последняя буква слова
	int len 			= first_not_liter - first_liter; //длина слова

	while ((first_not_liter!=string::npos) && (first_liter!=string::npos))
	{
		v.push_back(s.substr(first_liter,len)); //вставка слова в конец вектора

		//обновление счётчиков
		last_pos = first_not_liter;
		first_liter 	= s.find_first_of(liters, last_pos); 
		first_not_liter = s.find_first_not_of(liters, first_liter); 
		len 			= first_not_liter - first_liter;
	};

	// на случай, если осталось ещё одно слово без знаков препинания
	if(first_liter!=string::npos)
		v.push_back(s.substr(first_liter, s.length() - first_liter));

	return v;
}

// удаление заглавных букв из строки
string without_uppercase(string const &s)
{
	string ss = s;

	for (auto it = ss.begin(); it!=ss.end(); it++)
	{
		if (isupper(*it)) // Если заглавная буква
			*it = tolower(*it); // То заменить на строчную
	}

	return ss;
}

// вывод содержимого вектора
template <typename T>
void print_vector(vector<T> v)
{
	for (auto it = v.begin(); it!=v.end(); it++)
		cout<<*it<<endl;
}

const string liters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

int main()
{
	ifstream f;
	f.open("task1.cpp");
	vector<string> v = str_to_words(reading(f),liters);
	print_vector(v);
	cout<<endl<<"-------------------------"<<endl;
	cin.get();

	// удаление одинаковых элементов из вектора
	sort(v.begin(),v.end());
	for (auto it = adjacent_find(v.begin(),v.end()); it!=v.end(); v.erase(it), it = adjacent_find(v.begin(),v.end()));
	//v.erase(unique(v.begin(),v.end()), v.end());
	//v=unique(v.begin(),v.end());

	cout<<endl<<"-------------------------"<<endl;
	//cout<<(v[1]==v[5]);
	print_vector(v);
	return 0;
}