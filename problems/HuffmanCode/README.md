<!-- ┏━┓╻  ╻   ┏━┓┏┓ ┏━┓╻ ╻╺┳╸   ╻ ╻╻ ╻┏━╸┏━╸┏┳┓┏━┓┏┓╻┏━╸┏━┓╺┳┓┏━╸
     ┣━┫┃  ┃   ┣━┫┣┻┓┃ ┃┃ ┃ ┃    ┣━┫┃ ┃┣╸ ┣╸ ┃┃┃┣━┫┃┗┫┃  ┃ ┃ ┃┃┣╸
     ╹ ╹┗━╸┗━╸ ╹ ╹┗━┛┗━┛┗━┛ ╹    ╹ ╹┗━┛╹  ╹  ╹ ╹╹ ╹╹ ╹┗━╸┗━┛╺┻┛┗━╸ -->

Huffman Coding | Greedy Algo-3

    Difficulty Level : Hard
    Last Updated : 24 Nov, 2021

Huffman coding is a lossless data compression algorithm. The idea is to assign variable-length codes to input characters, lengths of the assigned codes are based on the frequencies of corresponding characters. The most frequent character gets the smallest code and the least frequent character gets the largest code.
The variable-length codes assigned to input characters are Prefix Codes, means the codes (bit sequences) are assigned in such a way that the code assigned to one character is not the prefix of code assigned to any other character. This is how Huffman Coding makes sure that there is no ambiguity when decoding the generated bitstream.
Let us understand prefix codes with a counter example. Let there be four characters a, b, c and d, and their corresponding variable length codes be 00, 01, 0 and 1. This coding leads to ambiguity because code assigned to c is the prefix of codes assigned to a and b. If the compressed bit stream is 0001, the de-compressed output may be “cccd” or “ccb” or “acd” or “ab”.
See this for applications of Huffman Coding.
There are mainly two major parts in Huffman Coding

    Build a Huffman Tree from input characters.
    Traverse the Huffman Tree and assign codes to characters.

Steps to build Huffman Tree
Input is an array of unique characters along with their frequency of occurrences and output is Huffman Tree.

    Create a leaf node for each unique character and build a min heap of all leaf nodes (Min Heap is used as a priority queue. The value of frequency field is used to compare two nodes in min heap. Initially, the least frequent character is at root)
    Extract two nodes with the minimum frequency from the min heap.

    Create a new internal node with a frequency equal to the sum of the two nodes frequencies. Make the first extracted node as its left child and the other extracted node as its right child. Add this node to the min heap.
    Repeat steps#2 and #3 until the heap contains only one node. The remaining node is the root node and the tree is complete.
    Let us understand the algorithm with an example:

character Frequency
a 5
b 9
c 12
d 13
e 16
f 45

Step 1. Build a min heap that contains 6 nodes where each node represents root of a tree with single node.

Step 2 Extract two minimum frequency nodes from min heap. Add a new internal node with frequency 5 + 9 = 14.

Huffman Coding step 2

Now min heap contains 5 nodes where 4 nodes are roots of trees with single element each, and one heap node is root of tree with 3 elements

character Frequency
c 12
d 13
Internal Node 14
e 16
f 45

Step 3: Extract two minimum frequency nodes from heap. Add a new internal node with frequency 12 + 13 = 25

Huffman Coding step 3

Now min heap contains 4 nodes where 2 nodes are roots of trees with single element each, and two heap nodes are root of tree with more than one nodes

character Frequency
Internal Node 14
e 16
Internal Node 25
f 45

Step 4: Extract two minimum frequency nodes. Add a new internal node with frequency 14 + 16 = 30

Huffman Coding step 4

Now min heap contains 3 nodes.

character Frequency
Internal Node 25
Internal Node 30
f 45

Step 5: Extract two minimum frequency nodes. Add a new internal node with frequency 25 + 30 = 55

Huffman Coding step 5

Now min heap contains 2 nodes.

character Frequency
f 45
Internal Node 55

Step 6: Extract two minimum frequency nodes. Add a new internal node with frequency 45 + 55 = 100

Huffman Coding step 6

Now min heap contains only one node.

character Frequency
Internal Node 100

Since the heap contains only one node, the algorithm stops here.

Steps to print codes from Huffman Tree:
Traverse the tree formed starting from the root. Maintain an auxiliary array. While moving to the left child, write 0 to the array. While moving to the right child, write 1 to the array. Print the array when a leaf node is encountered.

Steps to print codes from Huffman Tree

The codes are as follows:

character code-word
f 0
c 100
d 101
a 1100
b 1101
e 111

Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.

Below is the implementation of above approach:

<!-- ===================================================================== -->

// C++(STL) program for Huffman Coding with STL
#include <bits/stdc++.h>
using namespace std;

// A Huffman tree node
struct MinHeapNode {

    // One of the input characters
    char data;

    // Frequency of the character
    unsigned freq;

    // Left and right child
    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned freq)

    {

        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }

};

// For comparison of
// two heap nodes (needed in min heap)
struct compare {

    bool operator()(MinHeapNode* l, MinHeapNode* r)

    {
        return (l->freq > r->freq);
    }

};

// Prints huffman codes from
// the root of Huffman Tree.
void printCodes(struct MinHeapNode\* root, string str)
{

    if (!root)
        return;

    if (root->data != '$')
        cout << root->data << ": " << str << "\n";

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");

}

// The main function that builds a Huffman Tree and
// print codes by traversing the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size)
{
struct MinHeapNode *left, *right, \*top;

    // Create a min heap & inserts all characters of data[]
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));

    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1) {

        // Extract the two minimum
        // freq items from min heap
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with
        // frequency equal to the sum of the
        // two nodes frequencies. Make the
        // two extracted node as left and right children
        // of this new node. Add this node
        // to the min heap '$' is a special value
        // for internal nodes, not used
        top = new MinHeapNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    // Print Huffman codes using
    // the Huffman tree built above
    printCodes(minHeap.top(), "");

}

// Driver Code
int main()
{

    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };

    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, size);

    return 0;

}

<!-- ===================================================================== -->

// This code is contributed by Aditya Goel

Output:

f: 0
c: 100
d: 101
a: 1100
b: 1101
e: 111

<!-- ===================================================================== -->

Time complexity: O(nlogn) where n is the number of unique characters. If there are n nodes, extractMin() is called 2\*(n – 1) times. extractMin() takes O(logn) time as it calles minHeapify(). So, overall complexity is O(nlogn).
If the input array is sorted, there exists a linear time algorithm. We will soon be discussing in our next post.
Applications of Huffman Coding:

    They are used for transmitting fax and text.
    They are used by conventional compression formats like PKZIP, GZIP, etc.

It is useful in cases where there is a series of frequently occurring characters.

Reference:
http://en.wikipedia.org/wiki/Huffman_coding
This article is compiled by Aashish Barnwal and reviewed by GeeksforGeeks team. Please write comments if you find anything incorrect, or you want to share more information about the topic discussed above.
