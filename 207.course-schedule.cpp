/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (39.32%)
 * Likes:    2439
 * Dislikes: 123
 * Total Accepted:    284.3K
 * Total Submissions: 712K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 * 
 * Example 1:
 * 
 * 
 * Input: 2, [[1,0]] 
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * Example 2:
 * 
 * 
 * Input: 2, [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 * 
 * 
 * Note:
 * 
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph_(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            graph_[prerequisites[i][1]].push_back(prerequisites[i][0]); 
        }
        
        vector<int> status_(numCourses, 0);
        
        for(int i = 0; i < numCourses; i++){
            if(dfs(graph_, i, status_)) return false;
        }
        return true;
    }

private:
    bool dfs(vector<vector<int>>& graph, int idx, vector<int>& status_){
        if(status_[idx] == 2) return false;
        if(status_[idx] == 1) return true;
        
        status_[idx] = 1;
        for(auto& idx2: graph[idx]){
            if(dfs(graph, idx2, status_)) return true;
        }
        status_[idx] = 2;
        
        return false;
    }
};
// @lc code=end

