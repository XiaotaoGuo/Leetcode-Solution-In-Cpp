/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (31.50%)
 * Likes:    1524
 * Dislikes: 465
 * Total Accepted:    288.2K
 * Total Submissions: 900K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()) return res;
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, left = 0, bottom = m - 1, right = n - 1;
        sprial(matrix, top, left, bottom, right, res);
        return res;
    }

void sprial(vector<vector<int>>& matrix, int top, int left, int bottom, int right, vector<int>& res){
    if(left < right && top < bottom){
        for(int i = left; i < right; i++){
            res.push_back(matrix[top][i]);
        }
        for(int i = top; i < bottom; i++){
            res.push_back(matrix[i][right]);
        }
        for(int i = right; i > left; i--){
            res.push_back(matrix[bottom][i]);
        }
        for(int i = bottom; i > top; i--){
            res.push_back(matrix[i][left]);
        }
    }
    else if(left == right && top == bottom){
        res.push_back(matrix[top][left]);
    }
    else if(left < right && top == bottom){
        for(int i = left; i <= right; i++){
            res.push_back(matrix[top][i]);
        }
    }
    else if(top < bottom && left == right){
        for(int i = top; i <= bottom; i++){
            res.push_back(matrix[i][left]);
        }
    }
    else{
        return;
    }
    top++; left++; bottom--; right--;
    sprial(matrix, top, left, bottom, right, res);
    
}
};
// @lc code=end

