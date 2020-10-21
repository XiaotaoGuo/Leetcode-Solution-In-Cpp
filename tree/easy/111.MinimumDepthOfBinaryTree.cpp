/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (37.62%)
 * Likes:    1751
 * Dislikes: 759
 * Total Accepted:    454K
 * Total Submissions: 1.2M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 *
 * Note: A leaf is a node with no children.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: root = [2,null,3,null,4,null,5,null,6]
 * Output: 5
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 10^4].
 * -1000 <= Node.val <= 1000
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
#include <bits/stdc++.h>

#include <algorithm>
#include <queue>

class Solution {
    // method 1 : iteratively
public:
    int minDepth(TreeNode* root) {
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
                if (!q->left && !q->right) {
                    // we found the first leaf node, it must in
                    // min depth
                    return depth;
                }
                if (node->left) next_level.push(node->left);
                if (node->right) next_level.push(node->right);
            }
            std::swap(q, next_level);
        }

        return depth;
    }

    // method 2 : recursively
    // public:
    //     int minDepth(TreeNode* root) {
    //         if (!root) return 0;
    //         int min_depth = INT_MAX;
    //         dfs(root, 0, )
    //     }

    // private:
    //     int dfs(TreeNode* node, int current_depth, int& min_depth) {
    //         if (!node || current_depth >= min_depth) {
    //             return;
    //         }
    //         current_depth++;
    //         if (!node->left && !node->right) {
    //             min_depth = current_depth;
    //         }

    //         dfs(node->left, current_depth, min_depth);
    //         dfs(node->right, current_depth, min_depth);
    //     }
};
// @lc code=end
