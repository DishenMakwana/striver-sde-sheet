// Problem Statement: Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

// Example 1:
// Input:
// List 1 = [1,3,1,2,4], List 2 = [3,2,4]
// Output:
// 2

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }

    ListNode(int val, ListNode *next)
    {
        this->val = val;
        this->next = next;
    }
};

ListNode *getIntersectionNode(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL || l2 == NULL)
    {
        return NULL;
    }

    ListNode *a = l1;
    ListNode *b = l2;

    while (a != b)
    {
        a = a == NULL ? l2 : a->next;
        b = b == NULL ? l1 : b->next;
    }

    return a;
}

void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(1);
    l1->next->next->next = new ListNode(2);
    l1->next->next->next->next = new ListNode(4);

    ListNode *l2 = new ListNode(3);
    l2->next = l1->next->next->next;
    l2->next->next = new ListNode(4);

    ListNode *ans = getIntersectionNode(l1, l2);
    cout << ans->val << endl;

    return 0;
}

// Time Complexity: 2*O(n+m)
// Space Complexity: O(1)