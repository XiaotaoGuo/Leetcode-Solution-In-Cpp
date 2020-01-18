/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
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

#include <string>
#include <vector>
using namespace std;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        if(!root) return "";
        result += to_string(root->val);
        result += ' ';
        result += serialize(root->left);
        result += serialize(root->right);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        vector<int> vecNode;
        int left = 0, right = 0;
        while(left < data.length()){
            // find the breakpoints between data
            while(right < data.length() && data[right] != ' ') right++;
            int val = stoi(data.substr(left, right - left));
            left = right + 1;
            right = left;
            vecNode.push_back(val);
        }

        return buildTree(vecNode, 0, vecNode.size() - 1);

    }

    TreeNode* buildTree(vector<int> vecNode, const int left, const int right){
        if(left < 0 || right >= vecNode.size() || left > right) return nullptr;
        int val = vecNode[left];
        TreeNode* root = new TreeNode(val);
        int idx = left;

        // find the first number is larger than the root
        while(idx <= right && vecNode[idx] <= val) idx++;
        root->left = buildTree(vecNode, left + 1, idx - 1);
        root->right = buildTree(vecNode, idx, right);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end

