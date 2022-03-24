#include <bits/stdc++.h>
using namespace std;

// this is the node structure for Huffman tree
struct Node
{
    char data;
    size_t frequency;

    Node *left, *right;

    Node(char data, size_t f)
    {
        left = right = NULL;
        this->data = data;
        this->frequency = f;
    }
};

// this code prints Huffman codes for the given characters
void printNode(Node *root, string str)
{
    if (!root)
        return;
    else if (root->data != '$')
        std::cout << root->data << " => " << str << std::endl;

    // if tree goes to left side add 0 in huffman code and vice versa for right node
    printNode(root->left, (str + '0'));
    printNode(root->right, (str + '1'));
}

struct compareNode
{
    bool operator()(Node *x, Node *y)
    {
        return (x->frequency > y->frequency);
    }
};

void HuffmanCode(char data[], size_t freq[], size_t len)
{
    Node *left, *right, *top;

    priority_queue<Node *, vector<Node *>, compareNode> min_heap;

    for (size_t i = 0; i < len; i++)
    {
        min_heap.push(new Node(data[i], freq[i]));
    }

    while (min_heap.size() != 1)
    {
        left = min_heap.top();
        min_heap.pop();

        right = min_heap.top();
        min_heap.pop();

        top = new Node('$', (left->frequency + right->frequency));

        top->left = left;
        top->right = right;

        std::cout << left->data << ", " << right->data << ", ";

        min_heap.push(top);
    }
    std::cout << std::endl;

    printNode(top, " ");
}

// Drive code
int main()

{

    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    size_t freq[] = {5, 9, 12, 13, 16, 45};

    size_t size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCode(arr, freq, size);

    return 0;
}