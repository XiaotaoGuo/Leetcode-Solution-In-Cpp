/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 *
 * https://leetcode.com/problems/path-sum-iii/description/
 *
 * algorithms
 * Easy (46.03%)
 * Likes:    3922
 * Dislikes: 306
 * Total Accepted:    214.5K
 * Total Submissions: 454.2K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * You are given a binary tree in which each node contains an integer value.
 * 
 * Find the number of paths that sum to a given value.
 * 
 * The path does not need to start or end at the root or a leaf, but it must go
 * downwards
 * (traveling only from parent nodes to child nodes).
 * 
 * The tree has no more than 1,000 nodes and the values are in the range
 * -1,000,000 to 1,000,000.
 * 
 * Example:
 * 
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 * 
 * ⁠     10
 * ⁠    /  \
 * ⁠   5   -3
 * ⁠  / \    \
 * ⁠ 3   2   11
 * ⁠/ \   \
 * 3  -2   1
 * 
 * Return 3. The paths that sum to 8 are:
 * 
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3. -3 -> 11
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
// method 1
// public:
//     int pathSum(TreeNode* root, int sum) {
//         if (root == nullptr) return 0;
//         return pathSumUp(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
//     }
    
// private:
//     int pathSumUp(TreeNode* node, int current_sum, int target_sum) {
//         if (node == nullptr) return 0;
//         current_sum += node->val;
//         return (current_sum == target_sum) + pathSumUp(node->left, current_sum, target_sum) + pathSumUp(node->right, current_sum, target_sum);
//     }
    
// method 2
public:
    int pathSum(TreeNode* root, int sum) {
        ans = 0;
        prefix_sum_count[0] = 1;
        
        dfs(root, 0, sum);
        return ans;
    }
    
private:
    std::unordered_map<int, int> prefix_sum_count;
    int ans;
    
    void dfs(TreeNode* node, int current_sum, int target_sum) {
        if (node == nullptr) return;
        current_sum += node->val;
        ans += prefix_sum_count[current_sum - target_sum];
        prefix_sum_count[current_sum]++;
        dfs(node->left, current_sum, target_sum);
        dfs(node->right, current_sum, target_sum);
        prefix_sum_count[current_sum]--;
    }
};
// @lc code=end

