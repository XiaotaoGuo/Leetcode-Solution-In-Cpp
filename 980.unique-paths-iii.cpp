/*
 * @lc app=leetcode id=980 lang=cpp
 *
 * [980] Unique Paths III
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int todos = 1;
        int si = -1, sj = -1;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0) todos++;
                else if(grid[i][j] == 1){
                    si = i;
                    sj = j;
                }
            }
        }
        
        return dfs(grid, si, sj, todos);
    }
    
private:
    int dfs(vector<vector<int>>& grid, int si, int sj, int todos){
        if(si < 0 || sj < 0 || si >= grid.size() || sj >= grid[0].size()) return 0;
        if(grid[si][sj] == -1) return 0;
        if(grid[si][sj] == 2) return todos == 0;
        grid[si][sj] = -1;
        int paths = dfs(grid, si + 1, sj, todos - 1) + 
                    dfs(grid, si - 1, sj, todos - 1) +
                    dfs(grid, si, sj + 1, todos - 1) +
                    dfs(grid, si, sj - 1, todos - 1);
        grid[si][sj] = 0;
        return paths;
    }
};
// @lc code=end

