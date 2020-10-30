/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (54.99%)
 * Likes:    2873
 * Dislikes: 162
 * Total Accepted:    343K
 * Total Submissions: 623.4K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,null,5,null,4]
 * Output: [1, 3, 4]
 * Explanation:
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
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
#include <queue>

class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> result;
        if (root == nullptr) return result;
        std::queue<TreeNode*> current_level;
        current_level.push(root);
        while (!current_level.empty()) {
            std::queue<TreeNode*> next_level;
            while(!current_level.empty()) {
                TreeNode* node = current_level.front();
                current_level.pop();
                // only push the rightmost node to result
                if (current_level.empty()) result.push_back(node->val);
                if (node->left) next_level.push(node->left);
                if (node->right) next_level.push(node->right);
            }
            current_level = next_level;
        }        
        return result;
    }
};
// @lc code=end

