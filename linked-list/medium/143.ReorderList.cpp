/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 *
 * https://leetcode.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (36.81%)
 * Likes:    2247
 * Dislikes: 123
 * Total Accepted:    258.3K
 * Total Submissions: 675.1K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 *
 * Example 1:
 *
 *
 * Given 1->2->3->4, reorder it to 1->4->2->3.
 *
 * Example 2:
 *
 *
 * Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        // find median
        ListNode *fast = head, *slow = head;
        ListNode* tail;
        while (fast && fast->next) {
            fast = fast->next->next;
            tail = slow;
            slow = slow->next;
        }
        if (fast) {
            tail = slow;
            slow = slow->next;
        }
        // cut list into two half
        tail->next = nullptr;

        // push second half list to a stack
        std::stack<ListNode*> second_half;
        while (slow) {
            second_half.push(slow);
            slow = slow->next;
        }

        // concatanate two half
        ListNode* curr = head;
        while (!second_half.empty()) {
            ListNode* nextNode = second_half.top();
            second_half.pop();
            nextNode->next = curr->next;
            curr->next = nextNode;
            curr = curr->next->next;
        }
    }
};
// @lc code=end
