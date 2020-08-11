/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (42.94%)
 * Likes:    3549
 * Dislikes: 129
 * Total Accepted:    480.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int num = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                num += dfs(grid, i, j, visited);
            }
        }
        return num;
        
    }

private:
    bool dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return false;
        if(visited[i][j]) return false;
        visited[i][j] = true;
        if(grid[i][j] == '0') return false;
        dfs(grid, i + 1, j, visited);
        dfs(grid, i - 1, j, visited);
        dfs(grid, i, j + 1, visited);
        dfs(grid, i, j - 1, visited);
        
        return true;
    }
};
// @lc code=end

