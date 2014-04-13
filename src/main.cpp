/*************************************************************************
	> File Name: src/main.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Fri 11 Apr 2014 08:23:59 PM CST
 ************************************************************************/

#include<iostream>
#include "queue.h"
#include "queue.cpp"
using namespace std;
//这是循环队列，
int main()
{
    Queue<int> queue(1);
    queue.Push(108);
    queue.Push(11);
    queue.Push(14);
    cout << queue.Front()<<endl;
    cout << "hello queue" <<endl;
    return 0;
}
