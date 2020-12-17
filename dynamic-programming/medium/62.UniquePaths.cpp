/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (54.64%)
 * Likes:    4231
 * Dislikes: 230
 * Total Accepted:    566.1K
 * Total Submissions: 1M
 * Testcase Example:  '3\n7'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 *
 * How many possible unique paths are there?
 *
 *
 * Example 1:
 *
 *
 * Input: m = 3, n = 7
 * Output: 28
 *
 *
 * Example 2:
 *
 *
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the
 * bottom-right corner:
 * 1. Right -> Down -> Down
 * 2. Down -> Down -> Right
 * 3. Down -> Right -> Down
 *
 *
 * Example 3:
 *
 *
 * Input: m = 7, n = 3
 * Output: 28
 *
 *
 * Example 4:
 *
 *
 * Input: m = 3, n = 3
 * Output: 6
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= m, n <= 100
 * It's guaranteed that the answer will be less than or equal to 2 * 10^9.
 *
 *
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> counts(m + 1, std::vector<int>(n + 1, 0));
        counts[1][1] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                counts[i][j] += (counts[i - 1][j] + counts[i][j - 1]);
            }
        }
        return counts[m][n];
    }
};
// @lc code=end
