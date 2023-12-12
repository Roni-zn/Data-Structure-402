#include<iostream>
using namespace std;

//--- creating a data type for nodes ----
struct node
{
	int value;
	node *next;
	node *prev;
};

//--- definition of linked list class ---
class Double_Linked_list
{
	
  public:
  	node *head = NULL;
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
	void print();

};

//--- insertion at the begining ---------
void Double_Linked_list::insert_at_begin(int data)
{
	node *new_node;
	new_node = new node;
	new_node->value = data;
	new_node->prev = NULL ;
	if(head==NULL)
	{
		head = new_node;
		new_node->next = NULL;
	}
	else
	{
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}

	
	
}

//--- insertion at the end --------------
void Double_Linked_list::insert_at_end(int data)
{
	node *new_node, *temp=head;
	new_node = new node;
	new_node->value = data;
	new_node->next = NULL;
    if(head==NULL)
    {
    	head = new_node;
		new_node->prev = NULL;
	}
	else
	{
    	while (temp->next != NULL)
	    {
			temp = temp->next;
		}
		temp->next = new_node;
		new_node->prev = temp;	
    }

}

//--- insertion at index-----------------
void Double_Linked_list::insert_at_index(int data, int index)
{
	node *new_node, *trail = head;
	new_node = new node;
	new_node->value = data;
	for (int i = 1; i < index-1; i++)
	{
		trail = trail->next;
	}
	new_node->next = trail->next;
	trail->next = new_node;
	new_node->next->prev = new_node;
	new_node->prev = trail;

}

//--- size of the list ------------------
int Double_Linked_list::size_of_list()
{
	node *temp=head;
	int i = 0;
	while( temp != NULL )
	{
		temp = temp->next;
		i++;
	}
	return i;
}

//--- updat at index --------------------
void Double_Linked_list::update(int data,int index)
{
	node *temp = head;
	for (int i = 1; i < index; i++)
	{
		temp = temp->next;
	}
	temp->value = data;

}

//--- removing from the begining --------
int Double_Linked_list::remove_at_begin()
{
	int data;
	data = head->value;
	head = head->next;
	head -> prev = NULL;
	return data;
		
}

//--- removing from the end -------------
int Double_Linked_list::remove_at_end()
{
	int data;
    node *temp=head;
	
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	data = temp->value;
	temp->prev->next = NULL;
	return data;
}

//--- removing at index -----------------
int Double_Linked_list::remove_at_index(int index)
{
	int data;
	node *temp;
	temp = head;
	for (int i = 1; i < index ; i++)
	{
		if (temp->next != NULL)
		{
			temp = temp-> next;
		}
	}
	data = temp->value; 
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	return data;
}

//--- adding a list to our current list -
void Double_Linked_list::concatenate(node *ptr)
{
	node *temp = this->head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = ptr;
	ptr->prev = temp;


}

//--- inverting the list ----------------
void Double_Linked_list::invert()
{
    node* temp = NULL;
    node* current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
        head = temp->prev;

}
//--- print -----------------------------
void Double_Linked_list::print()
{
	node *temp = head;
	if (head == NULL)
	   { 
        cout << "List is empty" << endl; 
        return; 
       }
	else
	{
		while (temp != NULL)
		{
			cout << temp->value << " ";
			temp = temp->next;
		}
	}	
	cout<<endl;
}


//===== MAIN ====================================
int main()
{
	return 0;
}