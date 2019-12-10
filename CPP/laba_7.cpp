#include <iostream>
#include "laba_7.h"
using namespace std;


int main(int argc, char const *argv[])
{
	Product p;
	Product p2;
	p2.set_cost(5);
	p.set_name("milk");

	cout<<p.name<<endl;
	cout<<p.cost<<endl;
	cout<<p2.cost<<endl;
	
	p=p2;
	cout<<p.cost<<endl;
	
	cout<<p<<endl;

	Product p3(p);

	for(int i=0;i<p.charact.Size();i++)
    	cout<<p.charact[i]<<endl;

    cout << p.charact.Size();
	return 0;
}