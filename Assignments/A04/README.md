### Basic Binary Tree
- Ordinary BST with an insert, print, and helper funcion to create nodes
- Dynamically allocates memory
- Uses recursive functions

```
#include<stdio.h> 
#include<stdlib.h> 
#include<iostream>
using namespace std;
   
struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
   
// A utility function to create a new BST node 
struct node *newNode(int item) 
{ 
    struct node *temp = (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
// A utility function to do inorder traversal of BST 
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        cout << root->key << endl; 
        inorder(root->right); 
    } 
} 
   
struct node* insert(struct node* node, int key) 
{ 
    if (node == NULL) 
      return newNode(key); 
  
    if (key < node->key) 
        node->left = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key);    
  
    return node; 
} 
 
int main() 
{ 
    struct node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
   
    inorder(root); 
   
    return 0; 
} 
```

#### Source: https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
