//Function for inorder traversal of tree
void inorder(struct node *root) 
{ 
    if(!root) 
    { 
        return; 
    } 
    inorder(root->left); 
    cout << root->val<<" "; 
    inorder(root->right); 
} 

//Function for preorder traversal of tree
void preorder(struct node *root) 
{ 
    if(!root) 
    { 
        return; 
    } 
    cout << root->val<<" "; 
    preorder(root->left); 
    preorder(root->right); 
} 

//Function for postorder traversal of tree
void postorder(struct node *root) 
{ 
    if(!root) 
    { 
        return; 
    } 
    
    postorder(root->left); 
    postorder(root->right); 
    cout << root->val<<" "; 
} 