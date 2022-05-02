// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

// debug accepted
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// by gaurav
class Solution // harmless (Preservs the given lists)
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *end = new ListNode(0, nullptr); // creating a head to push new sorted elements
        ListNode *head = end;                     // head will point the start of the list and end will keep pointing the last elements

        // traverse till one or both goes empty, while doing this keep updating the points as required
        while (list1 != nullptr && list2 != nullptr)
            if (list1->val <= list2->val)
                end->next = new ListNode(list1->val, nullptr), list1 = list1->next, end = end->next;
            else
                end->next = new ListNode(list2->val, nullptr), list2 = list2->next, end = end->next;

        // push the remaing element in the new list
        while (list1 != nullptr)
            end->next = new ListNode(list1->val, nullptr), list1 = list1->next, end = end->next;

        while (list2 != nullptr)
            end->next = new ListNode(list2->val, nullptr), list2 = list2->next, end = end->next;

        // return the new sored list, first element is dummy one;
        return head->next;
    }
};

class Solution2 // teases the given lists
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) // O(m+n)
    {
        ListNode *ans = NULL;
        // Base cases
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;
        // puts the sorted elements in the given list itself which ever first turns out to be have smaller element
        // recursively sorting the elements
        if (list1->val <= list2->val)
            ans = list1, ans->next = mergeTwoLists(list1->next, list2);
        else
            ans = list2, ans->next = mergeTwoLists(list1, list2->next);

        return ans;
    }
};

void PrintListNode(ListNode *l)
{
    std::cout << "[ ";
    while (l != nullptr)
        std::cout << l->val, l = l->next, l != nullptr ? cout << ", " : cout << " ";
    std::cout << "]" << std::endl;
}

int main(int arg, char *argv[])
{
    Solution s;
    ListNode *l1 = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(7, nullptr)))));
    ListNode *l2 = new ListNode(4, new ListNode(4, new ListNode(7, new ListNode(9, new ListNode(17, new ListNode(20, nullptr))))));

    PrintListNode(s.mergeTwoLists(l1, l2));
    PrintListNode(l1);
    PrintListNode(l2);
    return 0;
}