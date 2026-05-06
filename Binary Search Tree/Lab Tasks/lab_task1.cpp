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

void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;
    int arr[] = {45, 25, 65, 15, 35, 55, 75};
    for (int i = 0; i < 7; i++) {
        root = insert(root, arr[i]);
    }

    cout << "inorder traversal: ";
    inorder(root);
    cout << "\n";

    cout << "preorder traversal: ";
    preorder(root);
    cout << "\n";

    cout << "postorder traversal: ";
    postorder(root);
    cout << "\n";

    return 0;
}