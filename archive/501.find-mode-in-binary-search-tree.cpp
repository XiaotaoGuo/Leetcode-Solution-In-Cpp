/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
 *
 * https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (40.19%)
 * Likes:    636
 * Dislikes: 259
 * Total Accepted:    65.5K
 * Total Submissions: 162.2K
 * Testcase Example:  '[1,null,2,2]'
 *
 * Given a binary search tree (BST) with duplicates, find all the mode(s) (the
 * most frequently occurred element) in the given BST.
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than or equal
 * to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or
 * equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * 
 * For example:
 * Given BST [1,null,2,2],
 * 
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 * 
 * 
 * 
 * 
 * return [2].
 * 
 * Note: If a tree has more than one mode, you can return them in any order.
 * 
 * Follow up: Could you do that without using any extra space? (Assume that the
 * implicit stack space incurred due to recursion does not count).
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
    vector<int> findMode(TreeNode* root) {
        init = false;
        vector<int> result;
        max_count = 0;
        inorder(root, result);
        return result;
    }

private:
    int max_count;
    bool init;
    int prev;
    int count;
    
    void inorder(TreeNode* node, vector<int>& result){
        if(!node) return;
        inorder(node->left, result);
        
        if(!init){
            prev = node->val;
            count = 1;
            init = true;
        }
        else{
            if(node->val == prev){
                count++;
            }
            else{
                prev = node->val;
                count = 1;
            }
        }
        if(count == max_count){
            result.push_back(node->val);
        }
        else if(count > max_count){
            result.clear();
            result.push_back(node->val);
            max_count = count;
        }
        
        inorder(node->right, result);
    }
};
// @lc code=end

