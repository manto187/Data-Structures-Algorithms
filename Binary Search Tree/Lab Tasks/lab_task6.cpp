#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

int leafNodes(Node* root){
            if(!root) return 0;
            
            if(!root->left && !root->right) 
                return 1;
            return leafNodes(root->left) + leafNodes(root->right);
    
}

int main(){
    Node* root = NULL;
    int arr[] = {45, 25, 65, 15, 35, 55, 75};
    for(int i=0; i<7; i++)
        root = insert(root, arr[i]);
    
    cout << "total nodes: " << leafNodes(root) << endl;

    return 0;
}