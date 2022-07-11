#include<iostream>
using namespace std;

template<class T>
class DEqueue{
private:
int front,rear;
int size;
T *dq;
public:

DEqueue(int s)
{
  front=rear=-1;
  size=s;
  dq = new T[s];
}

void enqf(T val)
{
   if((front==0 && rear==size-1) || (front == rear+1))
   {
       cout<<"can't insert at rear end"<<endl;
   }  
   else if(front==-1)
   {
     front=rear=0;
     dq[front]=val;
   }
   else if(front==0)
   {
     front=size-1;
     dq[front]=val;
   }
   else{
     front--;
     dq[front]=val;
   }
}

void enqr(T val)
{
  if(front==0 && rear==size-1 || front == rear+1)
   {
       cout<<"can't insert at rear end"<<endl;
   }
  else if(front==-1)
  {
      front=rear=0;
      dq[rear]=val;
  }
  else if(rear==size-1)
  {
      rear=0;
      dq[rear]=val;
  }
  else
  {
    rear++;
    dq[rear]=val;
  }
}

void deqf()
{
  if(front==-1)
   {
     cout<<"empty"<<endl;
   }
   if(front==rear)
   {
     front=rear-1;
   }
   else if(front==size-1)
   {
     front=0;
   }
   else{
     front++;
   }
}

void deqr()
{
   if(front==-1)
   {
     cout<<"empty"<<endl;
   }
   else if(front==rear)
   {
     front=rear=-1;
   }
   else if(rear==0)
   {
     rear=size-1;
   }
   else{
     rear--;
   }
}

void show()
{
 if(front<=rear)
 {
    for(int i=front;i<=rear;i++)
    {
        cout<<dq[i]<<"\t";
    }
 }
 else
 {
    for(int i=front;i<=size-1;i++)
    {
        cout<<dq[i]<<"\t";
    }
    for(int i=0;i<=rear;i++)
    {
        cout<<dq[i]<<"\t";
    }
 }
}

};
int main()
{
    DEqueue<char> Dq(5);
    Dq.enqr('a');
    Dq.enqr('b');
    Dq.enqr('c');
    Dq.enqr('d');
    Dq.enqr('e');
    Dq.deqf();
    Dq.enqr('k');
    Dq.show();
    return 0;
}