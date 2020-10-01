#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define loop(x,n) for(int x = 0; x < n; ++x)
#define ll long long int
typedef vector<int> vi; 
typedef pair<int, int> pi; 
#define pb push_back 

//Structure of a node of a tree
struct node { 
    int val; 
    struct node* left; 
    struct node* right;
    node(int data) 
    { 
        val = data;
        left = NULL; 
        right = NULL; 
    } 
}; 

//Function to insert a value to a node
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

//Function for searching a value in the tree
struct node* search(struct node* root, int key) 
{ 
    if (root == NULL || root->val == key) 
       return root; 
    if (root->val < key) 
       return search(root->right, key); 
  
    return search(root->left, key); 
} 

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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //Example usage of each utiliy
    struct node* root=insert(root,100);
    insert(root,0);
    insert(root,1000);
    struct node* sh=search(root,10);
    if(sh==0)cout<<"Value not present in tree\n";
    else cout<<"Value present in tree\n";
    sh=search(root,0);
    if(sh==0)cout<<"Value not present in tree\n";
    else cout<<"Value present in tree\n";
    cout<<"Inorder : ";
    inorder(root);
    cout<<"\nPreorder : ";
    preorder(root);
    cout<<"\nPostorder: ";
    postorder(root);
    return 0;
}