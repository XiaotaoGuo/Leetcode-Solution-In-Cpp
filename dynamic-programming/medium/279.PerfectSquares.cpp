/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (47.81%)
 * Likes:    3693
 * Dislikes: 222
 * Total Accepted:    358.1K
 * Total Submissions: 740.1K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 *
 * Example 1:
 *
 *
 * Input: n = 12
 * Output: 3
 * Explanation: 12 = 4 + 4 + 4.
 *
 * Example 2:
 *
 *
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 */

// @lc code=start
#include <limits.h>

#include <cmath>
#include <vector>
class Solution {
public:
    int numSquares(int n) {
        std::vector<int> num_squares(n + 1, INT_MAX);
        num_squares[0] = 0;

        for (int i = 1; i <= std::sqrt(n); ++i) {
            for (int j = 1; j <= n; j++) {
                if (j - i * i >= 0) {
                    num_squares[j] =
                        std::min(num_squares[j], 1 + num_squares[j - i * i]);
                }
            }
        }
        return num_squares[n];
    }
};
// @lc code=end
