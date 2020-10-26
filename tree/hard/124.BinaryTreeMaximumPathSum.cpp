/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 *
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (34.65%)
 * Likes:    4518
 * Dislikes: 333
 * Total Accepted:    421.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty binary tree, find the maximum path sum.
 *
 * For this problem, a path is defined as any node sequence from some starting
 * node to any node in the tree along the parent-child connections. The path
 * must contain at least one node and does not need to go through the root.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3]
 * Output: 6
 *
 *
 * Example 2:
 *
 *
 * Input: root = [-10,9,20,null,null,15,7]
 * Output: 42
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 3 * 10^4].
 * -1000 <= Node.val <= 1000
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
    int maxPathSum(TreeNode* root) {
        result = INT_MIN;
        dfs(root);
        return result;
    }

private:
    int result;
    int dfs(TreeNode* root) {
        if (!root) return 0;

        // max path sum that go through this node and its
        // left & right subtree
        int sum = root->val;

        // max path sum that go through this node and one of its subtree
        int left_path = root->val;
        int right_path = root->val;

        int left_sum = dfs(root->left);
        if (left_sum > 0) {
            sum += left_sum;
            left_path += left_sum;
        }

        int right_sum = dfs(root->right);
        if (right_sum > 0) {
            sum += right_sum;
            right_path += right_sum;
        }

        result = max(result, sum);
        return max(left_path, right_path);
    }
};
// @lc code=end
