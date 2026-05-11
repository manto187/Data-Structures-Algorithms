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

bool search(Node* root, int value) {
    if (root == NULL) {
        return false;
    }
    if (root->data == value) {
        return true;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int main() {
    Node* root = NULL;
    int arr[] = {45, 25, 65, 15, 35, 55, 75};
    for (int i = 0; i < 7; i++) {
        root = insert(root, arr[i]);
    }

    cout << "Search 35: " << (search(root, 35) ? "found" : "not found") << "\n";
    cout << "Search 90: " << (search(root, 90) ? "found" : "not found") << "\n";

    return 0;
}