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

// Function Descriptions:

#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
using namespace std;

// this preprocessor generates the power of 2
#define pow2(n) (1 << n)

// this is the standard structure of any node in avl tree
struct avlNode
{
    int d;
    avlNode *l;
    avlNode *r;
} * rootPtr; //this pointer points to the root and its made global variable

class avl_tree
{
public:
    // height(avlNode *) : It calculate the height of the given AVL tree.
    int height(avlNode *);

    // difference(avlNode *): It calculate the difference between height of sub trees of given tree
    int difference(avlNode *);

    // avlNode *rr_rotat(avlNode *): A right-right rotation is a combination of right rotation followed by right rotation.
    avlNode *rr_rotat(avlNode *);

    // avlNode *ll_rotat(avlNode *): A left-left rotation is a combination of left rotation followed by left rotation.
    avlNode *ll_rotat(avlNode *);

    // avlNode *lr_rotat(avlNode*): A left-right rotation is a combination of left rotation followed by right rotation.
    avlNode *lr_rotat(avlNode *);

    // avlNode *rl_rotat(avlNode *): It is a combination of right rotation followed by left rotation.
    avlNode *rl_rotat(avlNode *);

    // avlNode * balance(avlNode *): It perform balance operation to the tree by getting balance factor
    avlNode *balance(avlNode *);

    // avlNode * insert(avlNode*, int): It perform insert operation. Insert values in the tree using this function.
    avlNode *insert(avlNode *, int);

    // show(avlNode*, int): It display the values of the tree.
    void show(avlNode *, int);

    // inorder(avlNode *): Traverses a tree in an in-order manner.
    void inorder(avlNode *);

    // preorder(avlNode *): Traverses a tree in a pre-order manner.
    void preorder(avlNode *);

    // postorder(avlNode*): Traverses a tree in a post-order manner
    void postorder(avlNode *);

    avl_tree()
    {
        rootPtr = NULL;
    }
};

int avl_tree::height(avlNode *t)
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
}

int avl_tree::difference(avlNode *t)
{
    int l_height = height(t->l);
    int r_height = height(t->r);
    int b_factor = l_height - r_height;
    return b_factor;
}

avlNode *avl_tree::rr_rotat(avlNode *parent)
{
    avlNode *t;
    t = parent->r;
    parent->r = t->l;
    t->l = parent;
    cout << "Right-Right Rotation";
    return t;
}
avlNode *avl_tree::ll_rotat(avlNode *parent)
{
    avlNode *t;
    t = parent->l;
    parent->l = t->r;
    t->r = parent;
    cout << "Left-Left Rotation";
    return t;
}
avlNode *avl_tree::lr_rotat(avlNode *parent)
{
    avlNode *t;
    t = parent->l;
    parent->l = rr_rotat(t);
    cout << "Left-Right Rotation";
    return ll_rotat(parent);
}
avlNode *avl_tree::rl_rotat(avlNode *parent)
{
    avlNode *t;
    t = parent->r;
    parent->r = ll_rotat(t);
    cout << "Right-Left Rotation";
    return rr_rotat(parent);
}
avlNode *avl_tree::balance(avlNode *t)
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
}
avlNode *avl_tree::insert(avlNode *r, int v)
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
}
void avl_tree::show(avlNode *p, int l)
{
    int i;
    if (p != NULL)
    {
        show(p->r, l + 1);
        cout << " ";
        if (p == rootPtr)
            cout << "Root -> ";
        for (i = 0; i < l && p != rootPtr; i++)
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
void avl_tree::postorder(avlNode *t)
{
    if (t == NULL)
        return;
    postorder(t->l);
    postorder(t->r);
    cout << t->d << " ";
}
int main()
{
    int c, i;
    //This is the only object created using avl_tree class (only one tree in this program)
    avl_tree avlObj;
    while (1)
    {
        cout << "1.Insert Element into the tree" << endl;
        cout << "2.show Balanced AVL Tree" << endl;
        cout << "3.InOrder traversal" << endl;
        cout << "4.PreOrder traversal" << endl;
        cout << "5.PostOrder traversal" << endl;
        cout << "6.Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "Enter value to be inserted: ";
            cin >> i;
            rootPtr = avlObj.insert(rootPtr, i);
            break;
        case 2:
            if (rootPtr == NULL)
            {
                cout << "Tree is Empty" << endl;
                continue;
            }
            cout << "Balanced AVL Tree:" << endl;
            avlObj.show(rootPtr, 1);
            cout << endl;
            break;
        case 3:
            cout << "Inorder Traversal:" << endl;
            avlObj.inorder(rootPtr);
            cout << endl;
            break;
        case 4:
            cout << "Preorder Traversal:" << endl;
            avlObj.preorder(rootPtr);
            cout << endl;
            break;
        case 5:
            cout << "Postorder Traversal:" << endl;
            avlObj.postorder(rootPtr);
            cout << endl;
            break;
        case 6:
            exit(1);
            break;
        default:
            cout << "Wrong Choice" << endl;
        }
    }
    return 0;
}