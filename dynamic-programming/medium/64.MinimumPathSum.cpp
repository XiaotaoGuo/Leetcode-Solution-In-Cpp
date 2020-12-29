/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (54.94%)
 * Likes:    3995
 * Dislikes: 77
 * Total Accepted:    488.2K
 * Total Submissions: 876.5K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right, which minimizes the sum of all numbers along its
 * path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
 * Output: 7
 * Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[1,2,3],[4,5,6]]
 * Output: 12
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 200
 * 0 <= grid[i][j] <= 100
 * 
 * 
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        std::vector<int> current_row = grid[0];
        for (int i = 0; i < grid.size(); ++i) {
            // iteratively update min sum for each row, we only need the result of the last row
            calMinSum(grid, current_row, i);
        }
        return current_row.back();
    }

private:
    void calMinSum(const std::vector<std::vector<int>>& grid, std::vector<int>& current_row, int next_row_idx) {

        for (int i = 0; i < current_row.size(); ++i) {
            
            if (next_row_idx == 0) {
                // #1: if the first row, simply add min sum from left side
                current_row[i] += (i == 0? 0 : current_row[i - 1]); 
            }
            else if (i == 0) {
                // #2: if the first element, simply add min sum from upper grid
                current_row[i] += grid[next_row_idx][i];
            }
            else {
                // #3: general case: choose min sum between left and upper side
                current_row[i] = std::min(current_row[i], current_row[i - 1]) + grid[next_row_idx][i];
            }
        }
    }
};
// @lc code=end

