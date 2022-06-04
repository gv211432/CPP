// Main file of the Project
// debug This is accepted by leet code
#include <bits/stdc++.h>
using namespace std;

// following is the struct for a list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// this function prints the list nodes
void printList(ListNode *l)
{
    // creating a temperory curr ListNode for referencing the next node once the current node is used
    // helps looping the values of the nodes
    ListNode *curr = l;

    std::cout << "[ ";
    while (curr != nullptr)
    {
        std::cout << curr->val;
        (curr->next != nullptr) ? cout << ", " : cout << " ";
        curr = curr->next;
    }
    std::cout << "]" << std::endl;
}

// class Solution
// {
//     // this will store the carray generated during the operations
//     int carray = 0;

//     // this pointer points to the front of the list
//     ListNode *front;
//     // this pointer points to the last node of the list
//     ListNode *last;

// public:
//     ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
//     {
//         // printList(l1);
//         // printList(l2);

//         // creating dummy ListNodes
//         ListNode *currL1 = l1, *currL2 = l2;

//         ListNode *newNode = new ListNode();
//         front = last = newNode;

//         while (currL1 || currL2)
//         {
//             // this will hold the addition results for each iteration
//             int temp = 0;

//             // some conditional operations
//             // this helps, prevent accessing the uninitialized pointers(segmentation fault)
//             if (currL1 == nullptr)
//             {
//                 // we can not access currL1->next pointer, as it is not initialized
//                 // not initialized means (no mapping of virtual address of variable in operating system to physical location)
//                 temp = carray + currL2->val;
//                 currL2 = currL2->next;
//             }
//             else if (currL2 == nullptr)
//             {
//                 // same as above for currL2
//                 temp = carray + currL1->val;
//                 currL1 = currL1->next;
//             }
//             else
//             {
//                 // if both's next varable is initalized
//                 temp = carray + currL1->val + currL2->val;

//                 // updating the current list nodes with their next nodes
//                 currL2 = currL2->next;
//                 currL1 = currL1->next;
//             }

//             std::cout << "Value is : " << temp % 10 << std::endl;
//             std::cout << "Carray is : " << temp / 10 << std::endl;

//             // update the carray variable with new value
//             carray = temp / 10;

//             // update the val variable of the last ListNode
//             last->val = (temp % 10);

//             //  if this is last iteration, we will stop here to prevent some operation in last iteration
//             if (currL1 == nullptr && currL2 == nullptr && !carray)
//                 break;

//             // we should not add new node in last iteration as it will increse the list size
//             ListNode *n = new ListNode();
//             last->next = n;
//             last = n;
//         };

//         if (carray)
//             last->val = carray;

//         // printList(front);

//         return front;
//     }
// };

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummyHead = new ListNode(0);        // declaring new list
        ListNode *p = l1, *q = l2, *curr = dummyHead; // copying head pointers of all three lists above
        int carry = 0;                                // let the initial carry be 0

        while (p != nullptr || q != nullptr) // iterate till both lists get exhausted
        {
            int x = (p != nullptr ? p->val : 0); // if no node found take value as 0
            int y = (q != nullptr ? q->val : 0);
            int sum = (carry + x + y); // generating sum by adding two numbers and previous carry

            carry = (sum / 10);                  // put the carry in carry
            curr->next = new ListNode(sum % 10); // load the unit place value of sum in new list node
            curr = curr->next;                   // make the new list node the current node

            if (p != nullptr) // if next pointer exist, then update or left unchanged
                p = p->next;
            if (q != nullptr)
                q = q->next;
        }

        if (carry > 0) // if still carry exits laod it in new list nodewwew
            curr->next = new ListNode(carry);

        printList(dummyHead->next);

        return dummyHead->next;
    }
};

int main(int arg, char *argv[])
{
    ListNode *l1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, nullptr))))));
    ListNode *l2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(0, nullptr))))))))))));

    Solution s;
    s.addTwoNumbers(l1, l2);
    return 0;
}