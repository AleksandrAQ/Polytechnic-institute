#include <iostream>
#include <cstdlib>

using namespace std;


int strlen(char* p)
{
   int i = 0;
   while (*p++)
      i++;
   return i;
}

char* strcat2(char *string1, char *string2)
{
	int str_size = strlen(string1)+strlen(string2);
	char *rezult=new char[str_size];
	int point = 0;
	for (int i = 0; i < strlen(string1); ++i)
	{
		rezult[point] = *string1;
		point++;
	}
	for (int i = 0; i < strlen(string2); ++i)
	{
		rezult[point] = *string2;
		point++;
	}
	return rezult;
}



char* strcat(char *string1, char *string2)
{
	int str_size = strlen(string1)+strlen(string2);
	char *rezult=new char[str_size];
	int point = 0;
	for (int i = 0; i < strlen(string1); ++i)
	{
		rezult[point] =i[string1];
		point++;
	}
	for (int i = 0; i < strlen(string2); ++i)
	{
		rezult[point] =string2[i];
		point++;
	}
	return rezult;
}


int main(int argc, char const *argv[])
{
	char *str1 = "string1";
	char  *str2 = "string2";
	cout << strcat(str1,str2)<< "\n";
	return 0;
}