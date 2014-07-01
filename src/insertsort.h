/*************************************************************************
	> File Name: src/insertsort.h
	> Author: 吴乃亮
	> Mail: wunailiang@gmail.com 
	> Created Time: Sat 28 Jun 2014 07:53:20 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
template <typename T>
void Insert(const T& e,T* a,int i)
{
    a[0]=e;
    while(e<a[i])
    {
        a[i+1]= a[i];
        i--;
    }
    a[i+1]=e;
}

template <typename T>
void InsertSort(T* a,const int n)
{
    for (int j=2;j<=n;j++)
    {
        T temp = a[j];
        Insert(temp,a,j-1);
    }
}
