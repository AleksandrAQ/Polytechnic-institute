#include <iostream>
#include <cstdlib>
using namespace std;

int MoveLeftWithAdd (unsigned x, unsigned y, int n)
{
	int l = sizeof(int)*8;
	return x<<n|y>>(l-n);
}

int main(int argc, char const *argv[])
{
	cout<<hex<<MoveLeftWithAdd(0x1234,0x5678 , 8);
	return 0;
}