/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (47.42%)
 * Likes:    2179
 * Dislikes: 77
 * Total Accepted:    361.1K
 * Total Submissions: 757.1K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 * Given the below binary tree and sum = 22,
 *
 *
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \    / \
 * 7    2  5   1
 *
 *
 * Return:
 *
 *
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
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

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> pathSum(TreeNode* root, int sum) {
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        search(root, sum, path, result);
        return result;
    }

private:
    void search(TreeNode* root, int target, std::vector<int>& path,
                std::vector<std::vector<int>>& result) {
        if (!root) return;
        path.push_back(root->val);
        target -= root->val;
        if (!root->left && !root->right) {
            if (target == 0) {
                result.push_back(path);
            }
        }
        search(root->left, target, path, result);
        search(root->right, target, path, result);

        path.pop_back();
    }
};
// @lc code=end
