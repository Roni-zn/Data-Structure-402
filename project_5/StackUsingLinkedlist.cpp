#include<iostream>
#include"E:\UniShits\Repossitories\Data-Structure-402\project_5\SimpleLinkedlist.cpp"
using namespace std;

class stack
{
   private:
    Linked_list l;
    public:
        void push(int value);
		int pop();
		int peek();
		bool is_empty();	
	
        
};
//--- push ----------------------------
void stack::push(int value)
{
    l.insert_at_begin(value);
}
//--- pop ------------------------------
int stack::pop()
{
    return l.remove_at_begin();
}
//--- peek -----------------------------
int stack::peek()
{
   return l.head->value;
}
//--- is empty -------------------------
bool stack::is_empty()
{
    if(l.size_of_list() == 0)
        return true;
    else 
        return false;    

}
//--- MAIN -----------------------------
int main()
{
    return 0;
}