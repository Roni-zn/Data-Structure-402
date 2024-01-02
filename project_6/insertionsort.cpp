#include <iostream>
#include "C:\Repositories\Data-Structure-402\project_5\SimpleLinkedlist.cpp"
using namespace std;


class InsertionSort
{
	private:
		Linked_list l;
	public:
		void add(int );
		void print();
		void insertion_sort();
};

// ----- add -----
void InsertionSort:: add(int d)
{
	l.insert_at_begin(d);
}
// ---- print ----
void InsertionSort:: print()
{
	l.print();
}
//----- sort -----
void InsertionSort:: insertion_sort()
{
	node *head = l.head;
	node *temp= l.head;
	while(temp!= NULL){
			node *next=temp->link;
			node *cur =head;
			node *prev=head;
		while(cur !=next)
		{
			if( cur ->value > temp-> value )
			{
				temp->link =cur; 
				if(cur == head)
				{
					head =temp;
				}
				else
				{
					prev->link= temp;
				}
			while(cur ->link !=temp) 
			{
				cur = cur ->link;
			}
			cur ->link=next;
		}
		prev=cur ;
		cur = cur ->link;
		}
		temp=next;

	}
}
int main() {
	InsertionSort s;
	s.add(11);
	s.add(9);
	s.add(12);
	s.add(7);
	s.print();
	s.insertion_sort();
	s.print();
	return 0;
}