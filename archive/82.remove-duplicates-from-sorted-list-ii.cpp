/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (34.12%)
 * Likes:    1128
 * Dislikes: 91
 * Total Accepted:    210.3K
 * Total Submissions: 607.2K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->1->2->3
 * Output: 2->3
 * 
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        ListNode* curr = head;
        while(curr){
            int count = 1;
            while(curr->next && curr->val == curr->next->val){
                ListNode* tmp = curr;
                curr = curr->next;
                delete tmp;
                count++;
            }
            if(count == 1){
                prev->next = curr;
                prev = prev->next;
                
            }
            curr = curr->next;
            prev->next = nullptr;
        }
        curr = dummy->next;
        delete dummy;
        return curr;
    }
};
// @lc code=end

