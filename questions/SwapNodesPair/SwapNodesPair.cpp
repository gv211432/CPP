// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void PrintListNode(ListNode *h)
{
    std::cout << "[ ";
    while (h != nullptr)
    {
        std::cout << h->val;
        (h->next == nullptr) ? cout << " " : cout << ", ";
        h = h->next;
    }
    std::cout << "]" << std::endl;
}

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        PrintListNode(head);
        if (head == nullptr or head->next == nullptr)
            return head;

        auto front = new ListNode(0, head);
        auto previous = front, current = head;

        while (current != nullptr and current->next != nullptr)
        {
            previous->next = current->next;
            current->next = previous->next->next;
            previous->next->next = current;

            previous = current;
            current = current->next;
        }

        PrintListNode(front->next);
        return front->next;
    }
};

int main(int arg, char *argv[])
{
    Solution s;

    ListNode *l = new ListNode(3, new ListNode(1, new ListNode(43, new ListNode(98, new ListNode(24, new ListNode(16, nullptr))))));
    s.swapPairs(l);
    return 0;
}