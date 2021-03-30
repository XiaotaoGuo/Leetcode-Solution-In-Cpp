/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 *
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (44.75%)
 * Likes:    2855
 * Dislikes: 52
 * Total Accepted:    200.2K
 * Total Submissions: 442.4K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * Given an m x n integers matrix, return the length of the longest increasing
 * path in matrix.
 *
 * From each cell, you can either move in four directions: left, right, up, or
 * down. You may not move diagonally or move outside the boundary (i.e.,
 * wrap-around is not allowed).
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
 * Output: 4
 * Explanation: The longest increasing path is [1, 2, 6, 9].
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
 * Output: 4
 * Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally
 * is not allowed.
 *
 *
 * Example 3:
 *
 *
 * Input: matrix = [[1]]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 200
 * 0 <= matrix[i][j] <= 2^31 - 1
 *
 *
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
        directions =
            std::vector<std::pair<int, int>>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        max_lens = std::vector<std::vector<int>>(
            matrix.size(), std::vector<int>(matrix[0].size(), 0));

        int result = 1;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                result = std::max(result, dfs(matrix, i, j));
            }
        }

        return result;
    }

private:
    std::vector<std::pair<int, int>> directions;
    std::vector<std::vector<int>> max_lens;

    int dfs(const std::vector<std::vector<int>>& matrix, int row, int col) {
        if (max_lens[row][col] != 0) {
            return max_lens[row][col];
        }

        int len = 1;
        for (auto& dir : directions) {
            int r = row + dir.first;
            int c = col + dir.second;

            if (r < 0 || r >= matrix.size() || c < 0 || c >= matrix[0].size())
                continue;

            if (matrix[r][c] > matrix[row][col]) {
                len = std::max(len, 1 + dfs(matrix, r, c));
            }
        }

        max_lens[row][col] = len;

        return max_lens[row][col];
    }
};
// @lc code=end
