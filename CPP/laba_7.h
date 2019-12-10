#include <string>
#include <iostream>
#include "array.h"
using namespace std;


class Product
{
public:
	//Array<MString> AddInf;
	Product()
	{
		charact.Add("std charct");
		name = "standrt";
		model = "standart";
		company = "standart";
		cost = 0;
		count = 0;
	}
	Product(const Product &p):
		name(p.name), model(p.model), company(p.company), cost(p.cost), count(p.count)
		{
			cout << "Copyed"<<endl;

		}
	~Product()
	{
		/*delete name;
		delete model;
		delete company;
		delete cost;
		delete count;
		delete[] charact;*/
		cout << "mem cleared" << endl;
	}
	Product& operator=(const Product &p)
	{
		cost = p.cost;
		return *this;
	}
	void set_name(string product_name)
	{
		name = product_name;
	}
	void set_model(string product_model)
	{
		model = product_model;
	}
	void set_company(string product_company)
	{
		company = product_company;
	}
	void set_cost(int product_cost)
	{
		cost = product_cost;
	}
	void set_count(int product_count)
	{
		count = product_count;
	}
	Array<string> charact;
	string name;
	string model;
	string company;
	int cost;
	int count;	
private:
	
};

ostream& operator<< (ostream &out, const Product &p)
{
	out << p.name<<","<<p.model<<","<<p.company<<","<<p.cost<<","<<p.count;
	return out;
}

