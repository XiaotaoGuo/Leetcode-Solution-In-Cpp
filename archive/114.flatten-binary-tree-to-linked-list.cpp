/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (44.24%)
 * Likes:    1816
 * Dislikes: 240
 * Total Accepted:    269.9K
 * Total Submissions: 606.1K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * Given a binary tree, flatten it to a linked list in-place.
 * 
 * For example, given the following tree:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 
 * The flattened tree should look like:
 * 
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
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
    void flatten(TreeNode* root) {
        if(!root || (!root->left && !root->right)) return;
        if(!root->left){
            flatten(root->right);
        }
        else if(!root->right){
            flatten(root->left);
            root->right = root->left;
            root->left = NULL;
        }
        else{
            flatten(root->left);
            flatten(root->right);
            TreeNode* curr = root->left;
            while(curr->right) curr = curr->right;
            curr->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
    }
};
// @lc code=end

