/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (40.40%)
 * Likes:    4705
 * Dislikes: 426
 * Total Accepted:    564.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 *
 * Example 1:
 *
 *
 * Input: 1->2
 * Output: false
 *
 * Example 2:
 *
 *
 * Input: 1->2->2->1
 * Output: true
 *
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode *head) {
        // compute the length of linked list
        int n = 0;
        ListNode *curr = head;
        while (curr) {
            curr = curr->next;
            n++;
        }
        if (n <= 1) return true;

        // move curr to the second half of linked list
        curr = head;
        for (int i = 0; i < n / 2; i++) {
            curr = curr->next;
        }
        if (n % 2) {
            curr = curr->next;
        }

        // reverse the second half of linked list
        ListNode *prev = nullptr;
        ListNode *next = curr->next;
        curr->next = prev;
        while (next) {
            prev = curr;
            curr = next;
            next = curr->next;
            curr->next = prev;
        }

        // compare the first half & reversed second half
        while (curr && head) {
            if (curr->val != head->val) return false;
            curr = curr->next;
            head = head->next;
        }

        return true;
    }
};
// @lc code=end
