/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (44.45%)
 * Likes:    4558
 * Dislikes: 87
 * Total Accepted:    437.8K
 * Total Submissions: 966.5K
 * Testcase Example:
 * '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n5'
 *
 * Write an efficient algorithm that searches for a target value in an m x n
 * integer matrix. The matrix has the following properties:
 *
 *
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: matrix =
 * [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
 * target = 5
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: matrix =
 * [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
 * target = 20
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= n, m <= 300
 * -10^9 <= matix[i][j] <= 10^9
 * All the integers in each row are sorted in ascending order.
 * All the integers in each column are sorted in ascending order.
 * -10^9 <= target <= 10^9
 *
 *
 */

// @lc code=start
#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        std::pair<int, int> valid_range{0, m - 1};

        int left = 0;
        int right = m - 1;
        // filter out rows where all elements are larger than target
        while (left < right) {
            int mid = (left + right) / 2 + 1;
            if (matrix[mid][0] > target) {
                right = mid - 1;
                valid_range.second = right;
            } else if (matrix[mid][0] < target) {
                left = mid;
            } else {
                return true;
            }
        }

        // filter out rows where all elements are smaller than target
        left = 0;
        while (left < right) {
            int mid = (left + right) / 2;
            if (matrix[mid][n - 1] < target) {
                left = mid + 1;
                valid_range.first = left;
            } else if (matrix[mid][n - 1] > target) {
                right = mid;
            } else {
                return true;
            }
        }

        // for the rest rows, do a binary search for each row
        for (int r = valid_range.first; r <= valid_range.second; ++r) {
            left = 0;
            right = n - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (matrix[r][mid] < target) {
                    left = mid + 1;
                } else if (matrix[r][mid] > target) {
                    right = mid - 1;
                } else {
                    return true;
                }
            }
        }

        return false;
    }
};
// @lc code=end
