/*
 * @lc app=leetcode id=988 lang=cpp
 *
 * [988] Smallest String Starting From Leaf
 *
 * https://leetcode.com/problems/smallest-string-starting-from-leaf/description/
 *
 * algorithms
 * Medium (45.00%)
 * Likes:    202
 * Dislikes: 42
 * Total Accepted:    15.7K
 * Total Submissions: 35K
 * Testcase Example:  '[0,1,2,3,4,3,4]'
 *
 * Given the root of a binary tree, each node has a value from 0 to 25
 * representing the letters 'a' to 'z': a value of 0 represents 'a', a value of
 * 1 represents 'b', and so on.
 * 
 * Find the lexicographically smallest string that starts at a leaf of this
 * tree and ends at the root.
 * 
 * (As a reminder, any shorter prefix of a string is lexicographically smaller:
 * for example, "ab" is lexicographically smaller than "aba".  A leaf of a node
 * is a node that has no children.)
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: [0,1,2,3,4,3,4]
 * Output: "dba"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: [25,1,3,1,3,0,2]
 * Output: "adz"
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: [2,2,1,null,1,0,null,0]
 * Output: "abc"
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes in the given tree will be between 1 and 8500.
 * Each node in the tree will have a value between 0 and 25.
 * 
 * 
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
#include<string>
using namespace std;
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        str = "";
        dfs(root, "");
        return str;
    }
private:
    string str;
    void dfs(TreeNode* node, string str_){
        if(!node) return;
        string curr_str = char('a'+node->val) + str_;
        if(!node->left && !node->right){
            if(str == "") str = curr_str;
            else if(str_comp(curr_str, str)) str = curr_str;
            return;
        }
        
        if(node->right) dfs(node->right, curr_str);
        if(node->left) dfs(node->left, curr_str);
    }
    
    bool str_comp(string str1, string str2){
        // return true if str1 < str2
        int pos = 0;
        if(str1 == str2) return false;
        while(pos < str1.length() && pos < str2.length()){
            if(str1[pos] < str2[pos]) return true;
            if(str1[pos] > str2[pos]) return false;
            pos++;
        }
        if(pos < str2.length()) return true;
        return false;
    }
};
// @lc code=end

