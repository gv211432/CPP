#ifndef ListNode_gaurav
#define ListNode_gaurav

namespace list_node
{
#include <iostream>
#include <vector>
    // struct for ListNode
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    class List_Node
    {
    public:
        // This prints the Nodes of ListNode Struct
        // PrintListNode(ListNode *head_pointer, std::string color_code_linux_teminal)
        // Eg: "31":Red, "32":Green, "33":Yellow, "34":"Blue", etc.. "41":BG_Red, "42":BG_Green, etc..
        void PrintListNode(ListNode *h, std::string color = "0")
        {
            std::cout << "\033[" << color << "m ListNode[ ";
            while (h != nullptr)
                std::cout << h->val << ", ", h = h->next;
            std::cout << "nullptr ] \033[0m" << std::endl;
        }

        // Generates the ListNode List and returns *head pointer
        // ListNode *generatrListNode(vector<int> &vector)
        ListNode *GenerateListNode(std::vector<int> &v)
        {
            ListNode *h = new ListNode();
            auto *head = h;
            for (auto n : v)
                h->next = new ListNode(n), h = h->next;
            return head->next;
        }

        // Generates the ListNode List, with given array
        // ListNode *GenerateListNode(arr, number of elements in arr)
        ListNode *GenerateListNode(int *v, int n)
        {
            ListNode *h = new ListNode();
            auto *head = h;
            for (size_t i = 0; i < n; i++)
                h->next = new ListNode(*(v + i)), h = h->next;
            return head->next;
        }
    };
}

#endif