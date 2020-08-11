/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (36.15%)
 * Likes:    3242
 * Dislikes: 214
 * Total Accepted:    490.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        ListNode* dummy = new ListNode(0);
        int n = lists.size();
        int leftLists = n;
        
        ListNode* curr = dummy;
        for(int i = 0; i < n; i++){
            if(!lists[i]) leftLists--;
        }
        while(leftLists > 1){
            
            int minValue = INT_MAX;
            int minIdx = -1;
            for(int i = 0; i < n; i++){
                if(!lists[i]) continue;
                if(lists[i]->val < minValue){
                    minValue = lists[i]->val;
                    minIdx = i;
                }
            }
            if(minIdx == -1) return nullptr;
            curr->next = lists[minIdx];
            lists[minIdx] = lists[minIdx]->next;
            if(!lists[minIdx]){
                leftLists--;
            }
            
            curr->next->next = nullptr;
            curr = curr->next;
        }
        int Idx = -1;
        for(int i = 0; i < n; i++){
            if(lists[i]){
                Idx = i;
                break;
            }
        }
        if(Idx != -1) curr->next = lists[Idx];
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
// @lc code=end

