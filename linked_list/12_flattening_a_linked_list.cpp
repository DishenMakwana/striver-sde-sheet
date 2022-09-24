// Problem Statement: Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:

// (i) a next pointer to the next node,

// (ii) a bottom pointer to a linked list where this node is head.

// Each of the sub-linked-list is in sorted order.

// Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order.

// Note: The flattened list will be printed using the bottom pointer instead of the next pointer.

// Example 1:
// Input:
// Number of head nodes = 4
// Array holding length of each list with head and bottom = [4,2,3,4]
// Elements of entire linked list = [5,7,8,30,10,20,19,22,50,28,35,40,45]

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode *bottom;

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

ListNode *mergeTwoLists(ListNode *a, ListNode *b)
{
    ListNode *tmp = new ListNode(0);
    ListNode *res = tmp;

    while (a != NULL && b != NULL)
    {
        if (a->val < b->val)
        {
            tmp->bottom = a;
            tmp = tmp->bottom;
            a = a->bottom;
        }
        else
        {
            tmp->bottom = b;
            tmp = tmp->bottom;
            b = b->bottom;
        }
    }

    if (a)
    {
        tmp->bottom = a;
    }
    else
    {
        tmp->bottom = b;
    }

    return res->bottom;
}

ListNode *flatten(ListNode *root)
{

    if (root == NULL || root->next == NULL)
        return root;

    // recur for list on right
    root->next = flatten(root->next);

    // now merge
    root = mergeTwoLists(root, root->next);

    // return the root
    // it will be in turn merged with its left
    return root;
}

int main()
{
    int n;
    cin >> n;

    vector<ListNode *> heads(n);

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;

        ListNode *head = new ListNode(0);
        ListNode *tmp = head;

        for (int j = 0; j < m; j++)
        {
            int val;
            cin >> val;

            tmp->bottom = new ListNode(val);
            tmp = tmp->bottom;
        }

        heads[i] = head->bottom;
    }

    ListNode *root = new ListNode(0);
    ListNode *tmp = root;

    for (int i = 0; i < n; i++)
    {
        tmp->next = heads[i];
        tmp = tmp->next;
    }

    root = flatten(root->next);

    while (root)
    {
        cout << root->val << " ";
        root = root->bottom;
    }

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)