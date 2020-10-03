#include <iostream>
#include <queue>
#include <vector> 
using namespace std;

struct node 
{ 
  int key; 
  struct node *left;
  struct node *right; 
}; 

struct node* newNode(int item) 
{ 
  node *temp = new node;
  temp->key = item;
  temp->left = NULL;
  temp->right = NULL; 
  return temp; 
} 

void postorder(struct node *root) 
{ 
  if (root != NULL)
  {
    postorder(root->left);  
    postorder(root->right); 
    cout << root->key << endl;
  }
} 

struct node* insert(struct node* n, int key) 
{ 
  if (n == NULL) 
    return newNode(key); 
  
  if (key < n->key) 
    n->left = insert(n->left, key); 
  else if (key > n->key) 
    n->right = insert(n->right, key);    
  
  return n; 
}

int main() 
{
  int items = 0;
  vector <int> small;
  vector <int> big;

  struct node *root = NULL;
  
  while (cin >> items)
  {
    root = insert(root, items);
  }

  postorder(root);
}
