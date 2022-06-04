// Main file of the Project
#include <bits/stdc++.h>
#include "../utilities/utilities.h"
using namespace std;

// #define ListNode leetcode::List_Node::ListNode;

// // Self made
// class Solution
// {
// public:
//     ListNode *removeElements(ListNode *head, int val) // Time O(N)
//     {
//         if (head == nullptr)
//             return head;

//         while (head->val == val)
//         {
//             head = head->next;
//             if (head == nullptr)
//                 return nullptr;
//         }

//         auto *prv = head, *curr = head->next;
//         while (curr != nullptr)
//         {
//             while (curr != nullptr and curr->val == val)
//                 curr = curr->next;
//             prv->next = curr;
//             prv = curr;
//             curr = (curr == nullptr) ? nullptr : curr->next;
//         }
//         return head;
//     }
// };

int main(int arg, char *argv[])
{
    // Solution s;
    // ListNode *h = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(5))))));
    // PrintListNode(h, "41");
    // PrintListNode(s.removeElements(h, 1));

    vector<int> v = {6, 1, 2, 5, 90, 34, 45, 6};
    // auto *head = GenerateListNode(v);
    // PrintListNode(s.removeElements(head, 6));

    leetcode::Print.print_vov(v);
    leetcode::Box.Box_2(v);
    return 0;
}