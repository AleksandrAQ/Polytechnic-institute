#include <iostream>


using namespace std;

int sum( int Array[3][5], int Dim1, int Dim2)
{
	int sum=0;
	for (int i = 0; i < Dim1; ++i)
	{
		for (int j = 0; j < Dim2; ++j)
		{
			if (i==j)
			{
				sum+=Array[i][j];
			}
		}
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	int Array[3][5]={
		{2,2,3,4,5},
		{1,2,3,4,5},
		{1,2,2,4,5}
	};
	cout << sum(Array, 3, 5) << "\n";
	return 0;
}