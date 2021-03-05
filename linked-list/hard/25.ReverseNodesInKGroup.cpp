/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (44.71%)
 * Likes:    3349
 * Dislikes: 397
 * Total Accepted:    331.9K
 * Total Submissions: 738.8K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 *
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes, in the end, should remain as it is.
 *
 * Follow up:
 *
 *
 * Could you solve the problem in O(1) extra memory space?
 * You may not alter the values in the list's nodes, only nodes itself may be
 * changed.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [2,1,4,3,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2,3,4,5], k = 3
 * Output: [3,2,1,4,5]
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1,2,3,4,5], k = 1
 * Output: [1,2,3,4,5]
 *
 *
 * Example 4:
 *
 *
 * Input: head = [1], k = 1
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range sz.
 * 1 <= sz <= 5000
 * 0 <= Node.val <= 1000
 * 1 <= k <= sz
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        ListNode* last_tail = dummy;
        ListNode* curr = head;
        ListNode* curr_head = curr;

        int len = 0;
        while (curr) {
            len++;
            if (len == k) {
                // store the node just after next k nodes
                ListNode* next_head = curr->next;

                // split the linked list
                curr->next = nullptr;

                // reverse next k nodes
                reverse(curr_head);

                // the last node of next k nodes should be the head of
                // reverse linked list
                last_tail->next = curr;

                // the head of next k nodes now should be the last of
                // next k nodes
                last_tail = curr_head;

                // reset
                curr_head = next_head;
                curr = curr_head;
                len = 0;
            } else {
                curr = curr->next;
            }
        }

        last_tail->next = curr_head;

        return dummy->next;
    }

private:
    void reverse(ListNode* head) {
        if (!head) return;

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }
};
// @lc code=end
