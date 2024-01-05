#include <iostream>
using namespace std;

struct node {
  int value;
  node* parent;
  node* left;
  node* right;
  char color;
};

class RBT
{
	private:
        node* successor(node *p);
        void leftrotate(node*);
    	void rightrotate(node*);
        void insertFix(node*);
        void removeFix(node *q);
	public:
		node* root = NULL;
		void insert(int key);
        node* remove(int x);
        void inorder(node* Root);
        void preOrder(node *root);


};
node* RBT::successor(node *p)
{
      node *y=NULL;
     if(p->left != NULL)
     {
         y = p->left;
         while(y->right != NULL)
              y = y->right;
     }
     else
     {
         y = p->right;
         while(y->left != NULL)
              y = y->left;
     }
     return y;
}
void RBT::leftrotate(node *p)
{
    if(p->right == NULL)
        return ;
    else
    {
       node *y = p->right;
       if(y->left != NULL)
        {
        	p->right = y->left;
        	y->left->parent = p;
        }
        else
            p->right = NULL;
            
        if(p->parent != NULL)
            y->parent = p->parent;
        if(p->parent == NULL)
    		root=y;
       else
        {
    	    if(p == p->parent->left)
            	p->parent->left = y;
            else
                p->parent->right = y;
        }
        y->left = p;
       p->parent = y;
    }
}
void RBT::rightrotate(node *p)
{
    if(p->left == NULL)
        return ;
    else
    {
        node *y = p->left;
        if(y->right != NULL)
        {
        	p->left = y->right;
        	y->right->parent = p;
        }
        else
            p->left = NULL;

        if(p->parent != NULL)
            y->parent = p->parent;
        if(p->parent == NULL)
            root = y;
        else
        {
    	    if(p == p->parent->left)
               p->parent->left = y;
            else
               p->parent->right = y;
        }
        y->right = p;
        p->parent = y;
    }
}

void RBT::insert(int key)
{
    node* p = root ,*q = NULL;
    node* new_node = new node;
    new_node->value = key;
    new_node->left = NULL;
    new_node->right =  NULL;
    new_node->color = 'r';

    if(root == NULL)
    {
        root = new_node;
        new_node->parent = NULL;
    }
    else
    {
	  while(p != NULL)
    	{
            q = p;
    	    if(p->value < new_node->value)
                p = p->right;
            else
                p = p->left;
        }

        new_node->parent = q;
        if(q->value < new_node->value)
            q->right = new_node;
        else
            q->left = new_node;
    }
    insertFix(new_node);
}
 // --- recoloring and rotating nodes ---
void RBT::insertFix(node *n)
{ 

	node *u; //uncle
    if(root == n)
        n->color='b';
    
    while(n->parent != NULL && n->parent->color =='r' )
    {
       node *g = n->parent->parent; //grandparent
       if(g->left == n->parent) // left child 
        {
	        if(g->right != NULL)
            {
            	u = g->right;
                if(u->color == 'r')
                {
                    n->parent->color ='b';
                    u->color ='b';
            	    g->color ='r';
                    n = g;
                }
            }
            else
            {
                if(n->parent->right == n) //triangle case
                {
                    n = n->parent;
                    leftrotate(n);
                    n->parent->color = 'b';
            	    g->color = 'r';
                }
                else if (n->parent->left == n) // line case
                {
                    leftrotate(g); 
                }   
            }
        }
        else // right child
        {
            if(g->left != NULL)
            {
                u=g->left;
                if(u->color =='r')
                {
                    n->parent->color = 'b';
                    u->color = 'b';
                    g->color = 'r';
                    n = g;
                }
            }
        	else
        	{
            	if(n->parent->left == n) //triangle case
                {
                    n =n->parent;
                    rightrotate(n);
                
                n->parent->color = 'b';
                g->color = 'r';
                }
                else if (n->parent->right == n) // line case
                {
                    rightrotate(g);
                }
                
            }
        }
        root->color = 'b'; 
    }
}

node* RBT::remove(int x)
{
    node* r = root;
    node *y = NULL;
    node *q = NULL;
    int found = 0;
    
    while(r != NULL && found == 0)  //-- searching --
    {
        if(r->value == x)
        found=1;
        if(found == 0)
        {
            if(r->value < x)
                r = r->right;
            else
                r = r->left;
        }
    }
 
        if(r->left == NULL || r->right == NULL)
            y = r;
        else
           y = successor(r);
        if(y->left != NULL)
            q = y->left;
        else
        {
            if(y->right != NULL)
                q = y->right;
            else
                q = NULL;
        }

        // the parent pointer of q to point to the parent of y
        if(q != NULL)
            q->parent = y->parent;
        // transplant
        // y is root . root points to q
        if(y->parent == NULL)
            root = q;
        else //updates the appropriate child pointer of the parent to point to q.
        {
            if(y == y->parent->left)
                y->parent->left = q;
            else
               y->parent->right = q;
        }
        if(y != r) // updates the key and color of p to match those of y.
        {
            r->color = y->color;
            r->value = y->value;
        }
         if(y->color == 'b') 
            removeFix(q);
    delete y;   
    return 0;
}

void RBT::removeFix(node *q)
{
    node *s; // sibling of q
    while(q != root && q->color == 'b') 
    {
        if( q->parent->left == q)
        {
            s = q->parent->right;
            if( s->color == 'r')
            {
                s->color = 'b';
                q->parent->color = 'r';
                leftrotate(q->parent);
                s = q->parent->right;
            }
            if(s->right->color == 'b' && s->left->color == 'b') 
            {
                s->color = 'r'; 
                q = q->parent;
            }
            else
            {
                if(s->right->color=='b' && s->left->color == 'r')
                {
                s->left->color == 'b';
                s->color = 'r';
                rightrotate(s);
                s = q->parent->right;
                }
                else
                {
                s->parent->color ='b';
                s->right->color = 'b';
                leftrotate(q->parent);
                }
                q = root ;
            }
        }
        else 
        {
            s=q->parent->left;
            if(s->color=='r')
            {
                s->color='b';
                q->parent->color='r';
                rightrotate(q->parent);
                s=q->parent->left;
            }
                if(s->left->color=='b'&&s->right->color=='b')
                {
                    s->color='r';
                    q=q->parent;
                }
                else 
                {
                    if(s->left->color=='b')
                    {
                        s->right->color='b';
                        s->color='r';
                        leftrotate(s);
                        s=q->parent->left;
                    }
                    else
                    {
                        s->parent->color ='b';
                        s->right->color = 'b';
                        leftrotate(q->parent);
                    }
                }
        }
    q->color='b';
    root->color='b';
    }
}

void RBT::inorder(node* t)
{ 
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->value << " ";
        inorder(t->right);

}
void RBT::preOrder(node *root) 
{ 
	if(root != NULL) 
	{ 
		cout << root->value << "." << root->color <<endl; 
		preOrder(root->left); 
		preOrder(root->right); 
    }
}

int main()
{
        RBT rbt;
        rbt.insert(10);
        rbt.insert(5);
        rbt.insert(4);
        rbt.insert(6);
        rbt.insert(3);
        rbt.preOrder(rbt.root);
        rbt.inorder(rbt.root);
}