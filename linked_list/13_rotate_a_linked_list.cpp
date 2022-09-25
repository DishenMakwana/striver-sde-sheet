// Problem Statement : Given the head of a linked list, rotate the list to the right by k places.

// Example 1:
// Input:
// 	head = [1,2,3,4,5]
// 	k = 2
// Output:
//  head = [4,5,1,2,3]

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

ListNode *rotate(ListNode *head, int k)
{
    if (!head || !head->next || k == 0)
    {
        return head;
    }

    ListNode *cur = head;
    int len = 1;

    while (cur->next && ++len)
    {
        cur = cur->next;
    }

    cur->next = head;
    k = k % len;
    k = len - k;

    while (k--)
    {
        cur = cur->next;
    }

    head = cur->next;
    cur->next = NULL;

    return head;
}

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;
    head = rotate(head, k);
    printList(head);

    return 0;
}

// Time Complexity : O(N) + O(N-(n%K)) = O(N)
// Space Complexity : O(1)