/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int len = n - m;
        if(len <= 0) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int idx = 0;
        ListNode* curr = dummy;
        ListNode* tail = nullptr;
        while(idx < m){
            tail = curr;
            curr = curr->next;
            idx++;
        }
        
        ListNode* prev = nullptr;
        ListNode* next = curr->next;
        while(idx <= n && curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            idx++;
        }
        
        tail->next->next = curr;
        tail->next = prev;
        head = dummy->next;
        delete dummy;
        return head;
    }
};
// @lc code=end

