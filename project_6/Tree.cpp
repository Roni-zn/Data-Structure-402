#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node
{
    int data;
    node* child;
    node* Sibling;
    node(int value)
    {
        this->data = value;
        child = Sibling = NULL;
    }

};

class tree
{
    private:
        node* root;
        void addSibling(node* n, int data);
        node* findParent(node* n);
        node* findLeaf(node* n);
        node* find(int value);
    public:
        tree(int value)
        {
            node* Root = new node(value);
            root = Root;
        }
        void insert(int root, int value);
        void remove(int value);
        void print();
};
//--- find parent --------------
node* tree::findParent(node* n)
{
    queue<node*> queue ;
    node* temp;
    node* parent;
    queue.push(root);
    while(!queue.empty())
    {
        parent = queue.front();
        temp = queue.front()->child;
        queue.pop();
        while(temp != NULL)
        {
            if(temp == n)
            return parent;
            queue.push(temp);
            temp = temp->Sibling;
        }
    }
    return NULL;

}
//--- find leaf -----------------
node* tree::findLeaf(node* n)
{
    // if(n->child == NULL && n->Sibling == NULL)
    //     return n;
    queue<node*> queue ;
    node* temp;
    queue.push(n);
    while(!queue.empty())
    {
        temp = queue.front()->child;
        queue.pop();
        while(temp != NULL)
        {
            if(temp->child == NULL && temp->Sibling == NULL)
                return temp;
            queue.push(temp);
            temp = temp->Sibling;
        }
    }
    return NULL;

}
//--- find ----------------------
node* tree::find(int value)
{
    if(value == root->data)
        return root;
    queue<node*> queue ;
    node* temp;
    queue.push(root);
    while(!queue.empty())
    {
        temp = queue.front()->child;
        queue.pop();
        while(temp != NULL)
        {
            if(temp->data == value)
                return temp;
            queue.push(temp);
            temp = temp->Sibling;
        }
    }
    return NULL;
}
//--- Add Sibling ---------------
void tree::addSibling(node* n, int value)
{
    if(n == NULL)
        return;
    while(n->Sibling)
        n = n->Sibling;
    n->Sibling = new node(value);
}
//-- insert --------------------
void tree::insert(int root, int value)
{
    node* n = find(root);
    if(n == NULL)
        return;
    if(n->child)
        addSibling(n->child, value);
    else
        n->child = new node(value);

}
//--- remove --------------------
void tree::remove(int value)
{
    node* n = find(value);
    node* replacement = findLeaf(n);
    if(n == NULL)
    {
        cout<<"given value dosen't exist";
    }
    else
    {
       
        if(replacement == NULL)
        { 
            node* parent = findParent(n);
            node* temp = parent->child;
            while(temp->Sibling->Sibling != NULL)
                temp = temp->Sibling;
            temp->Sibling = NULL;
        }
        else
        {
            node* parent = findParent(replacement);
            n->data = replacement->data;
            if(parent->child == replacement)
                parent->child = NULL;
            else
            {
                node* temp = parent->child;
                while(temp->Sibling->Sibling != NULL)
                    temp = temp->Sibling;
                temp->Sibling = NULL;

            }
        }
    }
}
//--- print ---------------------
void tree::print()
{
    
    queue<node*> queue ;
    node* temp = root;
    queue.push(root);
    cout<<root->data<<endl;
    while(!queue.empty())
    {
        temp = queue.front()->child;
        queue.pop();
        while(temp != NULL)
        {
            cout<<" "<<temp->data;
            queue.push(temp);
            temp = temp->Sibling;
        }
        cout<<endl;
    }
}

