/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (50.47%)
 * Likes:    3465
 * Dislikes: 370
 * Total Accepted:    388.1K
 * Total Submissions: 765.8K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * Given a binary tree, flatten it to a linked list in-place.
 *
 * For example, given the following tree:
 *
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 *
 *
 * The flattened tree should look like:
 *
 *
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
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
class Solution {
public:
    void flatten(TreeNode* root) { flattenTreeNode(root); }

private:
    TreeNode* flattenTreeNode(TreeNode* root) {
        if (root == nullptr) return nullptr;
        if (!root->left && !root->right) return root;

        // store left & right subtree to a local var incase we lost it
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        // flattern left subtree, if left is nullptr, the end of left subtree
        // would be root
        TreeNode* left_end = root;
        if (left) left_end = flattenTreeNode(left);

        // flatten right subtree, if right is nullptr,
        // the end of right subtree would be the end of left subtree
        TreeNode* right_end = left_end;
        if (right) right_end = flattenTreeNode(right);

        // detach left subtree
        root->left = nullptr;
        // attach left flattened subtree to right of root
        root->right = left;
        // concatanate right flatterned subtree to the end of left flattened
        // subtree
        left_end->right = right;

        return right_end;
    }
};
// @lc code=end
