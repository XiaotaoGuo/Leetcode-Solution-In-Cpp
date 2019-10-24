/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (43.24%)
 * Likes:    2176
 * Dislikes: 61
 * Total Accepted:    266.1K
 * Total Submissions: 608.1K
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return nullptr;
        for(int i = 0; i < inorder.size(); i++){
            hmap[inorder[i]] = i;
        }
        return helper(preorder, inorder, 0, preorder.size() -1, 0, inorder.size() -1);
        
    }
private:
    unordered_map<int, int> hmap;
    
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int l1, int r1, int l2, int r2){
        int root_num = preorder[l1]; // current root num
        int root_idx = hmap[root_num]; // root num position in the inorder array
        TreeNode* root = new TreeNode(root_num);
        if(l2 == r2) return root;
        int nl = root_idx - l2;
        int nr = r2 - root_idx;
        if(l2 < root_idx){
            root->left = helper(preorder, inorder, l1 + 1, l1 + nl, l2, root_idx - 1);
        }
        if(root_idx < r2){
            root->right = helper(preorder, inorder, l1 + nl + 1, l1 + nl + nr, root_idx + 1, r2);
        }
        return root;
        
    }
};
// @lc code=end

