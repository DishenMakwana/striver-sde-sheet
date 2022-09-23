// Problem Statement : Given the head of a singly linked list, return true if it is a palindrome.

// Example 1:
// Input: head = [1,2,3,3,2,1]
// Output:
//  true

// Explanation: If we read elements from left to right, we get [1,2,3,3,2,1]. When we read elements from right to left, we get [1,2,3,3,2,1]. Both ways list remains same and hence, the given linked list is palindrome.

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

ListNode *reverseList(ListNode *head)
{
    ListNode *pre = NULL, *next = NULL;

    while (head != NULL)
    {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }

    return pre;
}

bool isPalindrome(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }

    ListNode *slow = head, *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = reverseList(slow->next);
    slow = slow->next;

    while (slow != NULL)
    {
        if (head->val != slow->val)
        {
            return false;
        }

        head = head->next;
        slow = slow->next;
    }

    return true;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next = new ListNode(1);

    cout << (isPalindrome(head) == true ? "Yes" : "No") << endl;

    return 0;
}

// Time Complexity : 3*O(N/2) = O(N/2)
// Space Complexity : O(1)