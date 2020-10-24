/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 *
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (66.50%)
 * Likes:    3034
 * Dislikes: 82
 * Total Accepted:    927.2K
 * Total Submissions: 1.4M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path from the
 * root node down to the farthest leaf node.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 * Given binary tree [3,9,20,null,null,15,7],
 *
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 * return its depth = 3.
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
#include <bits/stdc++.h>

#include <algorithm>
#include <queue>

#define BFS 0

class Solution {
#if BFS
public:
    // method 1 : iteratively
    int maxDepth(TreeNode* root) {
        std::queue<TreeNode*> q;
        if (!root) return 0;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            depth++;
            std::queue<TreeNode*> next_level;
            while (!q.empty()) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) next_level.push(node->left);
                if (node->right) next_level.push(node->right);
            }
            std::swap(q, next_level);
        }

        return depth;
    }
#else
    // method 2 : recursively
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int max_depth = 0;
        dfs(root, 0, max_depth);

        return max_depth;
    }

private:
    void dfs(TreeNode* node, int current_depth, int& max_depth) {
        if (!node) {
            return;
        }
        current_depth++;
        if (!node->left && !node->right) {
            max_depth = std::max(current_depth, max_depth);
        }

        dfs(node->left, current_depth, max_depth);
        dfs(node->right, current_depth, max_depth);
    }
#endif
};
// @lc code=end
