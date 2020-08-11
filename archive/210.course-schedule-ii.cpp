/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 *
 * https://leetcode.com/problems/course-schedule-ii/description/
 *
 * algorithms
 * Medium (36.32%)
 * Likes:    1356
 * Dislikes: 95
 * Total Accepted:    188.9K
 * Total Submissions: 509.9K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, return
 * the ordering of courses you should take to finish all courses.
 * 
 * There may be multiple correct orders, you just need to return one of them.
 * If it is impossible to finish all courses, return an empty array.
 * 
 * Example 1:
 * 
 * 
 * Input: 2, [[1,0]] 
 * Output: [0,1]
 * Explanation: There are a total of 2 courses to take. To take course 1 you
 * should have finished   
 * course 0. So the correct course order is [0,1] .
 * 
 * Example 2:
 * 
 * 
 * Input: 4, [[1,0],[2,0],[3,1],[3,2]]
 * Output: [0,1,2,3] or [0,2,1,3]
 * Explanation: There are a total of 4 courses to take. To take course 3 you
 * should have finished both     
 * ⁠            courses 1 and 2. Both courses 1 and 2 should be taken after you
 * finished course 0. 
 * So one correct course order is [0,1,2,3]. Another correct ordering is
 * [0,2,1,3] .
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

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph_(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            graph_[prerequisites[i][1]].push_back(prerequisites[i][0]); 
        }
        
        // 0 - unvisited, 1 - visiting, 2 - visited  
        vector<int> status_(numCourses, 0);
        vector<int> result_;
        
        for(int i = 0; i < numCourses; i++){
            if(dfs(graph_, i, status_, result_)) return {};
        }
        
        reverse(result_.begin(), result_.end());
        
        return result_;
    }

private:
    bool dfs(vector<vector<int>>& graph, int idx, vector<int>& status_, vector<int>& result){
        // no loops in this selection
        if(status_[idx] == 2){
            return false;
        }
        
        // loops detected, no possible schedule
        if(status_[idx] == 1) return true;
        
        status_[idx] = 1;
        for(auto& idx2: graph[idx]){
            if(dfs(graph, idx2, status_, result)) return true;
        }
        status_[idx] = 2;
        result.push_back(idx);
        
        return false;
    }
};
// @lc code=end

