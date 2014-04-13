/*************************************************************************
> File Name: include/queue.h
> Author: ma6174
> Mail: ma6174@163.com 
> Created Time: Fri 11 Apr 2014 08:24:15 PM CST
************************************************************************/
#ifndef queue_h
#define queue_h
#include<iostream>
#include <stdio.h>
using namespace std;

template<typename T>
class Queue
{
public:
    Queue(int capacity=10);
    ~Queue();
    bool IsEmpty() const;
    T& Front() const;
    T& Rear() const;
    void Push(const T& item);
    void Pop();
private:
    T* queue;
    int front,
    rear,
    capacity,
    number;

};
#endif
