/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (49.10%)
 * Likes:    2681
 * Dislikes: 109
 * Total Accepted:    429.6K
 * Total Submissions: 874.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
#include <stack>

class Solution {
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if (root == nullptr) return result;
        std::stack<TreeNode*> curr_level_nodes;
        curr_level_nodes.push(root);
        int curr_level = 0;
        while (!curr_level_nodes.empty()) {
            std::vector<int> curr_level_vals;
            std::stack<TreeNode*> next_level_nodes;
            while (!curr_level_nodes.empty()) {
                TreeNode* node = curr_level_nodes.top();
                curr_level_nodes.pop();
                if (curr_level % 2 == 0) {
                    // if even level, push children from left to right
                    if (node->left) next_level_nodes.push(node->left);
                    if (node->right) next_level_nodes.push(node->right);
                }
                else {
                    // if odd level, push children from right to left
                    if (node->right) next_level_nodes.push(node->right);
                    if (node->left) next_level_nodes.push(node->left);
                }
                curr_level_vals.push_back(node->val);
            }
            result.push_back(curr_level_vals);
            ++curr_level;
            curr_level_nodes = next_level_nodes;
        }

        return result;
    }
};
// @lc code=end

