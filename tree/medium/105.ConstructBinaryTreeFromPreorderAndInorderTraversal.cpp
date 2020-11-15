/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (49.68%)
 * Likes:    4207
 * Dislikes: 112
 * Total Accepted:    417.9K
 * Total Submissions: 829.3K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 *
 *
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 *
 * Return the following binary tree:
 *
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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

#include <unordered_map>
#include <vector>

class Solution {
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        std::unordered_map<int, int> inorder_map;
        for (size_t i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;
        }
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0,
                         inorder.size() - 1, inorder_map);
    }

private:
    TreeNode* buildTree(const std::vector<int>& preorder,
                        const std::vector<int>& inorder, int preorder_begin,
                        int preorder_end, int inorder_begin, int inorder_end,
                        std::unordered_map<int, int>& inorder_map) {
        if (preorder_end < preorder_begin || inorder_end < inorder_begin)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[preorder_begin]);
        int root_idx = inorder_map[root->val];
        int left_len = root_idx - inorder_begin;
        int right_len = inorder_end - root_idx;
        root->left = buildTree(preorder, inorder, preorder_begin + 1,
                               preorder_begin + left_len, inorder_begin,
                               root_idx - 1, inorder_map);
        root->right =
            buildTree(preorder, inorder, preorder_begin + left_len + 1,
                      preorder_end, root_idx + 1, inorder_end, inorder_map);

        return root;
    }
};
// @lc code=end
