#include <iostream>
using namespace std;

enum Color {RED, BLACK};

class Node
{
public:
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int data)
    {
        this->data = data;
        color = RED;
        left = right = parent = NULL;
    }
};

class RBTree
{
private:
    Node* root;

    void rotateLeft(Node*& root, Node*& pt)
    {
        Node* pt_right = pt->right;

        pt->right = pt_right->left;

        if(pt->right != NULL)
            pt->right->parent = pt;

        pt_right->parent = pt->parent;

        if(pt->parent == NULL)
            root = pt_right;

        else if(pt == pt->parent->left)
            pt->parent->left = pt_right;

        else
            pt->parent->right = pt_right;

        pt_right->left = pt;
        pt->parent = pt_right;
    }

    void rotateRight(Node*& root, Node*& pt)
    {
        Node* pt_left = pt->left;

        pt->left = pt_left->right;

        if(pt->left != NULL)
            pt->left->parent = pt;

        pt_left->parent = pt->parent;

        if(pt->parent == NULL)
            root = pt_left;

        else if(pt == pt->parent->left)
            pt->parent->left = pt_left;

        else
            pt->parent->right = pt_left;

        pt_left->right = pt;
        pt->parent = pt_left;
    }