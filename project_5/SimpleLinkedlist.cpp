#include<iostream>
using namespace std;

struct node
{
	int value;
	node *link;
};

class Linked_list
{
  private:
	node *head = NULL;

  public:
	void insert_at_begin(int data);
	void insert_at_index(int data, int index);
	void insert_at_end(int data);
	void update(int data, int index);
	int remove_at_begin ();
	int remove_at_index (int index);
	int remove_at_end ();
	int size_of_list();
	void concatenate(node *ptr);
	void invert();

};

//--- insertion at the begining ---------
void Linked_list::insert_at_begin(int data)
{
	node *new_node;
	new_node->value = data;
	if(head==NULL)
	{
		head = new_node;
		new_node->link = NULL;
	}
	else
	{
		new_node->link= head;
		head = new_node;
	}
	
}
//--- insertion at the end --------------
void Linked_list::insert_at_end(int data)
{
	node *new_node, *temp=head;
	new_node->value = data;
	while (temp->link != NULL)
	{
		temp = temp->link;
	}
	temp->link = new_node;
	new_node->link = NULL;
}
//--- insertion at index----------------
void Linked_list::insert_at_index(int data, int index)
{
	
}
//--- size of the list ----------
int Linked_list::size_of_list()
{

}
