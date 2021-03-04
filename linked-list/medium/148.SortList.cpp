/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (46.15%)
 * Likes:    3921
 * Dislikes: 168
 * Total Accepted:    340K
 * Total Submissions: 734.2K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Given the head of a linked list, return the list after sorting it in
 * ascending order.
 *
 * Follow up: Can you sort the linked list in O(n logn) time and O(1) memory
 * (i.e. constant space)?
 *
 *
 * Example 1:
 *
 *
 * Input: head = [4,2,1,3]
 * Output: [1,2,3,4]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [-1,5,3,4,0]
 * Output: [-1,0,3,4,5]
 *
 *
 * Example 3:
 *
 *
 * Input: head = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [0, 5 * 10^4].
 * -10^5 <= Node.val <= 10^5
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
    ListNode *sortList(ListNode *head) {
        // for linked list with length of 0 or 1, no need to sort
        if (!head || !head->next) {
            return head;
        }

        ListNode *dummy = new ListNode();
        dummy->next = head;

        ListNode *fast = dummy;
        ListNode *slow = dummy;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        fast = slow->next;
        slow->next = nullptr;

        return merge(sortList(head), sortList(fast));
    }

private:
    ListNode *merge(ListNode *A, ListNode *B) {
        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;

        while (A && B) {
            if (A->val <= B->val) {
                curr->next = A;
                A = A->next;
            } else {
                curr->next = B;
                B = B->next;
            }
            curr = curr->next;
        }

        if (!A) {
            curr->next = B;
        }
        if (!B) {
            curr->next = A;
        }

        return dummy->next;
    }
};
// @lc code=end
