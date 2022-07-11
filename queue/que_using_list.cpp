#include<iostream>
using namespace std;

template<class T>
class node{
public:
T data;
node *next;
};

template<class T>
class queue_list{
public:

node<T> *front,*rear;

queue_list()
{
    front=rear=NULL;
}

void enque(T val)
{
    
    node<T> *temp = new node<T>;
    
    if(front==NULL)
    {
        front=rear=temp;
        temp->data=val;
        temp->next=NULL;
    } 
    else
    {   
        rear->next=temp;
        temp->data=val;
        temp->next=NULL;
        rear=temp;
    }
}

void deque()
{
    if(front==NULL)
    {
        cout<<"QUEUE UNDERFLOW"<<endl;
    }
    else
    {
        node<T> *p;
        p=front;
        front=front->next;
        delete p;
    }
}

void show()
{
    node<T> *n;
    n=front;
    if(front==NULL)
    {
        cout<<"QUEUE UNDERFLOW"<<endl;
    }
    else
    {
    while(n!=NULL)
    {
        cout<<n->data<<"\t";
        n=n->next;
    }
    }
}

};

int main()
{
    queue_list<char> q;
    q.enque('q');
    q.enque('u');
    q.enque('e');
    q.enque('u');
    q.enque('e');
    q.deque();
    q.show();
    return 0;
}