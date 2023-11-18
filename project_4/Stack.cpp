#include <iostream>
using namespace std;

//------Stack--------------------
class Stack{
	
	private:
		int top=-1;
		int stack[100];
		
	public:
		void push(int value);
		int pop();
		int peek();
		bool is_empty();	
	
};

//------is empty-----------------
bool Stack::is_empty()
{
	if(this->top==-1)
	   return true;
	else
	   return false;   
}
//-------push--------------------
void Stack::push(int value)
{
	/*if there was a "is full" 
	method,we would've check 
	that first;then push an item*/
	this->top+=1;
	this->stack[this->top]=value;
}
//------pop----------------------
int Stack::pop()
{
	if(is_empty()==true)
	   return 0;
	else
	   return this->stack[this->top--];
}
//------peek---------------------
int Stack::peek()
{
	return this->stack[this->top];
}



int main()
{
	return 0;
}










