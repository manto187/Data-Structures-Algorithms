#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = right = NULL;
    }
};

Node* insert(Node* root, int value){
    if(root == NULL)
    return new Node(value);

    if(value<root->data)
    root->left = insert(root->left, value);

    else if(value>root->data)
    root->right = insert(root->right, value);

    return root;
}

bool search(Node* root, int key){
    if(root == NULL)
    return false;

    if(root->data == key)
    return true;

    if(key<root->data)
    return search(root->left, key);

    return search(root->right, key);
}

void inorder(Node* root){
    if(root == NULL)
    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int findMin(Node* root){
    while(root->left!=NULL)
    root = root->left;

    return root->data;
}

int findMax(Node* root){
    while(root->right!=NULL)
    root = root->right;

    return root->data;
}

int main(){
    Node* root == NULL;

    root = insert(root, 100);
    insert(root, 50);
    insert(root, 150);
    insert(root, 30);
    insert(root, 70);
    insert(root, 120);
    insert(root, 170);
    insert(root, 20);
    insert(root, 40);
    insert(rooot, 60);
    insert(root, 80);

    cout<<"inorder traversal: ";
    inorder(root);

    cout<<"\nminimum vale = "<<findMin(root);

    cout<<"\nmaximum value = "<<findMax(root);

    if(search(root, 70))
    cout<<"\n70 found: ";
    else
    cout<<"\n70 not found: ";

    return 0;
}
