// Problem Statement: Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list instead, you will be given access to the node to be deleted directly. It is guaranteed that the node to be deleted is not a tail node in the list.

// Example 1:
// Input:
//  Linked list: [1,4,2,3]
//        Node = 2
// Output:
// Linked list: [1,4,3]
// Explanation: Access is given to node 2. After deleting nodes, the linked list will be modified to [1,4,3].

// Example 2:
// Input:
//  Linked list: [1,2,3,4]
//        Node = 1
// Output: Linked list: [2,3,4]
// Explanation:
//  Access is given to node 1. After deleting nodes, the linked list will be modified to [2,3,4].

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

void deleteNode(ListNode *node)
{
    if (node == NULL)
        return;

    node->val = node->next->val;
    node->next = node->next->next;

    return;
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
    ListNode *head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);

    printList(head);

    deleteNode(head->next->next);

    printList(head);

    return 0;
}

// Time Complexity: O(1)
// Space Complexity: O(1)