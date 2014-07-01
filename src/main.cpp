/*************************************************************************
	> File Name: src/main.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Fri 11 Apr 2014 08:23:59 PM CST
 ************************************************************************/

#include<iostream>
#include "queue.h"
#include "queue.cpp"

#include "chain.h"
#include "insertsort.h"
using namespace std;
int main()
{
    /***测试队列
    Queue<int> queue(1);
    queue.Push(108);
    queue.Push(11);
    queue.Push(14);
    cout << queue.Front()<<endl;
    cout << "hello queue\n\n\n\n" <<endl;
    */
    /****测试利用数组的插入排序
    int* a;
    a[0]=1;
    a[1]=12;
    a[2]=7;
    a[3]=2;
    for(int i=1;i<=3;i++)
        cout <<a[i]<<endl;
    InsertSort<int>(a,3);
    for(int i=1;i<=3;i++)
        cout <<a[i]<<endl;
    */

    /*****单向链表的测试*****/
    Chain<int> initchain;
    initchain.push_back(1);
    initchain.push_back(20);
    initchain.push_back(5);
    initchain.push_back(399);
    initchain.push_back(39);
    initchain.push_back(31);
    initchain.insert(11,2);
    initchain.erase(2);
    initchain.insert(99,0);

    //for(ChainNode<int>* ptr=initchain.begin();ptr!=0;ptr=ptr->link)//这是最朴素的模式，好点的方式是设计一个迭代器
    //{
        //cout << ptr->data<<endl;
    //}
    //测试get函数 
    cout <<"test get fun\tget(int)=" <<initchain.get(3)->data<<endl;
    cout <<"end="<<(*initchain.end())<<endl;
    for(Chain<int>::ChainIterator it = initchain.begin();it != 0;it++)
    {
        cout <<(*it)<<endl;
    }

    cout <<"before test overload <<\n";
    cout <<initchain<<endl;

    cout <<"before sort\n";
    initchain.InsertSort();
    cout << initchain<<endl;

    return 0;
}
