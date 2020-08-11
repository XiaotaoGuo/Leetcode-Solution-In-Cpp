/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (41.10%)
 * Likes:    1085
 * Dislikes: 23
 * Total Accepted:    175.9K
 * Total Submissions: 422.4K
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty()) return nullptr;
        return buildSubTree(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
private:
    TreeNode* buildSubTree(vector<int>& inorder, vector<int>& postorder, 
                           int l1, int r1, int l2, int r2){
        if(l1 > r1) return nullptr;
        TreeNode* root = new TreeNode(postorder[r2]);
        if(l2 == r2) return root;
        int mid = 0;
        for(uint i = 0; i < inorder.size(); i++)
            if(inorder[i] == postorder[r2]){
                mid = i;
                break;
            }
        int len = mid - 1 - l1;
        root->left = buildSubTree(inorder, postorder, l1, mid-1, l2, l2 + len);
        root->right = buildSubTree(inorder, postorder, mid+1, r1, l2 + len + 1, r2-1);
        return root;
    }
};
// @lc code=end

