/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (47.89%)
 * Likes:    2192
 * Dislikes: 41
 * Total Accepted:    264K
 * Total Submissions: 544.3K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 *
 *
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
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
    TreeNode* buildTree(std::vector<int>& inorder,
                        std::vector<int>& postorder) {
        std::unordered_map<int, int> inorder_map;
        for (size_t i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;
        }
        return buildTree(postorder, inorder, 0, postorder.size() - 1, 0,
                         inorder.size() - 1, inorder_map);
    }

private:
    TreeNode* buildTree(const std::vector<int>& postorder,
                        const std::vector<int>& inorder, int postorder_begin,
                        int postorder_end, int inorder_begin, int inorder_end,
                        std::unordered_map<int, int>& inorder_map) {
        if (postorder_end < postorder_begin || inorder_end < inorder_begin)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[postorder_end]);
        int root_idx = inorder_map[root->val];
        int left_len = root_idx - inorder_begin;
        int right_len = inorder_end - root_idx;
        root->left = buildTree(postorder, inorder, postorder_begin,
                               postorder_begin + left_len - 1, inorder_begin,
                               root_idx - 1, inorder_map);
        root->right = buildTree(postorder, inorder, postorder_begin + left_len,
                                postorder_end - 1, root_idx + 1, inorder_end,
                                inorder_map);

        return root;
    }
};
// @lc code=end
