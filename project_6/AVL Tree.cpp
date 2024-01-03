#include <iostream> 
using namespace std; 
struct node
{
	int value; 
	node *left; 
	node *right; 
	int height;

};

class AVLTree
{
	public:
		int height(node *N);
		int getBalance(node *N);
		int max(int a, int b);
		node* findMin(node* N);
		node* newNode(int key);
		node* LeftRotate(node *x);
		node* RightRotate(node *y);
		node* insert( int key ,node* n);
		node* remove(int key, node* n);
		void preOrder(node *root);
		void inorder(node* t);
};

// -----height of the tree -----
int AVLTree::height(node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return N->height; 
} 
//---- balance factors----- 
int AVLTree::getBalance(node *N) 
{ 
	if (N == NULL) 
		return 0; 
	int balance = height(N->left) - height(N->right);
	 return balance; 
} 

int AVLTree::max(int a, int b) 
{ 
	return (a > b)? a : b; 
} 

node* AVLTree::findMin(node* N)
    {
        if(N == NULL)
            return NULL;
        else if(N->left == NULL)
            return N;
        else
            return findMin(N->left);
    }


node*  AVLTree::newNode(int key) 
{ 
	node* new_node = new node;
	new_node->value = key; 
	new_node->left = NULL; 
	new_node->right = NULL; 
	new_node->height = 1; 
	return(new_node); 
}


node*  AVLTree::LeftRotate(node *x) 
{ 
	node *y = x->right; 
	node *T2 = y->left; 
 
	y->left = x; 
	x->right = T2; 

	x->height = max(height(x->left), height(x->right)) + 1; 
	y->height = max(height(y->left), height(y->right)) + 1; 
 
	return y; 
}

node* AVLTree::RightRotate(node *y) 
{ 
	node *x = y->left; 
	node *T2 = x->right; 

	
	x->right = y;
	y->left = T2; 

	 
	y->height = max(height(y->left), height(y->right)) + 1; 
	x->height = max(height(x->left), height(x->right)) + 1; 

	 
	return x; 
} 


node* AVLTree::insert( int key ,node* n) 
{ 
	 if(n == NULL)
        {
            n = new node;
            n->value= key;
            n->height = 0;
            n->left = n->right = NULL;
        }
        else if(key < n->value)
        {
            n->left = insert(key, n->left);
            if(height(n->left) - height(n->right) == 2)
            {
                if(key < n->left->value )
                    n = RightRotate(n);
                else
					n->left = LeftRotate(n->left);
					n = RightRotate(n);
            }
        }
        else if(key > n->value)
        {
            n->right = insert(key, n->right);
            if(height(n->right) - height(n->left) == 2)
            {
                if(key > n->right->value)
                    n = LeftRotate(n);
                else
                    n->right = RightRotate(n->right);
        			n = LeftRotate(n);
            }
        }

        n->height = max(height(n->left), height(n->right))+1;
        return n;
}
	
node* AVLTree::remove(int key, node* n)
{
	node* temp;

	
	if (n == NULL)
		return NULL;


	else if (key < n->value)
		n->left = remove(key, n->left);
	else if (key > n->value)
		n->right = remove(key, n->right);


	else if (n->left && n->right)
	{
		temp = findMin(n->right);
		n->value = temp->value;
		n->right = remove(n->value, n->right);
	}
	
	else
	{
		temp = n;
		if (n->left == NULL)
			n = n->right;
		else if (n->right == NULL)
			n = n->left;
		delete temp;
	}
	if (n == NULL)
		return n;

	n->height = max(height(n->left), height(n->right)) + 1;


	if (height(n->left) - height(n->right) == 2)
	{
		
		if (height(n->left->left) - height(n->left->right) == 1)
			return LeftRotate(n);
		
		else
			n->right = RightRotate(n->right);
			return LeftRotate(n);
			
	}
	
	else if (height(n->right) - height(n->left) == 2)
	{
	
		if (height(n->right->right) - height(n->right->left) == 1)
			return RightRotate(n);
		else
			n->left = LeftRotate(n->left);
			return RightRotate(n); 
	}
	return n;
}

void AVLTree::preOrder(node *root) 
{ 
	if(root != NULL) 
	{ 
		cout << root->value << " "; 
		preOrder(root->left); 
		preOrder(root->right); 
	} 
} 

// ===== MAIN ===== 
int main() 
{  
	return 0; 
}
