/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (63.28%)
 * Likes:    5956
 * Dislikes: 116
 * Total Accepted:    1.2M
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Reverse a singly linked list.
 *
 * Example:
 *
 *
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 *
 *
 * Follow up:
 *
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
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
    ListNode* reverseList(ListNode* head) {
        method #1 : iteratively ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    };

    // method #2: recursively
    // class Solution {
    // public:
    //     ListNode* reverseList(ListNode* head) {

    //         if (head == nullptr) return head;

    //         ListNode* new_head = new ListNode();
    //         reverseListRecursivly(head, new_head);
    //         head->next = nullptr;

    //         return new_head;
    //     }

    // private:
    //     ListNode* reverseListRecursivly(ListNode* head, ListNode*& new_head)
    //     {

    //         if (head == nullptr || head->next == nullptr) {
    //             new_head = head;
    //             return head;
    //         }

    //         reverseListRecursivly(head->next, new_head)->next = head;

    //         return head;
    //     }
    // };
    // @lc code=end
