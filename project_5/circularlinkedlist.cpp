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
  public:
  	node *head=NULL;
  	node *last=NULL;
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

//---- insertion at begininig -----------
void Circular_Linked_list::insert_at_begin(int data)
{
	node *new_node;
	new_node = new node;
	new_node->value = data;
	if(head == NULL)
	{
		this->head = new_node;
		this->last = new_node;
		new_node->link = this->head;
	}
	else
	{
		new_node->link = this->head;
		this->head = new_node;
		last->link = new_node;
	}
	
}
//---- insertion at the end -------------
void Circular_Linked_list::insert_at_end(int data)
{
	node *new_node;
	new_node = new node;
	new_node->value = data;
	if(head == NULL)
	{
		this->head = new_node;
		this->last = new_node;
		new_node->link = this->last;
	}
	else
	{
		new_node->link = head;
		last->link = new_node;
		last = new_node;
	}
	
}
//---- insertion at index --------------
void Circular_Linked_list::insert_at_index(int data,int index)
{
	
	node *new_node,*temp = head;
	new_node = new node;
	new_node->value = data;
	for(int i = 1 ; i<index-1;i++ )
	{
		temp = temp->link;
	}
	new_node->link = temp->link;
	temp->link = new_node;
}
//---- update --------------------------
void Circular_Linked_list::update(int data,int index)
{
	node *temp = head;
	for(int i = 1 ; i<index ;i++ )
	{
		temp = temp->link;
	}
	temp->value = data ;
}
//---- concatenate -------- second list's
// last pointer should be passed to this method -
void Circular_Linked_list::concatenate(node *ptr)
{
	this->last->link = ptr->link ;
	this->last = ptr ;
	this->last->link = this->head ;
	
} 
//---- size ----------------------------
int Circular_Linked_list::size_of_list()
{
	node *temp=head;
	int i ;
	if(head == NULL)
		i=0;
	else
	{	
		i=1;
		while( temp->link != head )
		{
			temp = temp->link;
			i++;
		}
   }
	return i;	
}
//---- remove at the begining ----------
int Circular_Linked_list::remove_at_begin ()
{
	int data;
	node *temp= head;
	while( temp ->link != head)
	{
		temp = temp ->link;
	}
	
	data = head ->value ;
	temp ->link = head->link;
	head = head->link;
	return data;
}
//---- remove at the end ---------------
int Circular_Linked_list::remove_at_end ()
{
	int data;
	node *current = head , *temp;
	while(current->link != head)
	{
		temp=current;
		current=current->link;
	}
	temp->link=head;
	data = current->value;
	return data;
}
//---- remove at index ------------------
int Circular_Linked_list::remove_at_index (int index)
{
	int data;
	node *temp , *current , *temp2;
	current = head;
	temp = head;
	if(index == 1)
	{
			while( temp ->link != head)
		{
			temp = temp ->link;
		}
	
		data = head ->value ;
		temp ->link = head->link;
		head = head->link;
	}
	else
	{
		for (int i= 1; i <= index ; i++)
		{
			temp2 = temp;
			temp = current;
			data = current->value;
			current = current->link;
		}
		temp2->link = current ;
	
	}
	
	return data;
}
//---- print ----------------------------
void Circular_Linked_list::print()
{
	node *temp ;
	 if (head == NULL)
	   { 
        cout << "List is empty" << endl; 
        return; 
       }
    else
	{
		
	   temp = head; 
		do
		{
			cout << temp->value << " ";
			temp = temp->link;
		} while (temp != head );
		cout<<endl;
	}
}

void Circular_Linked_list:: invert()
{
	
  if(head != NULL) 
  {
    node *prev = head;
    node *temp = head;
    node *current = head->link;

    prev->link = prev;

    while(current != head) {
      temp = current->link;
      current ->link = prev;
      head->link = current;
      prev = current;
      current = temp;
    }

    head = prev;
  }
}



