// Add two numbers represented as Linked Lists
// Problem Statement: Given the heads of two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// Input Format:
// (Pointer/Access to the head of the two linked lists)

// num1  = 243, num2 = 564

// l1 = [2,4,3]
// l2 = [5,6,4]

// Result: sum = 807; L = [7,0,8]

// Explanation: Since the digits are stored in reverse order, reverse the numbers first to get the or original number and then add them as → 342 + 465 = 807. Refer to the image below.

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

ListNode *addTwoNumber(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(0);
    ListNode *tmp = dummy;

    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry)
    {
        int sum = 0;

        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        sum += carry;

        carry = sum / 10;

        ListNode *node = new ListNode(sum % 10);

        tmp->next = node;
        tmp = tmp->next;
    }

    return dummy->next;
}

void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(7);
    l2->next->next->next = new ListNode(9);

    ListNode *res = addTwoNumber(l1, l2);

    printList(res);

    return 0;
}

// Time Complexity: O(max(m,n)) where m and n are the number of nodes in the two linked lists.
// Space Complexity: O(max(m,n))