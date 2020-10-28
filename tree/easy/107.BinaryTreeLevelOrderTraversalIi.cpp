/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (54.24%)
 * Likes:    1747
 * Dislikes: 226
 * Total Accepted:    380.6K
 * Total Submissions: 701.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
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
 * return its bottom-up level order traversal as:
 *
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <algorithm>
#include <queue>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> levelOrderBottom(TreeNode *root) {
        std::vector<std::vector<int>> result;
        if (root == nullptr) return result;

        std::queue<TreeNode *> q;
        q.psuh(root);
        while (!q.empty()) {
            std::queue<TreeNode *> next_q;
            std::vector<int> level;
            while (!q.empty()) {
                TreeNode *node = q.front();
                q.pop();

                level.push_back(node->val);
                if (node->left) next_q.push(node->left);
                if (node->right) next_q.push(node->right);
            }
            result.push_back(level);
            level.clear();
            std::swap(q, next_q);
        }

        std::reverse(result.begin(), result.end());

        return result;
    }
};
// @lc code=end
