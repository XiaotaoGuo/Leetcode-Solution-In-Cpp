/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (52.05%)
 * Likes:    2045
 * Dislikes: 117
 * Total Accepted:    344.6K
 * Total Submissions: 659K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 *
 * Input:
 *
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 *
 * Output: ["1->2->5", "1->3"]
 *
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return paths;
    }

private:
    std::vector<std::string> paths;
    void dfs(TreeNode* root, std::string path) {
        if (!root) {
            return;
        }

        if (!path.empty()) path += "->";
        path += std::to_string(root->val);
        if (!root->left && !root->right) {
            paths.push_back(path);
            return;
        }
        dfs(root->left, path);
        dfs(root->right, path);
    }
};
// @lc code=end
