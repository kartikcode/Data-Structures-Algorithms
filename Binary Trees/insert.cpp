//Function to insert a value to a tree
struct node* insert(struct node *root, int value) 
{ 
    if(!root) 
    { 
        root = new node(value);
        return root ; 
    } 
    if(value > root->val) 
    { 
        root->right = insert(root->right, value); 
    } 
    else
    {
        root->left = insert(root->left, value); 
    } 
    return root; 
} 
