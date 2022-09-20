// Merge two sorted Linked Lists
// In this article, we will solve the most asked coding interview question: ” Merge two sorted Linked Lists “

// Problem Statement: Given two singly linked lists that are sorted in increasing order of node values, merge two sorted linked lists and return them as a sorted list. The list should be made by splicing together the nodes of the first two lists.

// Input Format :
// l1 = {3,7,10}, l2 = {1,2,5,8,10}

// Output :
// {1,2,3,5,7,8,10,10}

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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL)
        return l2;

    if (l2 == NULL)
        return l1;

    if (l1->val > l2->val)
        swap(l1, l2);

    ListNode *res = l1;

    while (l1 != NULL && l2 != NULL)
    {
        ListNode *tmp = NULL;

        while (l1 != NULL && l1->val <= l2->val)
        {
            tmp = l1;
            l1 = l1->next;
        }

        tmp->next = l2;

        swap(l1, l2);
    }

    return res;
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
    ListNode *l1 = new ListNode(5);
    l1->next = new ListNode(7);
    l1->next->next = new ListNode(9);

    ListNode *l2 = new ListNode(3);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(8);
    l2->next->next->next = new ListNode(10);

    ListNode *res = mergeTwoLists(l1, l2);
    printList(res);

    return 0;
}

// Time Complexity: O(n+m)
// Space Complexity: O(1)