/*************************************************************************
	> File Name: src/queue.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Fri 11 Apr 2014 08:23:13 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include "queue.h"
using namespace std;

template<typename T>
Queue<T>::Queue(int queuecapacity):capacity(queuecapacity),
    number(0)
{
    if(capacity<1) throw "capacity must >1";
    queue=new T[capacity];
    front=rear=0;
}

template<typename T>
Queue<T>::~Queue()
{
    delete []queue;
    /*delete p1 在回收空间的过程中，只有 p1[0] 这个对象调用了析构函数，其它对象如p1[1]、p1[2] 等都没有调用自身的析构函数，这就是问题的症结所在。如果用 delete[]，则在回收空间之前所有对象都会首先调用自己的析构函数。
*/
}

template<typename T>
inline bool Queue<T>::IsEmpty() const 
{
    return front==rear;
}
 
template<typename T>
inline T& Queue<T>::Front() const
{
    if(IsEmpty()) throw "queue is empty";
    return queue[(front+1)%capacity];
}

template<typename T>
inline T& Queue<T>::Rear() const
{
    if(IsEmpty()) throw "queue is empty";
    return queue[rear];
}

template<typename T>
void Queue<T>::Push(const T& x)
{
    if((rear+1)%capacity == front)
    {
        cout << "double the capacity" <<endl;
        T* newqueue=new T[2*capacity];
        int start = (front+1)%capacity;
        if(start<2)
            copy(queue+start,queue+start+capacity-1,newqueue);
        else
        {
            copy(queue+start,queue+capacity,newqueue);
            copy(queue,queue+rear+1,newqueue+capacity-start);
        }
        front=2*capacity-1;
        rear=capacity-2;
        capacity*=2;
        delete [] queue;
        queue = newqueue;
    }
    rear = (rear+1)%capacity;
    queue[rear]=x;
}
    
    
