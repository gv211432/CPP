// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

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
public:
    void reorderList(ListNode *head)
    {
        ListNode *slow = head, *fast = head->next;
        // bringing the slow pointer in the middle of the linked
        // list by fast and slow pointer technique
        while (fast != nullptr and fast->next != nullptr)
            slow = slow->next, fast = fast->next->next;

        ListNode *second = slow->next;         // this is second part of the list to be reversed
        ListNode *prev = slow->next = nullptr; // cutting the list in two parts now

        // reversing the linked list by interation method
        while (second != nullptr)
        {
            ListNode *tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;
        }

        ListNode *first = head; // this is head of one first list
        second = prev;          // this is head of second reversed list
        // now merging both of these lists
        while (second != nullptr) // second list may be smaller than first or equal
        {
            ListNode *tmp1 = first->next, *tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1, second = tmp2;
        }
    }

    void reorderList2(ListNode *head)
    {
        // Using slow and fast pointer method for pointing slow at the middle of the list
        ListNode *slow = head, *fast = head;              // increment slow by one and fast by two steps
        while (fast != nullptr and fast->next != nullptr) // stop when fast or fast->next goes null
            slow = slow->next, fast = fast->next->next;

        // Now reversing the second half part of the list
        // now take slow as current node and null pointer as previous
        ListNode *curr = slow, *prv = nullptr;
        while (curr != nullptr)
        {
            auto *tmp = curr->next;
            curr->next = prv;
            prv = curr;
            curr = tmp;
        }
        // now second part is reversed and prv is pointing to its head
        // take second as head of reversed list and first as head itself
        ListNode *second = prv, *first = head;

        // reordering as required and stop when second or second->next goes null
        while (second != nullptr and second->next != nullptr)
        {
            auto *tmp1 = first->next, *tmp2 = second->next;
            first->next = second;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6))))));

    PrintListNode(head, "31");
    s.reorderList2(head);
    PrintListNode(head, "32");
    return 0;
}