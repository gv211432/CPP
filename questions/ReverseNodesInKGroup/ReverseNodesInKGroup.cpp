// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
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

int getLen(ListNode *head)
{
    int len = 0;
    while (head)
        head = head->next, len++;
    return len;
}

class Solution
{
public:
    // ListNode *recurse(ListNode *head, int k, ListNode &end, int acc = 1)
    // {
    //     ListNode *new_head = head;
    //     if (head->next != nullptr and acc < k)
    //     {
    //         new_head = recurse(head->next, k, end, acc + 1);
    //         head->next->next = head;
    //     }
    //     head->next = &end;
    //     return new_head;
    // }

    ListNode *loop(ListNode *head, int i, int k, int n)
    {
        if (i == n)
            return head;

        ListNode *prev = nullptr, *dum = head, *curr = head, *temp = head->next;

        int t = k;
        while (t--)
        {
            temp = curr->next, curr->next = prev;
            prev = curr, curr = temp;
        }
        dum->next = loop(curr, i + 1, k, n);
        return prev;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int list_len = getLen(head);               // this is the total list length
        int no_possible_iterations = list_len / k; // no of times we can reverse the items in list

        return loop(head, 0, k, no_possible_iterations);
    }
};

int main(int arg, char *argv[])
{
    Solution s;
    ListNode *h = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6, new ListNode(7, new ListNode(8))))))));
    PrintListNode(s.reverseKGroup(h, 2));
    return 0;
}