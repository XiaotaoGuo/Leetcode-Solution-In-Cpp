/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (35.89%)
 * Likes:    3618
 * Dislikes: 648
 * Total Accepted:    478.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [1,2,3,6,9,8,7,4,5]
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 *
 *
 *
 * Constraints:
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 10
 * -100 <= matrix[i][j] <= 100
 *
 *
 */

// @lc code=start
#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> result;
        int m = matrix.size();
        int n = matrix[0].size();
        int row1 = 0;
        int row2 = m - 1;
        int col1 = 0;
        int col2 = n - 1;
        while (row1 <= row2 && col1 <= col2) {
            for (int c = col1; c <= col2; ++c) {
                result.push_back(matrix[row1][c]);
            }
            for (int r = row1 + 1; r <= row2; ++r) {
                result.push_back(matrix[r][col2]);
            }
            if (row1 < row2 && col1 < col2) {
                for (int c = col2 - 1; c > col1; --c) {
                    result.push_back(matrix[row2][c]);
                }
                for (int r = row2; r > row1; --r) {
                    result.push_back(matrix[r][col1]);
                }
            }
            row1++;
            row2--;
            col1++;
            col2--;
        }

        return result;
    }
};
// @lc code=end
