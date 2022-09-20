// Remove N-th node from the end of a Linked List
// Problem Statement: Given a linked list, and a number N. Find the Nth node from the end of this linked list and delete it. Return the head of the new modified linked list.

// Example
//  Input: head = [1,2,3,4,5], n = 2

// Output: [1,2,3,5]

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode()
    {
        val = 0;
        next = NULL;
    }

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

ListNode *removeNthFromLast(ListNode *head, int n)
{
    ListNode *start = new ListNode();
    start->next = head;

    ListNode *fast = start, *slow = start;

    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return start->next;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;

    ListNode *result = removeNthFromLast(head, n);

    while (result != NULL)
    {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)