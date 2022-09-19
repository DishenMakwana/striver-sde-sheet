// Find middle element in a Linked List
// Problem Statement: Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node.

// Input Format:
// ( Pointer / Access to the head of a Linked list )
// head = [1,2,3,4,5]

// Result: [3,4,5]
// ( As we will return the middle of Linked list the further linked list will be still available )

// Explanation: The middle node of the list is node 3 as in the below image.

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

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head, *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution s;
    ListNode *middle = s.middleNode(head);

    cout << middle->val << " ";

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)