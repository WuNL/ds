/*************************************************************************
	> File Name: src/chain.h
	> Author: 吴乃亮
	> Mail: wunailiang@gmail.com 
	> Created Time: Sat 28 Jun 2014 08:43:15 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

template<typename T>
class Chain;//forward decalaration
template<typename T>
class ChainNode
{
public:
    ChainNode(T element = 0,ChainNode* next =0):data(element),link(next)
    {

    }
    friend class Chain<T>;
    T data;
    ChainNode<T>* link;
};

//全是用内联写的，正常不应这样吧？
template<typename T>
class Chain
{
public:
    class ChainIterator;
    Chain():size(0)
    {
        cout <<"into constructor\n"<<endl;

        first = new ChainNode<T>;
        last = 0;
    };

    ~Chain()
    {

        cout <<"into deconstructor\n"<<endl;
        if(size)
            return;
        while(first->link)
        {
            ChainNode<T>* temp=first->link;
            delete first->link;
            first->link = temp->link;
        }
        delete first;
    };

    ChainIterator begin()
    {
        return ChainIterator(first->link);
    }

    ChainIterator end()
    {
        return ChainIterator(last);
    }

    bool push_back(const T& e)
    {
        cout <<"into push_back\n"<<endl;
        if(size)
        {
            last->link = new ChainNode<T> (e);
            last = last->link;
        }
        else
            first->link = last =new ChainNode<T> (e);
        size++;
        cout <<"size="<<size<<endl;
    }

    ChainNode<T>* get(int i)
    {
        if((i)>size || (i)<0)
        {
            cout <<"mem error\n"<<endl;
            exit(1);
        }    
        int index=i;
        ChainNode<T>* temp=first;
        
        for(int j = 1;j<=index;j++)
        {
            temp = temp->link;
        }
        return temp;
    }

    //序号是从1开始的
    bool insert(const T& e,int i)//在第i个节点之后插入
    {
        if((i)>size || (i)<0)
        {
            cout <<"mem error\n"<<endl;
            exit(1);
        }    
        ChainNode<T>* temp = new ChainNode<T>(e);
        temp->link = get(i)->link;
        get(i)->link = temp;


        size++;
        return true;
    }

    bool erase(int i)
    {
        if((i)>size || (i)<=0)
        {
            cout <<"mem error\n"<<endl;
            exit(1);
        }    
        ChainNode<T>* temp = get(i-1)->link;
        get(i-1)->link = get(i-1)->link->link;
        delete temp;
        size--;
        return true;
    }

    int _size()
    {
        return size;
    }
private:
    ChainNode<T> *first;//first用作哨兵
    ChainNode<T> *last;
    int size;
public:
 class ChainIterator
{
public:
    ChainIterator(ChainNode<T>* startnode = 0):current(startnode)
    {

    }
    T& operator * () const
    {
        return current->data;
    }
    T* operator -> () const {return &current->data;}

    bool operator != (const ChainIterator right) const
    {
        return current != right.current;
    }
    bool operator == (const ChainIterator right) const
    {
        return current == right.current;
    }
    ChainIterator operator ++(int)
    {
        ChainIterator old=*this;
        current = current->link;
        return old;
    }
private:
    ChainNode<T>* current;
};   
    //操作符重载在类内部请使用友元。并且注意不要使用endl，\n之类的东西
    friend std::ostream& operator << (std::ostream &os,Chain<T> &c)
    {
        for(Chain<T>::ChainIterator it=c.begin();it!=0;it++)
        {
            os<< (*it)<<"\t";
        }
        return os;
    }

/*****利用链表插入排序*******/
    bool InsertSort()
{
    //0，1个节点的链表就没必要排序了
    if(size<2)
    {
        cout << "No need to sort \n";
        return 0;
    }

    ChainNode<T>* last_n = first->link;//最后一个有序节点
    ChainNode<T>* first_n = first->link;//地一个有数的节点
    ChainNode<T>* current_n;//当年正排序的节点，即last_n后一个
    ChainNode<T>* n1;
    ChainNode<T>* n2;
    while(last_n->link!=0)
    {
        current_n = last_n->link;
        //小于首节点的情况，交换当前排序节点和首节点
        if(current_n->data < first_n->data)
        {
            last_n->link = current_n->link;
            current_n->link = first_n;
            first_n = current_n;
            first->link = first_n;
        }
        //
        else
        {
            n1 = first_n;
            n2 = first_n->link;
            while(n2->data < current_n->data )
            {
                n1 = n2;
                n2= n2->link;
            }
            //当前排序节点处于有序序列中间的情况
            if(n1 != last_n)
            {
                last_n->link = current_n->link;
                current_n->link = n2;
                n1->link = current_n;
            }
            //扔最后边的情况
            else
            {
                last_n = last_n->link;
            }
        }
    }

}


};

