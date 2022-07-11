#include<iostream>
using namespace std;

template<class T>
class cirque{
private:

T *que;
int front,rear;
int size;

public:
cirque(int sz)
{
    front=rear=-1;
    size=sz;
    que=new T[sz];
}

void enq(T val)
{
   if(front==0 && rear==size-1 || front==rear+1)
   {
       cout<<"OVERFLOW"<<endl;
   }
    else if(front==-1)
    { 
        front=0;
        rear=0;
        que[rear]=val;
    }
    else if(rear==size-1)
    {
        rear=0;
        que[rear]=val;
    }
    else
    {
        rear++;
        que[rear]=val;
    }
}

void deq()
{
  if(front==-1)
  {
      cout<<"UNDERFLOW"<<endl;
  }
  else if(front==rear)
  {
     front=rear=-1;
  }
  else if(front==size-1)
  {
     front=0;
  }
  else
  {
    front++;
  }
}

void show()
{
 if(front<=rear)
 {
    for(int i=front;i<=rear;i++)
    {
        cout<<que[i]<<"\t";
    }
 }
 else
 {
    for(int i=front;i<=size-1;i++)
    {
        cout<<que[i]<<"\t";
    }
    for(int i=0;i<=rear;i++)
    {
        cout<<que[i]<<"\t";
    }
 }
}

};

int main()
{
    cirque<int> q(5);
    q.enq(2);
    q.enq(3);
    q.enq(4);
    q.enq(7);
    q.enq(9);
    q.deq();
    q.deq();
    q.deq();
    q.deq();
    q.enq(5);
    q.enq(0);
    q.enq(5);
    q.enq(2);
    q.show();
    return 0;
}