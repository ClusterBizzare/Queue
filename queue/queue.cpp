#include<iostream>
using namespace std;

template<class T>
class queue{
private:
T *que;
int rear,front;
int size;
public:
queue(int sz)
{
  front=rear=-1;
  size = sz;
  que = new T[sz];
}

void enque(T val)
{
    if(rear==size-1)
    {
        cout<<"QUEUE OVERFLOW"<<endl;
    }
    else
    {
        if(front==-1)
        {
            front++;
        }
        rear++;
        que[rear]=val;
    }
}

void deque()
{
    if(front==-1 || front>rear)
    {
        cout<<"QUEUE UNDERFLOW"<<endl;
    }
    else
    {
        front++;
    }
}

void print()
{
  if(rear==-1 && front==-1)
  {
      cout<<"QUEUE UNDERFLOW"<<endl;
  }   
  else{
      for(int i=front;i<=rear;i++)
      {
          cout<<que[i]<<"\t";
      }
  }
}
};

int main()
{
    queue<int> q(5);
    q.enque(2);
    q.enque(4);
    q.enque(7);
    q.enque(0);
    q.enque(3);
    q.deque();
    q.enque(5);
    q.print();
    return 0;
} 