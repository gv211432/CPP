// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void PrintListNode(ListNode *h, string color = "0")
{
    std::cout << "\033[" << color << "m"
              << "[ ";
    while (h != nullptr)
        cout << h->val << ", ", h = h->next;
    std::cout << "nullptr ]"
              << "\033[0m" << std::endl;
}

class Solution
{

    ListNode *recurse(ListNode *head)
    {
        ListNode *new_head = head;
        if (head->next != nullptr)
            new_head = recurse(head->next),
            head->next->next = head;
        head->next = nullptr;
        return new_head;
    }

public:
    ListNode *reverseList(ListNode *head)
    {
        return recurse(head);
    }

    ListNode *reverseList2(ListNode *head)
    {
        ListNode *prv = nullptr, *curr = head;

        // PrintListNode(curr);
        while (curr != nullptr)
        {
            auto *tmp = curr->next;
            curr->next = prv;
            prv = curr;
            curr = tmp;
        }
        // PrintListNode(prv);

        return prv;
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6))))));
    // s.reverseList(head);
    PrintListNode(s.reverseList2(head));

    return 0;
}