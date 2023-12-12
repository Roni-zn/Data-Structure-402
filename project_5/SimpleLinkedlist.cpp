 #include<iostream>
using namespace std;
//--- creating a data type for nodes ----
struct node
{
	int value;
	node *link;
};
//--- definition of linked list class ---
class Linked_list
{
  public:
  	node *head=NULL;
	void insert_at_begin(int data); //olia
	void insert_at_index(int data, int index);//olia
	void insert_at_end(int data);//olia
	void update(int data, int index);
	int remove_at_begin ();
	int remove_at_index (int index);
	int remove_at_end ();
	int size_of_list();
	void concatenate(node *head2);
	void invert();
	void print();
};

//--- insertion at the begining ---------
void Linked_list::insert_at_begin(int data)
{
	node *new_node;
	new_node = new node;
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
	new_node = new node;
	new_node->value = data;
    if(head==NULL)
    {
    	head = new_node;
		new_node->link = NULL;
	}
	else
	{
    	while (temp->link != NULL)
	    {
			temp = temp->link;
		}
		temp->link = new_node;
		new_node->link = NULL;
    }
}
//--- insertion at index-----------------
void Linked_list::insert_at_index(int data, int index)
{
	node *new_node, *trail = head;
	new_node = new node;
	new_node->value = data;
	for (int i = 1; i < index-1; i++)
	{
		trail = trail->link;
	}
	new_node->link = trail->link;
	trail = new_node;
}
//--- size of the list ------------------
int Linked_list::size_of_list()
{
	node *temp=head;
	int i = 0;
	while( temp != NULL )
	{
		temp = temp->link;
		i++;
	}
	return i;
}
//--- updat at index --------------------
void Linked_list::update(int data,int index)
{
	node *temp = head;
	for (int i = 1; i < index; i++)
	{
		temp = temp->link;
	}
	temp->value = data;
	
}
//--- removing from the begining --------
int Linked_list::remove_at_begin()
{
	int data=head->value;
	head = head->link;
	return data;
}
//--- removing from the end -------------
int Linked_list::remove_at_end()
{
	
	node *temp=head;
	int data;
	while (temp->link->link!= NULL)
	{
		temp = temp->link;
	}
	data=temp->link->value;
	temp->link=NULL;
	return data;
	
}
//--- removing at index -----------------
int Linked_list::remove_at_index(int index)
{
	node *temp = head;
	int data;
	for(int i = 1; i < index-1; i++)
	{
		if(temp->link != NULL)
		temp = temp->link;
	}
	data=temp->link->value;
	temp->link = temp->link->link;
	return data;
}
//--- adding a list to our current list -
void Linked_list::concatenate(node *head2)
{
	node *temp = this->head;
	while(temp->link != NULL)
	{
		temp=temp->link;
	}
	temp->link=head2;

}
//--- inverting the list ----------------
void Linked_list::invert()
{
	node *pre = NULL; 
	node *current = head; 
	node *temp;
	 while(current != NULL)
	 {
	 	temp = current->link;
	 	current->link = pre;
	 	pre = current;
	 	current = temp;
	 }
		head = pre;
}
//--- print (temporary) -----------------
void Linked_list::print()
{
	node *temp = head;
	 if (head == NULL)
	   { 
        cout << "List is empty" << endl; 
        return; 
       }
	while (temp != NULL)
	{
		cout << temp->value << " ";
		temp = temp->link;
	}
	cout<<endl;
}
