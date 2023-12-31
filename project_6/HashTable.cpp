#include <iostream>
#include <string>
#include <list>
using namespace std;
class HashTable
{
    private:
        struct node{
            int key;
            string value;
            node(int key, string value)
            {
                this->key = key;
                this->value = value;
            }
        };
        int bucket;
    list<node*> *table;
    int HashFunction(int key);
    public:
        HashTable(int size);
        void Insert(int key, string value);
        string Delete(int key);
        string Search(int key);
        void print();
};
//--- Hash table constructor ------------------
HashTable::HashTable(int size)
{
    this->bucket = size;
    table = new list<node*>[bucket];

}
//--- Hash Function ---------------------------
int HashTable::HashFunction(int key)
{
    int index = key % bucket;
    return index; 
}
//--- insert ----------------------------------
void HashTable::Insert(int key, string value)
{
    int index = HashFunction(key);
    node* entry = new node(key, value);
    if(!table[index].empty())
    {
        list<node*>::iterator i;
        node* temp ;
        for(i = table[index].begin(); i != table[index].end(); i++)
        {
            temp = *i;
            if(temp->key == key)
              break;
        
        }
        if(temp->key == key)
        {
            temp->value = value;
        }
        else
        {
            table[index].push_front(entry);
        }
    }
    else
    {
        table[index].push_front(entry);
    }
}
//--- search ----------------------------------
string HashTable::Search(int key)
{
    int index = HashFunction(key);
    list<node*>::iterator i;
    node* temp ;
    for(i = table[index].begin(); i != table[index].end(); i++)
    {
        temp = *i;
        if(temp->key == key)
            return temp->value;
       
    }
    return "not found";
}
//--- delete ----------------------------------
string HashTable::Delete(int key)
{
    int index = HashFunction(key);
    list<node*>::iterator i;
    string returnValue = "not found";
    node* temp ;
    for(i = table[index].begin(); i != table[index].end(); i++)
    {
        temp = *i;
        if(temp->key == key)
            break;
       
    }
    if(i != table[index].end())
    {
        returnValue = temp->value;
        table[index].erase(i);
    }
    return returnValue;
}
//--- print -----------------------------------
void HashTable::print()
{
    node* temp;
    for (int i = 0; i < bucket; i++)
    {
        cout << i <<": ";
        for (auto x : table[i])
        {
            temp = x;
            cout << " --> " <<temp->key<<":"<< temp->value;
        }
        cout << endl;
    }
}

