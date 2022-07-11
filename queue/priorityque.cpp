#include<iostream>
using namespace std;

template<class T>
class node{
public:
T data;
int pr;
node *next;
};

template<class T>
class priorityq{
public:

node<T> *front,*rear;

priorityq()
{
  front=rear=NULL;
}

void enq(T val,int p)
{
  node<T> *temp = new node<T>;
  node<T> *t;
  t=front;
  temp->data=val;
  temp->pr=p;
  if(front==NULL)
  {
     front=rear=temp;
     temp->next=NULL;
  }
  else if(temp->pr < t->pr)
  {
      temp->next = front;
      front=temp;
  }
  else
  {
    t=front;
    if(rear->pr < p)
    {
        rear->next=temp;
        temp->next=NULL;
        rear=temp;
    }
    else
    {
    while(t->next->pr <= p)
    {
        t=t->next;
    }
    temp->next=t->next;
    t->next=temp;
  }
  }
}

void deq()
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
   node<T> *s;
   s=front;
   while(s!=NULL)
   {
       cout<<s->data<<"\t";
       s=s->next;
   }
}

};

int main()
{
    priorityq<char> pq;
    pq.enq('t',4);
    pq.enq('r',2);
    pq.enq('e',3);
    pq.enq('e',5);
    pq.deq();
    pq.show();
    return 0;
}