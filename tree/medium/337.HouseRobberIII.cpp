/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
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
#include <unordered_map>
class Solution {
public:
    int rob(TreeNode* root) {
        if (!root) return 0;
        if (hmap.find(root) != hmap.end()) return hmap[root];
        int curr_sum = root->val;
        if (root->left) {
            curr_sum += rob(root->left->left);
            curr_sum += rob(root->left->right);
        }
        if (root->right) {
            curr_sum += rob(root->right->left);
            curr_sum += rob(root->right->right);
        }
                            
        int prev_sum = rob(root->left) + rob(root->right);
        hmap[root] = std::max(curr_sum, prev_sum);
        return hmap[root];
    }

private:
    std::unordered_map<TreeNode*, int> hmap;
};
// @lc code=end

