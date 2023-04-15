#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left, *right;
    Node()
    {
        this->data = 0;
        this->left =NULL;
        this->right = NULL;
    }
};

struct Node* getnewnode(int data)
{
    struct Node *newnode;
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}
Node* newNode(Node* root,int val)
{
    if(root==NULL)
    {
        return getnewnode(val);
    }
    else if(root->data>val)
    {
        root->left = newNode(root->left,val);
    }
    else if(root->data < val)
    {
        root->right = newNode(root->right,val);
    }
    return root;

}
struct Node* deleteNode(Node* root,int val)
{
    
}

int main()
{
    Node* root;
}