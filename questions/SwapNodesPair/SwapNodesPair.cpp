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

// Solution2: Recursion(By myself)
class Solution2
{
    void recurse(ListNode *head) // O(N)
    {
        // at a time we are operating on three consecutive nodes, make sure all of them availble
        if (head != nullptr and head->next != nullptr and head->next->next != nullptr)
        {
            // copy two consecutive node for operations after updating them
            auto previous = head, current = head->next; // p=1, c=2
            previous->next = current->next;
            current->next = previous->next->next;
            previous->next->next = current;
            recurse(current);
        }
    }

public:
    ListNode *swapPairs(ListNode *head)
    {
        auto front = new ListNode(0, head);
        recurse(front);
        return front->next;
    }
};

int main(int arg, char *argv[])
{
    // Solution s;

    // ListNode *l = new ListNode(3, new ListNode(1, new ListNode(43, new ListNode(98, new ListNode(24, new ListNode(16, nullptr))))));
    // s.swapPairs(l);

    ListNode *head = new ListNode(3);
    ListNode *new_head = head;

    std::cout << "head: " << head->val << " head add:" << &head << " head->next:" << head->next << std::endl;
    std::cout << "new_head: " << new_head->val << " new_head add:" << &new_head << " new_head->next:" << new_head->next << std::endl;

    std::cout << "\033[31m"
              << "head: " << head << "\033[0m" << std::endl;
    std::cout << "\033[32m"
              << "new_head: " << new_head << "\033[0m" << std::endl;

    head->next = new ListNode(9);

    std::cout << "head->val: " << &head->next->val << std::endl;
    std::cout << "new_head->val: " << &new_head->next->val << std::endl;

    return 0;
}