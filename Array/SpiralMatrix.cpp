// Its a good question for beginners to traverse in the 2D matrix and traverse the linked list value.

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        // we can move step wise step in this question.
        // defining the important variables.

        vector<vector<int>> finl(m, vector<int>(n, -1));

        // now the positions.
        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        // as we are given with the linked list so
        while (head)
        {

            for (int i = left; i <= right; i++)
            {
                if (!head)
                {
                    break;
                }
                finl[top][i] = head->val;
                head = head->next;
            }
            top++; // we have filled the first row.

            // now move downward
            for (int i = top; i <= bottom; i++)
            {
                if (!head)
                {
                    break;
                }
                finl[i][right] = head->val;
                head = head->next;
            }
            right--; // coming towards left.

            for (int i = right; i >= left; i--)
            {
                if (!head)
                {
                    break;
                }
                finl[bottom][i] = head->val;
                head = head->next;
            }
            bottom--; // filled till the right-left

            // now moving upward

            for (int i = bottom; i >= top; i--)
            {
                if (!head)
                {
                    break;
                }
                finl[i][left] = head->val;
                head = head->next;
            }
            left++;
            // all four directions covered.
        }
        return finl;
    }
};

int main()
{

    return 0;
}