#include <iostream>
#include <string>
#include <stack>
using namespace std;
struct node
{
    public:
    int value;
    node* leftchild;
    node* rightchild;
    node(int data)
    {
        value = data;
        leftchild = NULL;
        rightchild = NULL;
    }
};

class BinarySearchTree
{
    private:
    node* root = NULL;
    node* FindParent(node* parent, node* Node);
    node* MinValueNode(node* Node);
    bool is_leaf(node* Node);
    public:
    void insert(int data);
    void remove(int data);
    node* search(int data);
    string preorder();
    string inorder();
    string postorder();

};
//--- find parrent ------------------
node* BinarySearchTree::FindParent(node* parent, node* Node)
{   
    while(parent)
    {
        if(parent->leftchild == Node || parent->rightchild == Node)
            break;
        if(Node->value < parent->value)
            parent = parent->leftchild;
        else if(Node->value > parent->value)
            parent = parent->rightchild;

    }
    return parent;

}
//--- is leaf ------------------------
bool BinarySearchTree::is_leaf(node* Node)
{
    if( Node->leftchild == NULL && Node->rightchild == NULL)
        return true;
    else
        return false;
}
//--- min value node -----------------
node* BinarySearchTree::MinValueNode(node* Node)
{
    node* temp = Node;
    while(temp->leftchild!= nullptr)
        temp = temp->leftchild;

    return temp;
}
//--- insert -------------------------
void BinarySearchTree::insert(int data)
{
    node* newnode = new node(data);
    if(root == NULL)
    {
        root = newnode;
    }
    else
    {
        node* temp = root;
        node* Node;
        while( temp)
        {
            Node = temp;
            if( data < temp->value)
                temp = temp->leftchild;
            else
                temp = temp->rightchild;
        }
        if(data < Node->value)
            Node->leftchild = newnode;
        else
            Node->rightchild = newnode;
        
    }
}
//--- remove -------------------------
void BinarySearchTree::remove(int data)
{
    if(search(data) == NULL)
        cout<<"number doesn't exist";
    else
    {
        node* current = search(data);
        if( is_leaf(current))
        {
            node* parent = FindParent(root, current);
            if(current == parent->leftchild)
                parent->leftchild = NULL;
            else
                parent->rightchild = NULL;
            free(current);
        }
        else if( current->leftchild == NULL)
        {
            node* parent = FindParent(root, current);
            if(current == parent->leftchild)
                parent->leftchild = current->rightchild;
            else
                parent->rightchild = current->rightchild;
            free(current);
        }
        else if( current->rightchild == NULL)
        {
            node* parent = FindParent(root, current);
            if(current == parent->leftchild)
                parent->leftchild = current->leftchild;
            else
                parent->rightchild = current->leftchild;
            free(current);
        }
        else
        {
            node* minNode = MinValueNode(current->rightchild);
            node* parrent = FindParent(current, minNode);
            current->value = minNode->value;
            if(minNode == parrent->leftchild)
                parrent->leftchild = NULL;
            else
                parrent->rightchild = minNode->rightchild;
            
            free(minNode);
        }

    }
}
//--- search -------------------------
node* BinarySearchTree::search(int data)
{
    node* temp = root;
    while( temp != NULL)
    {
        if(data == temp->value)
            return temp;
        if( data < temp->value)
            temp = temp->leftchild;
        else if( data > temp->value)
            temp = temp->rightchild;
        
    }
    return NULL;

}
//--- inorder ------------------------
string BinarySearchTree::inorder()
{
    node* temp = root;
    string result;
    stack <node*> s;
    if(temp == NULL)
        result = "empty";
    else
    {
        while( temp != NULL || s.empty() == false)
        {
            while( temp!= NULL)
            {               
                s.push(temp);
                temp = temp->leftchild;
            }
            temp = s.top();
            s.pop();
            result += to_string(temp->value) + " ";
            temp = temp->rightchild;
        }
    }
    return result;
}
//--- preorder -----------------------
string BinarySearchTree::preorder()
{
    node* temp = root;
    string result;
    stack <node*> s;
    if(temp == NULL)
        result = "empty";
    else
    {
        while(temp != NULL|| s.empty() == false)
        {
            while( temp != NULL)
            {
                result += to_string(temp->value) + " ";

                if(temp->rightchild)
                    s.push(temp->rightchild);

                temp = temp->leftchild;
            }
            if(!s.empty())
            {
                temp = s.top();
                s.pop();
            }
        }
    }
    return result;
}
//--- postorder ----------------------
string BinarySearchTree::postorder()
{
    node* temp = root;
    string result;
    stack <node*> s1,s2;
    s1.push(temp);
    if(temp == NULL)
        result = "empty";
    else
    {
        while( !s1.empty())
        {
            temp = s1.top();
            s1.pop();
            s2.push(temp);
            if(temp->leftchild)
                s1.push(temp->leftchild);
            if(temp->rightchild)
                s1.push(temp->rightchild); 
        }
        while( !s2.empty())
        {
            result += to_string(s2.top()->value) + " ";
            s2.pop();
        } 
    }
    return result;
}


//==== another way to get the postorder traverse =======================
/*while(temp != NULL|| s1.empty() == false)
        {
            while( temp != NULL)
            {
                s2.push(temp);
                if(temp->leftchild)
                    s1.push(temp->leftchild);

                temp = temp->rightchild;
            }
            if(!s1.empty())
            {
                temp = s1.top();
                s1.pop();
            }

        }
        while( !s2.empty())
        {
            result += to_string(s2.top()->value) + " ";
            s2.pop();
        }*/
