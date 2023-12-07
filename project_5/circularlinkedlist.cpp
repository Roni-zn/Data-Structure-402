 #include<iostream>
using namespace std;
//--- creating a data type for nodes ----
struct node
{
	int value;
	node *link;
};

class Circular_Linked_list
{
  private:
	node *head=NULL;

  public:
	void insert_at_begin(int data); //olia
	void insert_at_index(int data, int index);//olia
	void insert_at_end(int data);//olia
	void update(int data, int index);//olia
	int remove_at_begin ();//ronak
	int remove_at_index (int index);//ronak
	int remove_at_end ();//ronak
	int size_of_list();//ronak
	void concatenate(node *ptr);//olia
	void invert();//ronak
	void print();//temporary
};


int Circular_Linked_list::size_of_list()
{
	node *temp=head;
	int i = 0;
	while( temp->link != head )
	{
		temp = temp->link;
		i++;
	}
	return i;	
}

int Circular_Linked_list::remove_at_begin ()
{
	int data;
	node *temp= head;
	while( temp ->link != head)
	{
		temp = temp ->link;
	}
	
	temp ->link = head->link;
	head = head->link;
	data = temp->link;
	return data;
}

int Circular_Linked_list::remove_at_end ()
{
	int data;
	node *current = head , *temp;
	while(current->next != head)
	{
		temp=current;
		current=current->link;
	}
	temp->next=head;
	data = current->link;
	return data;
}

int Circular_Linked_list::remove_at_index (int index)
{
	int data;
	node *temp , *current = *head;
	for (int i= 0; i < index-1 ; i++)
	{
		temp = current;
		current = current->link;
	}
	temp->link = current -> link;
	data = current->link;
	return data;
}