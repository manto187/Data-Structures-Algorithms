#include<iostream>
#include<vector> 
using namespace std;

struct Node{
    int data;
    vector<Node*> children;

    Node(int value){
        data=value;
    }
};

void printTree(Node* root){
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    for(Node* child : root->children){
        printTree(child);
    }
}

int main(){
    Node* root = new Node(1);

    Node* child1 = new Node(2);
    Node* child2 = new Node(3);
    Node* child3 = new Node(4);

    root->children.push_back(child1);
    root->children.push_back(child2);
    root->children.push_back(child3);

    child1->children.push_back(new Node(5));
    child1->children.push_back(new Node(6));

    cout<<" tree traversal: ";
    printTree(root);
    return 0;
}