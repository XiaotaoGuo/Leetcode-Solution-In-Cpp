/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (44.64%)
 * Likes:    2480
 * Dislikes: 275
 * Total Accepted:    274.6K
 * Total Submissions: 607.3K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 *
 * For example, given the following triangle
 *
 *
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 *
 *
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 * Note:
 *
 * Bonus point if you are able to do this using only O(n) extra space, where n
 * is the total number of rows in the triangle.
 *
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        int n = triangle.size();
        std::vector<int> min_sum{triangle[0][0]};
        int current_min_sum = min_sum.front();
        for (int i = 1; i < n; i++) {
            std::vector<int> next_level(i + 1, 0);

            // for the first and last element in each level, there is only 1
            // possible path
            next_level.front() = triangle[i].front() + min_sum.front();
            next_level.back() = triangle[i].back() + min_sum.back();

            current_min_sum = std::min(next_level.front(), next_level.back());
            for (int j = 1; j < i; j++) {
                next_level[j] =
                    triangle[i][j] + std::min(min_sum[j - 1], min_sum[j]);
                current_min_sum = std::min(current_min_sum, next_level[j]);
            }
            min_sum = next_level;
        }

        return current_min_sum;
    }
};
// @lc code=end
