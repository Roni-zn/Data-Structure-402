#include <iostream>
using namespace std;
//-------Global Variable-----------
const int max_size=100;
//-------Queue Class---------------
class Queue
{
	private:
		int front=0;
		int rear=0;
		int queue[max_size];
	public:
		void Enqueue(int value);
		int Dequeue();
		int Peek();	
		void Reverse();
		bool is_empty();
		bool is_full();
		void display();
	
};

//-------Enqueue-----------------------
void Queue::Enqueue(int value)
{
	if(rear==max_size)
	{
	   is_full();
	}
	else
	{
	   queue[rear++]=value;
	}
}
//-------Dequeue-----------------------
int Queue::Dequeue()
{
	if(front==rear)
	{
		is_empty();
		return 100000;
	}
	else
	{
	
    	int dequeued_item=queue[front];
	    for(int i=front;i<=rear;i++)
    	{
		   queue[i]=queue[i+1];
    	}
    	rear--;
    	return dequeued_item;
    }
}
//-------Peek--------------------------
int Queue::Peek()
{
	return queue[front];
}
//-------Reverse-----------------------
void Queue::Reverse()
{
	int t=rear-1;
	for(int i=0;i<rear/2;i++)
	{	
		int temp = queue[i];
		queue[i] =queue[t];
		queue[t] = temp;
		t--;
	
	}
	
}
//-------Empty-------------------------
bool Queue::is_empty()
{
	if(front==rear)
	  return true;
	else
	  return false;
}
//-------Full-------------------------
bool Queue::is_full()
{
	if(rear==max_size-1)
	   return true;
	else
	   return false;
}
//------Display---------
void Queue::display()
{
	for(int i=0;i<rear;i++)
	{
		cout<<queue[i]<<"  ";
	}
	cout<<endl;
}


















