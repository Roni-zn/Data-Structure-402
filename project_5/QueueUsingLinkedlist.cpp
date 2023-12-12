#include <iostream>
#include "E:\UniShits\Repossitories\Data-Structure-402\project_5\SimpleLinkedlist.cpp"
using namespace std;

class queue
{
    private:
        Linked_list l;
        int max_size;
    public:
        queue(int size)
        {
            max_size = size;
        }  
        void Enqueue(int value);
		int Dequeue();
		int Peek();	
		void Reverse();
		bool is_empty();
		bool is_full();
		void display();    

};

//--- Enqueue --------------------
void queue::Enqueue(int value)
{
    if(l.size_of_list() <= max_size)
        l.insert_at_end(value);    
}
//--- Dequeue --------------------
int queue::Dequeue()
{
   return l.remove_at_begin();
}
//--- Peek -----------------------
int queue::Peek()
{
    return l.head->value;
}
//--- Reverse --------------------
void queue::Reverse()
{
    l.invert();
}
//--- is empty -------------------
bool queue::is_empty()
{
    if(l.size_of_list() == 0)
        return true;
    else
        return false;    
}
//--- is full --------------------
bool queue::is_full()
{
    if(l.size_of_list() == max_size)
        return true ;
    else
        return false;
}
//--- display --------------------
void queue::display()
{
    l.print();
}
//=== MAIN =========================================
int main()
{
    return 0;
}