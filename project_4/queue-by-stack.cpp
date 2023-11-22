#include <iostream>
#include <stack>
using namespace std;


class MyQueue {
private:
    stack<int> stack1; 
    stack<int> stack2; 

public:
    MyQueue() {
    	void enqueue(int );
    	int dequeue();
    }
};


MyQueue :: void enqueue(int a) {
        while (!stack2.empty() {
            stack1.push(stack2.top());
            stack2.pop();
        }

        
        stack1.push(a);
    }

MyQueue :: int dequeue() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }

        int front = stack2.top();
        stack2.pop();
        return front;
    }