/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (42.26%)
 * Likes:    1190
 * Dislikes: 42
 * Total Accepted:    272.5K
 * Total Submissions: 631.8K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given the below binary tree and sum = 22,
 * 
 * 
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \    / \
 * 7    2  5   1
 * 
 * 
 * Return:
 * 
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
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

#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> curr;
        dfs(root, curr, sum, result);
        return result;
    }

private:
    void dfs(TreeNode* node, vector<int>& curr, int target, vector<vector<int>>& result){
        if(!node) return;
        target -= node->val;
        curr.push_back(node->val);
        if(!node->left && !node->right){
            if(target == 0) result.push_back(curr);
        }
        dfs(node->left, curr, target, result);
        dfs(node->right, curr, target, result);
        curr.pop_back();
    }
};
// @lc code=end

