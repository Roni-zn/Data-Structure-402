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
void Double_Linked_list::insert_at_begin(int data)
{
	
	
}

//--- insertion at the end --------------
void Double_Linked_list::insert_at_end(int data)
{


}

//--- insertion at index-----------------
void Double_Linked_list::insert_at_index(int data, int index)
{
	
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

}

//--- removing from the begining --------
int Double_Linked_list::remove_at_begin()
{
	node *temp = head->next->next;
	while(head != NULL)
	{
	 temp-> prev = NULL;
	 head = head->next;
	}
	temp -> prev = NULL;	
}

//--- removing from the end -------------
int Double_Linked_list::remove_at_end()
{
    node *temp=head;
	
		while (temp->next != NULL)
	{
		temp = temp->next;
	}
		temp-> next = NULL;
}

//--- removing at index -----------------
int Double_Linked_list::remove_at_index(int index)
{
	temp = head;
	for (int i = 0; i < index-1; i++)
	{
		if (temp->next != null)
		{
			temp = temp-> next;
		}
		ptr = temp -> next;  
        temp -> next = ptr -> next;  
        ptr -> next -> prev = temp; 
	}
 

}

//--- adding a list to our current list -
void Double_Linked_list::concatenate(node *ptr)
{

}

//--- inverting the list ----------------
void Double_Linked_list::invert()
{

}

//===== MAIN ====================================
int main()
{

}