// Main file of the Project
//  #include <iostream>
#include <bits/stdc++.h>

// creating an struct for children of a node
struct Node
{
    // data of this child
    int data;
    // pointer to the left child
    struct Node *left;
    // pointer to the right child
    struct Node *right;

    // "value" is the key or data that is goint to be added to the Node
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// this function checkes the binary tree
bool isBST(Node *root, int min, int max)
{
    // Base case. An empty tree is a BST.
    if (root == NULL)
        return true;
    // Checking if a key is outside the permitted range.
    if (root->data <= min)
        return false;
    if (root->data >= max)
        return false;
    // Sending in updates ranges to the right and left subtree
    return isBST(root->right, root->data, max) &&
           isBST(root->left, min, root->data);
}

int main(int arg, char *argv[])
{
    // std::cout << "Hello " << argv[0] << " project" << std::endl;

    // inserting root in the BST
    Node *root = new Node(15);

    root->left = new Node(4);
    root->right = new Node(20);

    root->left->left = new Node(1);
    root->left->right = new Node(14);

    // std::cout << root->right->data << std::endl;
    // std::cout << root->left->data << std::endl;
    // std::cout << root->left->left->data << std::endl;
    // std::cout << root->left->right->data << std::endl;

    int min = std::numeric_limits<int>::min();
    int max = std::numeric_limits<int>::max();

    std::cout << isBST(root, min, max) << std::endl;

    return 0;
}