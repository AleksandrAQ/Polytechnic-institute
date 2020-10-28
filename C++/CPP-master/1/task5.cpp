/*
Autor - Golishev Roman, 22.09.2014

ЗАдание: 5)	Напишите программу, сохраняющую в векторе числа, полученные из
 стандартного ввода (окончанием ввода является число 0). Удалите все элементы,
  которые делятся на 2 (не используете стандартные алгоритмы STL), если последнее
   число 1. Если последнее число 2, 
добавьте после каждого числа которое делится на 3 три единицы.
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;

	int t;

	cin>>t;
	while (t!=0)
	{
		v.push_back(t);
		cin>>t;
	}

	if (v[v.size()-1] == 1)
	{
		vector<int> vv;
		for (auto i = v.begin(); i!=v.end(); i++)
		{
			if ((*i % 2)==1)
			{
				vv.push_back(*i);
			}
		}
		v = vv;
	}
	else
		if (v[v.size()-1] == 2)
		{
			vector<int> vv;
				for (auto i = v.begin(); i!=v.end(); i++)
			{
				if ((*i % 3)==0)
				{
					vv.push_back(*i);
					vv.push_back(1);
					vv.push_back(1);
					vv.push_back(1);
					vv.insert(--vv.end(),3,1);
				}
				else
				{
					vv.push_back(*i);
				}
			}
			v = vv;
	};


	for (auto i:v)
	{
		cout<<i<<" ";
	};

	return 0;
}
