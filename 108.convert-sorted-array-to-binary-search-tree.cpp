/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (52.75%)
 * Likes:    1571
 * Dislikes: 161
 * Total Accepted:    318.2K
 * Total Submissions: 592.6K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted array: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return buildTree(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* buildTree(vector<int>& nums, int left, int right){
        if(left == right){
            return new TreeNode(nums[left]);
        }
        if(left > right) return nullptr;
        int mid = (left + right) / 2;
        TreeNode* head = new TreeNode(nums[mid]);
        head->left = buildTree(nums, left, mid - 1);
        head->right = buildTree(nums, mid + 1, right);
        return head;
    }
};
// @lc code=end

