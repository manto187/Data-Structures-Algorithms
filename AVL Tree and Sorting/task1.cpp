#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

int getHeight(Node* root){
    if(root == NULL)
        return 0;

    return root->height;
}

int getBalance(Node* root)
{
    if(root == NULL)
        return 0;

    return getHeight(root->left) - getHeight(root->right);
}

int maxValue(int a, int b)
{
    return (a > b) ? a : b;
}

Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = maxValue(getHeight(y->left),
                         getHeight(y->right)) + 1;

    x->height = maxValue(getHeight(x->left),
                         getHeight(x->right)) + 1;

    return x;
}