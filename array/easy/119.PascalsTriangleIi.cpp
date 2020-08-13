/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (48.78%)
 * Likes:    987
 * Dislikes: 201
 * Total Accepted:    316.3K
 * Total Submissions: 626.2K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the k^th index row of the
 * Pascal's triangle.
 * 
 * Note that the row index starts from 0.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: [1,3,3,1]
 * 
 * 
 * Follow up:
 * 
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 */

// @lc code=start
#include <vector>

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> row;
        for (int i = 0; i <= rowIndex; i++) {
            std::vector<int> nextRow(i + 1, 1);
            for (int j = 1; j < nextRow.size() - 1; j++) {
                nextRow[j] = row[j - 1] + row[j];
            }
            row = nextRow;
        }

        return row;
    }
};
// @lc code=end

