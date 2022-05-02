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

// this function prints all the element in linked to l
void PrintNode(ListNode *l)
{
    std::cout << "[ ";
    while (l != nullptr)
    {
        std::cout << l->val;
        l->next == nullptr ? cout << " " : cout << ", ";
        l = l->next;
    }
    std::cout << "]" << std::endl;
}

// this will merge the given listnodes in the new space and return the head
ListNode *ListMerge(ListNode *a, ListNode *b)
{
    ListNode *front = new ListNode(0, nullptr);
    ListNode *end = front;

    while (a != nullptr and b != nullptr)
    {
        if (a->val <= b->val)
        {
            end->next = new ListNode(a->val, nullptr);
            a = a->next;
        }
        else
        {
            end->next = new ListNode(b->val, nullptr);
            b = b->next;
        }
        end = end->next;
    }

    while (a != nullptr)
    {
        end->next = new ListNode(a->val, nullptr);
        a = a->next;
        end = end->next;
    }

    while (b != nullptr)
    {
        end->next = new ListNode(b->val, nullptr);
        b = b->next;
        end = end->next;
    }

    // PrintNode(front->next);
    return front->next;
}

// this class helps to decide how to sort the arrays in the priority queue
class Sorting
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        size_t aLen = 0, bLen = 0;
        while (a != nullptr)
            aLen++, a = a->next;
        while (b != nullptr)
            bLen++, b = b->next;

        return aLen >= bLen;
    }
};

// this is the solution class for the merging the listnode given with vector
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &list)
    {
        priority_queue<ListNode *, vector<ListNode *>, Sorting> q;

        q.push(nullptr);
        for (auto l : list)
            q.push(l);

        while (q.size() > 1)
        {
            auto a = q.top();
            q.pop();
            auto b = q.top();
            q.pop();

            auto c = ListMerge(a, b);
            q.push(c);
        }
        // PrintNode(q.top());
        return q.top();
    }
};

// =====================================================================================
// =====================================================================================

class SmallSort
{
public:
    bool operator()(pair<int, ListNode *> a, pair<int, ListNode *> b)
    {
        return a.first >= b.first;
    }
};

class Solution2
{
    size_t SizeOfList(ListNode *a)
    {
        size_t aLen = 0;
        while (a != nullptr)
            aLen++, a = a->next;
        return aLen;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &list)
    {
        if (list.size() == 0)
            return nullptr;
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, SmallSort> q;

        for (auto l : list)
            q.push(make_pair(SizeOfList(l), l));

        while (q.size() > 1)
        {
            auto a = q.top();
            q.pop();
            auto b = q.top();
            q.pop();

            auto m = ListMerge(a.second, b.second);
            q.push(make_pair(a.first + b.first, m));
        }
        PrintNode(q.top().second);
        return q.top().second;
    }
};

// =====================================================================================
// =====================================================================================

int main(int arg, char *argv[])
{
    ListNode *l1 = new ListNode(1, new ListNode(4, new ListNode(5, nullptr)));
    ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4, nullptr)));
    ListNode *l3 = new ListNode(2, new ListNode(6, nullptr));
    ListNode *l4 = new ListNode(-2, new ListNode(9, new ListNode(89, new ListNode(112, new ListNode(531, nullptr)))));

    vector<ListNode *> list = {l1, l2, l3, l4};

    std::cout << "These are inputs .." << std::endl;
    for (auto l : list)
        PrintNode(l);

    std::cout << "This is outputs .." << std::endl;
    Solution2 s;
    s.mergeKLists(list);
    // ListMerge(l1, l3);
    return 0;
}