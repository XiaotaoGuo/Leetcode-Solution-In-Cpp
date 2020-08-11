/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (37.34%)
 * Likes:    1759
 * Dislikes: 92
 * Total Accepted:    209.2K
 * Total Submissions: 557.5K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 * 
 * Example 1:
 * 
 * 
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
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
    ListNode* sortList(ListNode* head) {
        
        if(!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        auto mid = slow->next;
        slow->next = nullptr;
        return merge(sortList(head), sortList(mid));
    }

private:
    ListNode* merge(ListNode* l1, ListNode* l2){
        
        ListNode dummy(0);
        ListNode* curr = &dummy;
        while(l1 && l2){
            if(l1->val > l2->val) swap(l1, l2);
            curr->next = l1;
            l1 = l1->next;
            curr = curr->next;
        }
        
        if(l1) curr->next = l1;
        if(l2) curr->next = l2;
        
        return dummy.next;
    }
};
// @lc code=end

