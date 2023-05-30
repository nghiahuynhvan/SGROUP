#include<iostream>
#include<fstream>
using namespace std;
template<class T>
struct node
{
    T data;
    struct node *pNext;
};
// template<class T>
// typedef struct node<T> NODE;
template<class T>
class List
{
    private:
        struct node<T> *pHead;
        struct node<T> *pTail;
    public:
        List();
        ~List();
        bool isEmpty();
        int Length();
        struct node<T>* getNode(T&);
        void addHead(struct node<T>*);
        void addTail(struct node<T>*);
        void addPosition(struct node<T>*, int);
        void deleteHead();
        void deleteTail();
        void deletePosition(int);
        void Update(int,T&);
        void ShowLIST();
        //void ListOutfile(ofstream&);
        void BSort();
        void GetData(int,T&);
        int Search(T&);
        friend class Menu;
        friend class Order;
        friend class Order_Manager;
};

template<class T>
List<T>::List()
{
    this->pHead = NULL;
    this->pTail = NULL;
}
template<class T>
List<T>::~List()
{
    struct node<T> *p;
    while (this->pHead != NULL)
    {
        p = this->pHead;
        this->pHead = this->pHead->pNext;
        delete p;
    }
}
template<class T>
bool List<T>::isEmpty()
{
    if(this->pHead == NULL && this->pTail == NULL)
        return true;
    else 
        return false;
}
template<class T>
int List<T>::Length()
{
    int count = 0;
    for(struct node<T> *k = this->pHead ; k != NULL ; k = k->pNext)
        count++;
    return count;
}
template<class T>
struct node<T>* List<T>::getNode(T& t)
{
    struct node<T> *p = new struct node<T>;
    if(p == NULL)
    {
        cout<<"Khong du bo nho de cap phat";
        return NULL;
    }
    p->data = t;
    p->pNext = NULL;
    return p;
}
template<class T>
void List<T>::addHead(struct node<T> *p)
{
    if(p == NULL)
    {
        return;
    }
    if(this->pHead == NULL)
    {
        this->pHead = this->pTail = p;
    }
    else
    {
        p->pNext = this->pHead;
        this->pHead = p;
    }
}
template<class T>
void List<T>::addTail(struct node<T> *p)
{
    if(this->pHead == NULL)
    {
        this->pHead = this->pTail = p;
    }
    else
    {
        this->pTail->pNext = p;
        this->pTail = p;
    }
}
template<class T>
void List<T>::addPosition(struct node<T> *p, int index)
{
    int count = 0;
    for(struct node<T> *k = this->pHead ; k != NULL ; k = k->pNext)
        count++;
    if(this->pHead == NULL || index == 1)
    {
        this->addHead(p);
    }
    else if(index == count + 1) 
    {
        this->addTail(p);
    }
    else
    {
        int count2 = 0;
        struct node<T> *g = new struct node<T>;
        for(struct node<T> *k = this->pHead ; k != NULL ; k = k->pNext)
        {
            count2++;
            if(count2 == index)
            {
                struct node<T> *h = this->getNode(p->data);
                h->pNext = k;
                g->pNext = h;
            }
            g = k;
        }
    }
}
template<class T>
void List<T>::deleteHead()
{
    if(this->pHead == NULL)
    {
        return;
    }
    struct node<T>* p = this->pHead;
    this->pHead = this->pHead->pNext;
    delete p;
}
template<class T>
void List<T>::deleteTail()
{
    if(this->pHead == NULL)
    {
        return;
    }
    if(this->pHead->pNext == NULL)
    {
        this->deleteHead();
        return;
    }
    for(struct node<T> *k = this->pHead ; k != NULL ; k = k->pNext)
    {
        if(k->pNext == this->pTail)
        {
            delete this->pTail;
            k->pNext = NULL;
            this->pTail = k;
            return;
        }
    }
}
template<class T>
void List<T>::deletePosition(int index)
{
    int count = 0;
    for(struct node<T> *k = this->pHead; k != NULL ; k = k->pNext)
        count++;
    if(index == 1)
    {
        this->deleteHead();
    }
    else if(this->pHead == NULL)
    {
        cout<<"Khong co gi de xoa"<<endl;
    } else if(index == count)
    {
        this->deleteTail();
    }
    else
    {
        int count2 = 0;
        struct node<T> *g = new struct node<T>;
        for(struct node<T> *k = this->pHead ; k != NULL ; k = k->pNext)
        {
            count2++;
            if(count2 == index)
            {
                g->pNext = k->pNext;
                delete k;
            }
            g = k;
        }
    }
}
template<class T>
void List<T>::Update(int index, T& t)
{
    int count = 0;
    for(struct node<T> *k = this->pHead ; k != NULL ; k = k->pNext)
    {
        count++;
        if(count == index)
        {
            k->data = t;
        }
    }
}
template<class T>
void List<T>::ShowLIST()
{
    for(struct node<T> *k = this->pHead ; k != NULL ; k = k->pNext)
    {
        cout<<k->data;
    }
}
template<class T>
void List<T>::BSort()
{
    for(struct node<T> *k = this->pHead ; k->pNext != NULL ; k = k->pNext)
    {
        for(struct node<T> *l = k->pNext; l != NULL ; l = l->pNext)
            if(k->data > l->data)
            {
                T x;
                x = k->data;
                k->data = l->data;
                l->data = x;
            }
    }
}
template<class T>
void List<T>::GetData(int index,T& t)
{
    int count = 1;
    for(struct node<T> *k = this->pHead ; k != NULL ; k = k->pNext)
    {
        if(index == count)
        {
            t = k->data;
        }
        count++;
    }

}
template<class T>
int List<T>::Search(T& t)
{
    int count = 1;
    for(struct node<T> *k = this->pHead ; k != NULL ; k = k->pNext)
    {
        if(k->data == t)
        {
            return count;
        }
        count++;
    }
    return count;
}