/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (56.09%)
 * Likes:    3456
 * Dislikes: 179
 * Total Accepted:    250.2K
 * Total Submissions: 443.8K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given an n x n matrix where each of the rows and columns are sorted in
 * ascending order, return the k^th smallest element in the matrix.
 *
 * Note that it is the k^th smallest element in the sorted order, not the k^th
 * distinct element.
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
 * Output: 13
 * Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and
 * the 8^th smallest number is 13
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[-5]], k = 1
 * Output: -5
 *
 *
 *
 * Constraints:
 *
 *
 * n == matrix.length
 * n == matrix[i].length
 * 1 <= n <= 300
 * -10^9 <= matrix[i][j] <= -10^9
 * All the rows and columns of matrix are guaranteed to be sorted in
 * non-degreasing order.
 * 1 <= k <= n^2
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
public:
    int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1] + 1;
        while (left < right) {
            int mid = (left + right) / 2;
            int count = 0;
            for (int i = 0; i < matrix.size(); ++i) {
                count +=
                    std::upper_bound(matrix[i].begin(), matrix[i].end(), mid) -
                    matrix[i].begin();
            }
            if (count < k)
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }
};
// @lc code=end
