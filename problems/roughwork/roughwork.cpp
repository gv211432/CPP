// Main file of the Project
#include <bits/stdc++.h>

using namespace std;

int main(int arg, char *argv[])
{
    int a = 'a';
    char any = 97;
    std::cout << a << std::endl;
    std::cout << any << std::endl;

    struct node
    {
        int x;
        node *l;
    };

    class QueueNode
    {
    public:
        char data;
        unsigned freq;
        QueueNode *left, *right;
    };

    node *temp = new node[sizeof(node)];

    std::cout << sizeof(node[6]) << std::endl;

    std::cout << "multiplying : " << sizeof(node) * sizeof(node) << std::endl;

    std::cout << sizeof(node) << std::endl;

    std::cout << sizeof(new QueueNode[sizeof(QueueNode)]) << std::endl;

    // node *me = new node;

    // std::stringstream ss;

    // ss << (*me).x;

    // string place = ss.str();

    // // string ptr = &me;

    // std::cout << &me << std::endl;

    // std::cout << me << std::endl;

    // std::cout << &((*me).x) << std::endl;

    // int n = 27;

    // int *nPtr = &n;

    // stringstream ss;
    // ss << &n;

    // std::cout << &n << std::endl;

    // std::cout << nPtr << std::endl;

    // std::cout << &nPtr << std::endl;

    // std::cout << ss.str() << std::endl;

    return 0;
}
