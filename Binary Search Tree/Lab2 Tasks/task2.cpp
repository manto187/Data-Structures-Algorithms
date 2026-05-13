#include<iostream>
#include<climits>
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

bool isBST(Node* root, int min, int max){
    if(root == NULL)
    return true;

    if(root->data<=min || root->data>=max)
    return false;
    return isBST(root->left, min, root->data) && isBST(root->right, root->data, max);
}

int main(){
    Node* root = new Node(50);

    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);

    root->right->left = new Node(60);
    root->right->right = new Node(80);

    if(isBST(root, INT_MIN, INT_MAX))
    cout<<"valid BST";
    else
    cout<<"Not a BST";
    return 0;
}