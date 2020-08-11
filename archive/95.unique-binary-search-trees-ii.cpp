/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (37.03%)
 * Likes:    1555
 * Dislikes: 130
 * Total Accepted:    157.9K
 * Total Submissions: 422.1K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
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
    vector<TreeNode*> generateTrees(int n) {
        if(n <= 0) return {};
        vector<TreeNode*> trees;
        for(int i = 1; i <= n; i++){
            vector<TreeNode*> currTrees = generateOneTree(i, 1, n);
            trees.insert(trees.end(), currTrees.begin(), currTrees.end());
        }
        return trees;
    }

private:
    vector<TreeNode*> generateOneTree(int mid, int l, int r){     
        
        if (mid == l && mid == r) return vector<TreeNode*>{new TreeNode(mid)};
        vector<TreeNode*> roots;
        vector<TreeNode*> candidatesLeft;
        vector<TreeNode*> candidatesRight;
        if(l == mid){
            for(int j = mid + 1; j <= r; j++){
                candidatesRight = generateOneTree(j, mid + 1, r);
                for(int i = 0; i < candidatesRight.size(); i++){
                    TreeNode* root = new TreeNode(mid);
                    root->right = candidatesRight[i];
                    roots.push_back(root);
                }
            }
            
        }
        else if(r == mid){
            for(int i = l; i < mid; i++){
                candidatesLeft = generateOneTree(i, l, mid-1);
                for(int i = 0; i < candidatesLeft.size(); i++){
                    TreeNode* root = new TreeNode(mid);
                    root->left = candidatesLeft[i];
                    roots.push_back(root);
                }
            }
            
        }
        else{
            for(int i = l; i < mid; i++){
                for(int j = mid + 1; j <= r; j++){
                    candidatesLeft = generateOneTree(i, l, mid-1);
                    candidatesRight = generateOneTree(j, mid + 1, r);
                    for(int i = 0; i < candidatesLeft.size(); i++){
                        for(int j = 0; j < candidatesRight.size(); j++){
                            TreeNode* root = new TreeNode(mid);
                            root->left = candidatesLeft[i];
                            root->right = candidatesRight[j];
                            roots.push_back(root);
                        }
                    }
                }
            }
            
            
        }
        
        return roots;
    }
};
// @lc code=end

