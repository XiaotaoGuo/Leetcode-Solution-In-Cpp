/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (35.27%)
 * Likes:    1130
 * Dislikes: 132
 * Total Accepted:    264.5K
 * Total Submissions: 744.8K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 13
 * Output: false
 * 
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        if(n == 0) return false;
        if(matrix[0][0] > target) return false;
        int row = 0, col = 0;
        while(row < m){
            if(matrix[row][n - 1] >= target) break;
            row++;
        }
        if(row == m) return false;
        int l = 0, r = n - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return false;
    }
};
// @lc code=end

