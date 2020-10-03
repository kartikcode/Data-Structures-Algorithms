//Function for searching a value in the tree
struct node* search(struct node* root, int key) 
{ 
    if (root == NULL || root->val == key) 
       return root; 
    if (root->val < key) 
       return search(root->right, key); 
  
    return search(root->left, key); 
} 
