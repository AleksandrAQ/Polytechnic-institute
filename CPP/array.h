//#include <conio.h>
#include <stdio.h>
#include <iostream>
//#include <process.h>
using namespace std;

template<class T> class Array
{
   T * a;                 // указатель на массив элементов
    int ind,size;
        public:
    Array(void);
    Array(int Size);
    Array(const Array &Arr);
    ~Array(void);
    T& operator[](int Index);
    void Add(const T &Value);
    void Erase(int n);
    void Clear(void);
    int Empty(void);
    Array& operator=(const Array<T> &Arr);
    int Size(void);
    void ReSize(int NewSize);
  };
//----------------------------------
template<class T> Array<T>::Array(void)
{
  size=10;
  ind=0;
  a=new T[size];
}
//----------------------------------
template<class T> Array<T>::Array(int Size)
{
  size=Size;
  ind=0;
  if(Size==0)
    a=NULL;
  else
    a=new T[size];
}
//----------------------------------
template<class T> Array<T>::Array(const Array<T> & Arr)
{
  ind=Arr.ind;
  a=new T[size=Arr.size];
  for(int i=0; i<ind; i++)
    a[i] = Arr.a[i];
}
//----------------------------------
template<class T> Array<T>::~Array(void)
{
  delete[] a;
}
//----------------------------------
template<class T> int Array<T>::Size(void)
{
  return ind;
}
//----------------------------------
template<class T> T & Array<T>::operator [] (int n)
{
  if(n>=ind||n<0)
  {
    printf("Bad value of index!");
    exit(0);
  }
  return a[n];
}
//----------------------------------
template<class T> Array<T> & Array<T>::operator = (const Array<T>& Arr)
{
  delete[] a;
  a=new T[size=Arr.size];
  ind=Arr.ind;
  for(int i=0; i<ind; i++)
    a[i]=Arr.a[i];
  return *this;
}
//----------------------------------
template<class T> void Array<T>::ReSize(int NewSize)
{
  T *tmp;
  tmp=new T[NewSize];
  for(int i=0; i<NewSize && i<ind; i++)
    tmp[i]=a[i];
  delete[] a;
  a=tmp;
  size=NewSize;
  if(ind>=NewSize)
    ind=NewSize;
}
//----------------------------------
template<class T> void Array<T>::Add(const T &Value)
{
  if(ind>=size)
    ReSize(size+1);
  a[ind++]=Value;
}
//----------------------------------
template<class T> void Array<T>::Erase(int n)
{
  if(n<0||n>=ind)
    return;
  for(int i=n;i<ind-1;i++)
    a[i]=a[i+1];
  ind--;
}
//----------------------------------
template<class T> void Array<T>::Clear(void)
{
  ind=0;
}
//----------------------------------
template<class T> int Array<T>::Empty(void)
{
  return !ind;
}
//----------------------------------
/*
int main()
{
  Array<int> a1(5), a2(5);
  int i;
  for(i=0;i<5;i++)
    a1.Add(i);
  a1.Add(i++);
  a1.Add(i++);
  for(i=0;i<a1.Size();i++)
    cout<<a1[i];
  a2=a1;
  cout<<endl;
  for(i=0;i<a2.Size();i++)
    cout<<a2[i];
  cout<<endl<<a2.Size()<<endl;
  a2.Erase(2);
  for(i=0;i<a2.Size();i++)
    cout<<a2[i];
}
*/