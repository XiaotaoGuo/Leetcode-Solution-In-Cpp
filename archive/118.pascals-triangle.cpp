/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (47.99%)
 * Likes:    950
 * Dislikes: 85
 * Total Accepted:    311.7K
 * Total Submissions: 635.3K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        // result.push_back({1});
        for(int i = 1; i <= numRows; i++){
            vector<int> currRow(i);
            currRow.front() = 1;
            currRow.back() = 1;
            for(int j = 1; j < currRow.size() - 1; j++){
                currRow[j] = result.back()[j-1] + result.back()[j];
            }
            result.push_back(currRow);
        }
        return result;
    }
};
// @lc code=end

