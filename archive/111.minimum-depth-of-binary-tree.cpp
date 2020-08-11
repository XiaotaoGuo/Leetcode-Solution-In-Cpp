/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (35.90%)
 * Likes:    912
 * Dislikes: 523
 * Total Accepted:    343.1K
 * Total Submissions: 948K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * return its minimum depth = 2.
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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int min_dep = INT_MAX;
        int dep = 0;
        calDepth(root, dep, min_dep);
        return min_dep;
        
    }

private:
    void calDepth(TreeNode* node, int dep, int& min_dep){
        if(!node){
            return;
        }
        dep++;
        if(dep > min_dep) return;
        if(!node->left && !node->right){
            min_dep = min(min_dep, dep);
        }
        calDepth(node->left, dep, min_dep);
        calDepth(node->right, dep, min_dep);
        
    }
};
// @lc code=end

