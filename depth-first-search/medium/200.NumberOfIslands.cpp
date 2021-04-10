/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (48.98%)
 * Likes:    8116
 * Dislikes: 241
 * Total Accepted:    1M
 * Total Submissions: 2M
 * Testcase Example:
 * '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) and
 * '0's (water), return the number of islands.
 *
 * An island is surrounded by water and is formed by connecting adjacent lands
 * horizontally or vertically. You may assume all four edges of the grid are
 * all surrounded by water.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 300
 * grid[i][j] is '0' or '1'.
 *
 *
 */

// @lc code=start

#include <vector>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    result++;
                    visited[i][j] = true;
                    dfs(grid, i, j, visited);
                }
            }
        }

        return result;
    }

private:
    void dfs(const std::vector<std::vector<char>>& grid, int row, int col,
             std::vector<std::vector<bool>>& visited) {
        std::vector<std::pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (auto& dir : dirs) {
            int r = row + dir.first;
            int c = col + dir.second;

            if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) {
                continue;
            }

            if (grid[r][c] == '1' && !visited[r][c]) {
                visited[r][c] = true;
                dfs(grid, r, c, visited);
            }
        }
    }
};
// @lc code=end
