// Detect a Cycle in a Linked List

// Problem Statement: Given head, the head of a linked list, determine if the linked list has a cycle in it. There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.

// Return true if there is a cycle in the linked list. Otherwise, return false.

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

bool hasCycle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return false;
    }

    ListNode *fast = head, *slow = head;

    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    ListNode *node = new ListNode(1);
    node->next = new ListNode(2);
    node->next->next = new ListNode(3);
    node->next->next->next = new ListNode(4);
    node->next->next->next->next = node->next;

    cout << (hasCycle(node) == true ? "Yes" : "No") << endl;

    return 0;
}

// Time Complexity : O(N)
// Space Complexity : O(N)