#include <iostream>
using namespace std;

struct Node {

    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

Node* insert(Node* root, int value) {

    if(root == NULL)
        return new Node(value);

    if(value < root->data)
        root->left = insert(root->left, value);

    else
        root->right = insert(root->right, value);

    return root;
}

int sumNodes(Node* root){
    if(root == NULL)
    return 0;

    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

int main(){
    Node* root = NULL;

    root = insert(root, 100);
    insert(root, 50);
    insert(root, 150);
    insert(root, 30);
    insert(root, 70);
    insert(root, 120);
    insert(root, 170);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout<<"sum of all node = "<<sumNodes(root);

    return 0;
}