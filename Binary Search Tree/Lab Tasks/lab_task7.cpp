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

int height(Node* root){
        if(root==NULL) return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return max(leftHeight, rightHeight) + 1;
            
    
}

int main(){
    Node* root = NULL;
    int arr[] = {45, 25, 65, 15, 35, 55, 75};
    for(int i=0; i<7; i++)
        root = insert(root, arr[i]);
    
    cout << "height : " << height(root) << endl;

    return 0;
}