/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (57.70%)
 * Likes:    1587
 * Dislikes: 127
 * Total Accepted:    246.6K
 * Total Submissions: 424.4K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate an n x n matrix filled with elements
 * from 1 to n^2 in spiral order.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3
 * Output: [[1,2,3],[8,9,4],[7,6,5]]
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: [[1]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 20
 *
 *
 */

// @lc code=start
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> result(n, std::vector<int>(n, 0));
        int row = 0;
        int step = 1;
        while (row < n / 2) {
            for (int i = row; i < n - row - 1; ++i) {
                result[row][i] = step;
                step++;
            }
            for (int i = row; i < n - row - 1; ++i) {
                result[i][n - row - 1] = step;
                step++;
            }
            for (int i = n - 1 - row; i > row; --i) {
                result[n - row - 1][i] = step;
                step++;
            }
            for (int i = n - 1 - row; i > row; --i) {
                result[i][row] = step;
                step++;
            }
            row++;
        }

        if (n % 2 == 1) {
            result[row][row] = step;
        }

        return result;
    }
};
// @lc code=end
