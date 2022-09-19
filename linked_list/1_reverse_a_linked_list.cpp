// Reverse a Linked List
// Problem Statement: Given the head of a singly linked list, write a program to reverse the linked list, and return the head pointer to the reversed list.

// Input Format:
// head = [3,6,8,10]
// This means the given linked list is 3->6->8->10 with head pointer at node 3.

// Result:
// Output = [10,6,8,3]
// This means, after reversal, the list should be 10->6->8->3 with the head pointer at node 10.

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
    ListNode *reverseList(ListNode *&head)
    {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode *newNode = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newNode;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)

int main()
{
    ListNode *head = new ListNode(3);
    head->next = new ListNode(6);
    head->next->next = new ListNode(8);
    head->next->next->next = new ListNode(10);

    Solution s;
    ListNode *newHead = s.reverseList(head);

    while (newHead != NULL)
    {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }

    return 0;
}