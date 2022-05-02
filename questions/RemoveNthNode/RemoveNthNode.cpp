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

class Solution2
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(-1, head); // creating dummy node, where next node is the head node
        ListNode *temp = dummy;                   // also putting the value of dummy in temp

        for (int i = 0; i < n; i++) // this loop will make temp to point the given index value of given ListNode
            temp = temp->next;

        if (temp->next == nullptr) // if next value of the given index is nullptr means it's last value
            return dummy->next->next;

        ListNode *slow = head, *fast = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
            slow = fast;
            fast = fast->next;
        }
        slow->next = fast->next;
        delete fast;
        return dummy->next;
    }
};

// by gaurav
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *nthLast = new ListNode(-1, head), *head2 = head;
        int i;
        for (i = 0; i < n; i++)
            head2 = head2->next;

        while (head2 != nullptr)
            nthLast = nthLast->next, head2 = head2->next, i++;

        if (i - n == 0)
            return head->next;

        nthLast->next = nthLast->next->next;
        return head;
    }
};

void PrintListNode(ListNode *head, size_t n = 0)
{
    // for (size_t i = 0; i < n; i++)
    // {
    //     std::cout << head->val << std::endl;
    //     head = head->next;
    // }

    // std::cout << n << std::endl;
    std::cout << "[ ";
    while (n)
    {
        std::cout << head->val;
        head = head->next;
        (n - 1) ? std::cout << ", " : std::cout << " ";
        n--;
    }
    std::cout << "]" << std::endl;
}

int main(int arg, char *argv[])
{
    Solution s;

    ListNode *head = s.removeNthFromEnd(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode()))))), 3);
    PrintListNode(head, 4);

    PrintListNode(s.removeNthFromEnd(new ListNode(1, nullptr), 1));
    // std::cout << s.removeNthFromEnd(new ListNode(1, new ListNode(2, nullptr)), 1)->val << std::endl;
    PrintListNode(s.removeNthFromEnd(new ListNode(1, new ListNode(2, nullptr)), 2), 1);
    return 0;
}