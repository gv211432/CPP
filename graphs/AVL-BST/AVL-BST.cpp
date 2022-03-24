//Main file of the Project
#include <iostream>
#include <bits/stdc++.h>

// standard structure of a node
struct node
{
    int data;
    node *left = NULL;
    node *right = NULL;
};

std::vector<int> elementLeftToTop;

// function to genreate new nodes
node *generateNode(int data)
{
    node *root = new node();
    root->data = data;
    root->left = root->right = NULL;
    return root;
}

// this will print the tree form left to top
void printLeftToTop(node *root)
{
    if (root->left != NULL)
    {
        printLeftToTop(root->left);
    }

    if (root->right != NULL)
    {
        printLeftToTop(root->right);
    }
    std::cout << root->data << " ";
    elementLeftToTop.push_back(root->data);
}

// prints all the element in the tree for left to right
void printNode(node *root)
{
    if (root->left != NULL)
    {
        printNode(root->left);
    }
    std::cout << root->data << " ";

    if (root->right != NULL)
    {
        printNode(root->right);
    }
}

// searchs for a perticula key and returns the address of it
node *search(node **root, int key)
{
    if (*root == NULL)
        return *root;
    else if ((*root)->data == key)
        return *root;
    else if (key <= (*root)->data)
        return search(&(*root)->left, key);
    else
        return search(&(*root)->right, key);
}

// this function finds the maximum height of the tree
int treeHeight(node **root)
{
    if (*root == NULL)
        return -1;
    else
    {
        int leftDepth = treeHeight(&(*root)->left);
        int rightDepth = treeHeight(&(*root)->right);
        if (leftDepth > rightDepth)
            return (leftDepth + 1);
        else
            return (rightDepth + 1);
    }
}

// this function will find out the difference between the height of both child
int ChildDifference(node **root)
{
    int leftHeight = treeHeight(&(*root)->left);
    int rightHeight = treeHeight(&(*root)->right);
    int diff = leftHeight - rightHeight;
    return diff;
}

// this function rotates the nodes
node *RR_rotation(node *parent)
{
    node *current;
    current = (parent)->right;
    (parent)->right = current->left;
    current->left = (parent);
    return current;
}

// this function rotates the nodes
node *LL_rotation(node *parent)
{
    node *current;
    current = (parent)->left;
    (parent)->left = current->right;
    current->right = (parent);
    return current;
}

// this function rotates the nodes
node *RL_rotation(node *parent)
{
    node *current;
    current = (parent)->right;
    (parent)->right = LL_rotation(current);
    return (RR_rotation(current));
}

// this function rotates the nodes
node *LR_rotation(node *parent)
{
    node *current;
    current = (parent)->left;
    (parent)->left = RR_rotation(current);
    return (LL_rotation(current));
}

// this funtion will balance the tree
void balance(node *root)
{
    int getBalance = ChildDifference(&root);
    if (getBalance > 1)
    {
        if (ChildDifference(&(root)->left) > 0)
            LL_rotation(&*root);
        else
            LR_rotation(&*root);
    }
    else if (getBalance < -1)
    {
        if (ChildDifference(&(root)->right) > 0)
            RL_rotation(&*root);
        else
            RR_rotation(&*root);
    }
}

// a function to insert the key in the BST
void insert(node **root, int dataToInsert)
{
    if (*root == NULL)
    {
        // std::cout << "root is null" << std::endl;
        *root = generateNode(dataToInsert);
    }
    else if (dataToInsert == (*root)->data)
    {
        std::cout << "Skipping Duplicate " << (*root)->data << std::endl;
    }
    else if (dataToInsert <= (*root)->data)
    {
        insert(&(*root)->left, dataToInsert);
        // balance(*root);
    }
    else
    {
        insert(&(*root)->right, dataToInsert);
        // balance(*root);
    }
}

int main(int arg, char *argv[])
{
    node *BST = NULL;
    insert(&BST, 50);
    insert(&BST, 60);
    insert(&BST, 70);
    insert(&BST, 70);
    insert(&BST, 77);
    insert(&BST, 30);
    insert(&BST, 33);
    insert(&BST, 34);
    insert(&BST, 37);
    insert(&BST, 56);
    insert(&BST, 67);
    insert(&BST, 90);
    insert(&BST, 100);
    insert(&BST, 110);
    insert(&BST, 800);
    insert(&BST, 2);
    insert(&BST, 1);

    printNode(BST);
    std::cout << "\n"
              << std::endl;

    // printLeftToTop(BST);
    // std::cout << "\n"
    //           << std::endl;

    // std::cout << "Inter the key you want -> ";
    // int keyTofound = 0;
    // std::cin >> keyTofound;
    // node *res = search(&BST, keyTofound);

    // if (res != NULL)
    // {
    //     std::cout << "Found key is : " << res->data << " with address " << &res->data << std::endl;
    // }
    // else
    // {
    //     std::cout << "Key not found!!" << std::endl;
    // }

    std::cout
        << "Height of the BST is : " << treeHeight(&BST) << std::endl;

    std::cout << "Balance factor : " << ChildDifference(&BST) << std::endl;

    return 0;
}
