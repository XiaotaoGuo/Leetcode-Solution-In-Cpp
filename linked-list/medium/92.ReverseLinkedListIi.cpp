/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (40.49%)
 * Likes:    3321
 * Dislikes: 169
 * Total Accepted:    328.4K
 * Total Submissions: 811K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 * 
 * Note: 1 ≤ m ≤ n ≤ length of list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode *first_tail, *second_tail;
        ListNode *curr = dummy, *prev, *next;
        int step = 1;

        // move curr to the node just before the mth node, mark it as tail for the first part
        // and mth node should be tail for second part
        while (step < m) {
            curr = curr->next;
            step++;
        }
        first_tail = curr;
        curr = curr->next;
        
        second_tail = curr;
        prev = curr;
        curr = curr->next;
        while (step < n) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            step++;
        }
        first_tail->next = prev;
        second_tail->next = curr;

        return dummy->next;

    }
};
// @lc code=end

