#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
#include <stack>
using namespace std; // namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
class Solution{
 Node *reverseList(Node *temp)
{
    Node *dummy = NULL;
    while (temp != NULL)
    {
        Node *next = temp->next;
        temp->next = dummy;
        dummy = temp;
        temp = next;
    }
    return dummy;
}
 public:
bool isPalindrome(Node *head)
{
    // Your code here
    if (head == NULL || head->next == NULL)
        return true;

    Node *slow = head;
    Node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *rev = reverseList(slow->next);

    while (rev != NULL)
    {
        if (head->data != rev->data)
        {
            return false;
        }
        head = head->next;
        rev = rev->next;
    }
    return true;
}
};
int main()
{
    int t, i, n, l, firstdata;
    cin >> t;
    struct Node *head = NULL, *tail = NULL;
    while (t--)
    {
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;

        for (int i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    }
    Solution obj;
    if (obj.isPalindrome(head))
    {
        cout << true;
    }
    else
        cout << false;
}