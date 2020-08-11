/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, vector<TreeNode*>> graph_;
        
        
        buildGraph(root, graph_);
        
        vector<int> result_;
        searchGraph(graph_, target, K, result_);
        
        return result_;
    }

private:
    void buildGraph(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>>& graph_){
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left){
                graph_[curr].push_back(curr->left);
                graph_[curr->left].push_back(curr);
                q.push(curr->left);
            }
            if(curr->right){
                graph_[curr].push_back(curr->right);
                graph_[curr->right].push_back(curr);
                q.push(curr->right);
            }
        }
    }
    
    void searchGraph(unordered_map<TreeNode*,
                     vector<TreeNode*>>& graph,
                     TreeNode* target, int K,
                     vector<int>& result){
        unordered_set<TreeNode*> visited_;
        queue<TreeNode*> q;
        
        q.push(target);
        visited_.insert(target);
        
        while(!q.empty() && K >= 0){
            queue<TreeNode*> next_q;
            while(!q.empty()){
                TreeNode* curr = q.front();
                
                q.pop();
                if(K == 0) result.push_back(curr->val);
                for(auto& child: graph[curr]){
                    if(visited_.count(child)) continue;
                    next_q.push(child);
                    visited_.insert(child);
                }
            }
            swap(next_q, q);
            K--;
        }
    }
};
// @lc code=end

