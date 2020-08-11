/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (37.06%)
 * Likes:    2101
 * Dislikes: 298
 * Total Accepted:    319.6K
 * Total Submissions: 855.3K
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* curr = head;
        int len = 0;
        // get the length of linked list
        while(fast){
            fast = fast->next;
            len++;
        }
        fast = head;
        int idx = 0;
        // push the fast pointer to the middle of linked list
        while(idx < len / 2){
            fast = fast->next;
            idx++;
        }
        if(len % 2) fast = fast->next;
        
        idx = 0;
        ListNode* prev = nullptr;
        
        // reverse the linked list in first half
        while(idx < len / 2){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            idx++;
        }
        curr = prev;
        
        // compare two linked list 
        while(curr){
            if(curr->val != fast->val) return false;
            curr = curr->next;
            fast = fast->next;
        }
        
        return true;
    }
};
// @lc code=end

