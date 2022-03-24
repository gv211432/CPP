
#ifndef AvlTree
#define AvlTree

//  ┏━┓╻ ╻╻     ╺┳╸┏━┓┏━╸┏━╸
//  ┣━┫┃┏┛┃      ┃ ┣┳┛┣╸ ┣╸
//  ╹ ╹┗┛ ┗━╸    ╹ ╹┗╸┗━╸┗━╸
// Alv trees are self balancing trees..

// AVL tree is a self-balancing Binary Search Tree where the difference between
// heights of left and right subtrees cannot be more than one for all nodes.

// Tree rotation is an operation that changes the structure without interfering
// with the order of the elements on an AVL tree. It moves one node up in the
// tree and one node down. It is used to change the shape of the tree, and to
// decrease its height by moving smaller subtrees down and larger subtrees up,
// resulting in improved performance of many tree operations. The direction of
// a rotation depends on the side which the tree nodes are shifted upon whilst
// others say that it depends on which child takes the root’s place. This is a
// C++ Program to Implement AVL Tree.

#include <iostream>
#include <algorithm>
using namespace std;

// this preprocessor generates the power of 2
#define pow2(n) (1 << n)

class avl_tree
{
private:
    // this is the standard structure of any node in avl tree
    struct avlNode
    {
        int d;
        avlNode *l;
        avlNode *r;
        // one root pointer for every object generated through this class
    } * rootNodePtr;
    //this pointer points to the root and its made global variable

    // only to be used by the "insert()" and "InsertNode()" to track the node insertion
    bool isNodeInserted = true;

    // height(avlNode *) : It calculate the height of the given AVL tree.
    int height(avlNode *t)
    {
        int h = 0;
        if (t != NULL)
        {
            int l_height = height(t->l);
            int r_height = height(t->r);
            int max_height = max(l_height, r_height);
            h = max_height + 1;
        }
        return h;
    };

    // difference(avlNode *): It calculate the difference between height of sub trees of given tree
    int difference(avlNode *);

    // avlNode *rr_rotat(avlNode *): A right-right rotation is a combination of right rotation followed by right rotation.
    avlNode *rr_rotat(avlNode *parent)
    {
        avlNode *t;
        t = parent->r;
        parent->r = t->l;
        t->l = parent;
        cout << "Right-Right Rotation";
        return t;
    };

    // avlNode *ll_rotat(avlNode *): A left-left rotation is a combination of left rotation followed by left rotation.
    avlNode *ll_rotat(avlNode *parent)
    {
        avlNode *t;
        t = parent->l;
        parent->l = t->r;
        t->r = parent;
        cout << "Left-Left Rotation";
        return t;
    };

    // avlNode *lr_rotat(avlNode*): A left-right rotation is a combination of left rotation followed by right rotation.
    avlNode *lr_rotat(avlNode *parent)
    {
        avlNode *t;
        t = parent->l;
        parent->l = rr_rotat(t);
        cout << "Left-Right Rotation";
        return ll_rotat(parent);
    };

    // avlNode *rl_rotat(avlNode *): It is a combination of right rotation followed by left rotation.
    avlNode *rl_rotat(avlNode *parent)
    {
        avlNode *t;
        t = parent->r;
        parent->r = ll_rotat(t);
        cout << "Right-Left Rotation";
        return rr_rotat(parent);
    };

    // avlNode * balance(avlNode *): It perform balance operation to the tree by getting balance factor
    avlNode *balance(avlNode *t)
    {
        int bal_factor = difference(t);
        if (bal_factor > 1)
        {
            if (difference(t->l) > 0)
                t = ll_rotat(t);
            else
                t = lr_rotat(t);
        }
        else if (bal_factor < -1)
        {
            if (difference(t->r) > 0)
                t = rl_rotat(t);
            else
                t = rr_rotat(t);
        }
        return t;
    };

    // avlNode * insert(avlNode*, int): It perform insert operation. Insert values in the tree using this function.
    avlNode *insert(avlNode *r, int v)
    {
        if (r == NULL)
        {
            r = new avlNode;
            r->d = v;
            r->l = NULL;
            r->r = NULL;
            return r;
        }
        else if (r->d == v)
        {
            std::cout << "Skippkig duplicate : " << r->d << std::endl;
            isNodeInserted = false;
        }
        else if (v < r->d)
        {
            r->l = insert(r->l, v);
            r = balance(r);
        }
        else if (v > r->d)
        {
            r->r = insert(r->r, v);
            r = balance(r);
        }
        return r;
    };

    // show(avlNode*, int): It display the values of the tree.
    void show(avlNode *, int);

    // inorder(avlNode *): Traverses a tree in an in-order manner.
    void inorder(avlNode *);

    // preorder(avlNode *): Traverses a tree in a pre-order manner.
    void preorder(avlNode *);

    // postorder(avlNode*): Traverses a tree in a post-order manner
    void postorder(avlNode *);

public:
    // returns the height of the tree object;
    int TreeHeight();
    // returns the balance factor of the tree object
    int TreeDifference();
    // insert the value in the tree object by creating new avlNode
    bool InsertNode(int);
    // this prints all the element of the tree object
    void ShowTree();
    // prints the tree elements in BFS mannar
    void PrintInorder();
    // prints the element instantly on encounter(obviously form root to leaf) in WFS mannar
    void PrintPreorder();
    // prints the all element of node then the parent
    void PrintPostorder();
    // returns true if no element present in the tree object
    bool IsTreeNull();

    // constructor of this class
    avl_tree()
    {
        // initailizing the rootNode pointer with null value
        rootNodePtr = NULL;
    }
};

// ====================================================================
// ====================================================================
// utility functions

int avl_tree::difference(avlNode *t)
{
    int l_height = height(t->l);
    int r_height = height(t->r);
    int b_factor = l_height - r_height;
    return b_factor;
}

void avl_tree::show(avlNode *p, int l)
{
    int i;
    if (p != NULL)
    {
        show(p->r, l + 1);
        cout << " ";
        if (p == rootNodePtr)
            cout << "Root -> ";
        for (i = 0; i < l && p != rootNodePtr; i++)
            cout << " ";
        cout << p->d;
        show(p->l, l + 1);
    }
}

void avl_tree::inorder(avlNode *t)
{
    if (t == NULL)
        return;
    inorder(t->l);
    cout << t->d << " ";
    inorder(t->r);
}

void avl_tree::preorder(avlNode *t)
{
    if (t == NULL)
        return;
    cout << t->d << " ";
    preorder(t->l);
    preorder(t->r);
}

// ====================================================================
// ====================================================================
// object property functions

int avl_tree::TreeHeight()
{
    return height(rootNodePtr);
}

int avl_tree::TreeDifference()
{
    return difference(rootNodePtr);
}

bool avl_tree::InsertNode(int value)
{
    rootNodePtr = insert(rootNodePtr, value);
    if (!isNodeInserted)
    {
        isNodeInserted = true;
        return false;
    }
    return true;
}

void avl_tree::ShowTree()
{
    show(rootNodePtr, 1);
}

void avl_tree::PrintInorder()
{
    inorder(rootNodePtr);
}

void avl_tree::PrintPreorder()
{
    preorder(rootNodePtr);
}

void avl_tree::postorder(avlNode *t)
{
    if (t == NULL)
        return;
    postorder(t->l);
    postorder(t->r);
    cout << t->d << " ";
}

void avl_tree::PrintPostorder()
{
    postorder(rootNodePtr);
}

bool avl_tree::IsTreeNull()
{
    bool res = rootNodePtr == NULL ? true : false;
    return res;
}

#endif