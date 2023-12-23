#include <iostream>
#include "D:\UNI\projects\Data-Structure-402\project_5\SimpleLinkedlist.cpp"


struct node* swap(struct node* ptr1, struct node* ptr2)
{
    int tmp = ptr1->value;
    ptr1->value = ptr2->value;
    ptr2->value = tmp;
}


class Bubblesort
{
	private:
		Linked_list l;
		
	public:
		void add(int d);
		int bubblesort();
		void print_n();
};

// ----- insert-----
void Bubblesort::add(int d)
{
	l.insert_at_begin (d);
}

// ---- print -----
void Bubblesort::print_n()
{
	l.print();
}

// ----- sort -----
int Bubblesort::bubblesort()
{
	int n = l.size_of_list();
    node* h;
    h = l.head;
    node* i = h;
    node* j = i->link;
  
    for (i = l.head ; i != NULL ; i = i->link)
    {
  
        for (j = i ; j != NULL ; j = j->link) 
        {
  
            if (i -> value > j->value)
            {

             swap(i, j);
            }
		}
	}
}
 // ======== main =====
int main() {
	return 0;
}