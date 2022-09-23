// Problem Statement : Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.k is a positive integer and is less than or equal to the length of the linked list.If the number of nodes is not a multiple of k then left - out nodes, in the end, should remain as it is.

// Example 1:
// Input:
//  head = [1,2,3,4,5,6,7,8] k=3
// Output:
//  head = [3,2,1,6,5,4,7,8]

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

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == NULL || k == 1)
        return head;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *cur = dummy, *nex = dummy, *pre = dummy;
    int cnt = 0;

    while (cur->next != NULL)
    {
        cur = cur->next;
        cnt++;
    }

    while (cnt >= k)
    {
        cur = pre->next;
        nex = cur->next;

        for (int i = 1; i < k; i++)
        {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }

        pre = cur;
        cnt -= k;
    }

    return dummy->next;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);

    ListNode *res = reverseKGroup(head, 3);

    while (res != NULL)
    {
        cout << res->val << " ";
        res = res->next;
    }

    return 0;
}

// Time Complexity : O(N)
// Space Complexity : O(1)