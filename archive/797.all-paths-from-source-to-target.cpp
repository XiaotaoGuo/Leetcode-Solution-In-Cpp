/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 *
 * https://leetcode.com/problems/all-paths-from-source-to-target/description/
 *
 * algorithms
 * Medium (71.64%)
 * Likes:    488
 * Dislikes: 41
 * Total Accepted:    36.5K
 * Total Submissions: 50.7K
 * Testcase Example:  '[[1,2],[3],[3],[]]'
 *
 * Given a directed, acyclic graph of N nodes.  Find all possible paths from
 * node 0 to node N-1, and return them in any order.
 * 
 * The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.
 * graph[i] is a list of all nodes j for which the edge (i, j) exists.
 * 
 * 
 * Example:
 * Input: [[1,2], [3], [3], []] 
 * Output: [[0,1,3],[0,2,3]] 
 * Explanation: The graph looks like this:
 * 0--->1
 * |    |
 * v    v
 * 2--->3
 * There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes in the graph will be in the range [2, 15].
 * You can print different paths in any order, but you should keep the order of
 * nodes inside one path.
 * 
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path{0};
        dfs(graph, path, result);
        return result;
    }
    
private:
    void dfs(const vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& result){
        int curr = path.back();
        if(curr == graph.size() - 1){
            result.push_back(path);
            return;
        }
        for(auto next: graph[curr]){
            path.push_back(next);
            dfs(graph, path, result);
            path.pop_back();
        }
    }
};
// @lc code=end

