/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (43.30%)
 * Likes:    1891
 * Dislikes: 375
 * Total Accepted:    251.1K
 * Total Submissions: 577.5K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * Given the head of a linked list and a value x, partition it such that all
 * nodes less than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,4,3,2,5,2], x = 3
 * Output: [1,2,2,4,3,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [2,1], x = 2
 * Output: [1,2]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [0, 200].
 * -100 <= Node.val <= 100
 * -200 <= x <= 200
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less_list = new ListNode();
        ListNode* less_tail = less_list;
        ListNode* greater_list = new ListNode();
        ListNode* greater_tail = greater_list;
        ListNode* curr = head;
        while (curr) {
            if (curr->val < x) {
                less_tail->next = curr;
                less_tail = curr;
            } else {
                greater_tail->next = curr;
                greater_tail = curr;
            }
            curr = curr->next;
        }
        less_tail->next = greater_list->next;
        return less_list->next;
    }
};
// @lc code=end
