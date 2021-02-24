/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (35.38%)
 * Likes:    10908
 * Dislikes: 2637
 * Total Accepted:    1.8M
 * Total Submissions: 5.1M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have
 * leading zeros.
 * 
 * 
 */

// @lc code=start
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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len_diff = 0;
        ListNode *curr1 = l1;
        ListNode *curr2 = l2;
        ListNode *dummy = new ListNode();
        ListNode *curr_new = dummy;
        bool has_one = false;
        while (curr1 || curr2) {
            int val1 = 0;
            int val2 = 0;

            if (curr1) {
                val1 = curr1->val;
                curr1 = curr1->next;
            }

            if (curr2) {
                val2 = curr2->val;
                curr2 = curr2->next;
            }

            int sum = val1 + val2;
            if (has_one) {
                sum++;
                has_one = false;
            }

            if (sum >= 10) {
                sum -= 10;
                has_one = true;
            }

            curr_new->next = new ListNode(sum);
            curr_new = curr_new->next;
        }

        if (has_one) {
            curr_new->next = new ListNode(1);
        }

        return dummy->next;
    }
};
// @lc code=end

