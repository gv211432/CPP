
// Function Descriptions:
#include <iostream>
// #include <algorithm>
#include "AvlTree.h"
using namespace std;

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
            // rootPtr = avlObj.insert(rootPtr, i);
            avlObj.InsertNode(i);
            break;
        case 2:
            if (avlObj.IsTreeNull())
            {
                cout << "Tree is Empty" << endl;
                continue;
            }
            cout << "Balanced AVL Tree:" << endl;
            // avlObj.show(rootPtr, 1);
            avlObj.ShowTree();
            cout << endl;
            break;
        case 3:
            cout << "Inorder Traversal:" << endl;
            // avlObj.inorder(rootPtr);
            avlObj.PrintInorder();
            cout << endl;
            break;
        case 4:
            cout << "Preorder Traversal:" << endl;
            // avlObj.preorder(rootPtr);
            avlObj.PrintPreorder();
            cout << endl;
            break;
        case 5:
            cout << "Postorder Traversal:" << endl;
            // avlObj.postorder(rootPtr);
            avlObj.PrintPostorder();
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