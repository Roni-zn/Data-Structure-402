#include <iostream>
using namespace std;

class CircularQueue
{
   private:
    int size;
    int* queue;
    int front;
    int rear;

    public:
	 CircularQueue(int size) {
        this->size = size;
        this->queue = new int[size];
        this->front = this->rear = -1;
		}
		void Enqueue();
		void Dequeue();
		void Peek();
		void ReverseQueue();
		bool IsEmpty();
		bool IsFull();

}

// ----Check if the queue is empty----
CircularQueue::bool IsEmpty()
{	
		if (this->front == -1) {
            return true;
        }
        return false;
};

// ----Check if the queue is full-----
CircularQueue::bool IsFull()
{
      if ((this->front == 0 && this->rear == this->size - 1) || ((this->rear + 1) % this->size == this->front)) {
            return true;
        }
        return false;
};
// ----Adding an element----
CircularQueue::void Enqueue(int element)
{
	 if (this->isfull()) {
            return false;
        }
        else if (this->isempty()) {
            this->front = this->rear = 0;
            this->queue[this->rear] = val;
        }
        else {
            this->rear = (this->rear + 1) % this->size;
            this->queue[this->rear] = val;
        }
        return true;
};
// ----Removing an element----
CircularQueue::void Dequeue()
{
	if (this->isempty()) {
            return -1;
        }
        else {
            int temp = this->queue[this->front];
            this->queue[this->front] = -1;
            this->front = (this->front + 1) % this->size;
            return temp;
        }
};

CircularQueue::void Peek()
{
 return this->queue[this->front];
};

CircularQueue::void ReverseQueue()
{
	    int start = this->front;
        int end = this->rear;
        int* A = this->queue;
        while (start < end) {
            swap(A[start], A[end]);
            start++;
            end--;
};
