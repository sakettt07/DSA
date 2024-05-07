#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // using the recursive method
    void helper(ListNode *head, int &carry)
    {
        if (!head)
            return;
        helper(head->next, carry);           // we have reached to the lastnode of the LL.
        int product = head->val * 2 + carry; // double karliyaaa
        head->val = product % 10;            // newhead ki value mil gayi
        carry = product / 10;                // carry bhi dekh liya for T.C-1 its 18 so 1 carry
                                             // similarly for others.
    }
    ListNode *doubleIt(ListNode *head)
    {
        int carry = 0;
        helper(head, carry); // function call

        // agr carry hai toh hum uski new node bana denge.
        if (carry)
        {
            ListNode *Newlist = new ListNode(carry);
            Newlist->next = head;
            head = Newlist;
        }
        return head;
    }
};

int main()
{

    return 0;
}