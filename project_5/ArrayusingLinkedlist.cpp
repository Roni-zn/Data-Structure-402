#include <iostream>
#include "D:\UNI\projects\Data-Structure-402\project_5\SimpleLinkedlist.cpp"
using namespace std;

class Array
{
	private:
		Linked_list l;
		
	public:
		void Add(int);
		 void Insert(int,int);
		 int Delete(int);
		 void print();
		 
};

void Array:: print()
{
	l.print();
}
//--- Add -----------------------------
void Array:: Add(int value)
{
	l.insert_at_end(value);
}

//--- Insert -----------------------------
void Array::Insert(int index, int value)
{
	l.insert_at_index(value , index);
}

//--- Delete -----------------------------
int Array::Delete(int value)
{
	return	l.remove_at_index(value);
}

//--- MAIN -----------------------------
int main()
{
    return 0;
}

