/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
 *
 * https://leetcode.com/problems/delete-node-in-a-bst/description/
 *
 * algorithms
 * Medium (42.98%)
 * Likes:    2090
 * Dislikes: 90
 * Total Accepted:    128.4K
 * Total Submissions: 292.2K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n3'
 *
 * Given a root node reference of a BST and a key, delete the node with the
 * given key in the BST. Return the root node reference (possibly updated) of
 * the BST.
 * 
 * Basically, the deletion can be divided into two stages:
 * 
 * Search for a node to remove.
 * If the node is found, delete the node.
 * 
 * 
 * 
 * Note: Time complexity should be O(height of tree).
 * 
 * Example:
 * 
 * root = [5,3,6,2,4,null,7]
 * key = 3
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Given key to delete is 3. So we find the node with value 3 and delete it.
 * 
 * One valid answer is [5,4,6,2,null,null,7], shown in the following BST.
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 4   6
 * ⁠/     \
 * 2       7
 * 
 * Another valid answer is [5,2,6,null,4,null,7].
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 2   6
 * ⁠  \   \
 * ⁠   4   7
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // case 0: tree not exist, return nullptr
        if (!root) return nullptr;

        if (root->val > key) {
            // case 1: target node is smaller than root, search it on left subtree
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            // case 2: target node is larger than root, search it on left subtree
            root->right = deleteNode(root->right, key);
        } else {
            // case 3.1: target node is root, if one of its subtree is empty;
            // we can replace root with the other subtree's root
            if (!root->left || !root->right) {
                root = (root->left) ? root->left : root->right;
            } else {
                // case 3.2: two of its subtrees exists
                // we replace root with the smallest node of its right subtree, then delete that node
                TreeNode *target = root->right;
                while (target->left) target = target->left;
                root->val = target->val;
                root->right = deleteNode(root->right, target->val);
            }
        }
        return root;
    }
};
// @lc code=end

