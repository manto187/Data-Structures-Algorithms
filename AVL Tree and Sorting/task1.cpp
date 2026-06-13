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


Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = maxValue(getHeight(x->left),
                         getHeight(x->right)) + 1;

    y->height = maxValue(getHeight(y->left),
                         getHeight(y->right)) + 1;

    return y;
}

Node* insert(Node* root, int value)
{
    if(root == NULL)
        return new Node(value);

    if(value < root->data)
        root->left = insert(root->left, value);

    else if(value > root->data)
        root->right = insert(root->right, value);

    else
        return root;

    root->height = 1 + maxValue(getHeight(root->left),
                                getHeight(root->right));

    int balance = getBalance(root);

    // LL Case
    if(balance > 1 && value < root->left->data)
        return rightRotate(root);

    // RR Case
    if(balance < -1 && value > root->right->data)
        return leftRotate(root);

    // LR Case
    if(balance > 1 && value > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case
    if(balance < -1 && value < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
