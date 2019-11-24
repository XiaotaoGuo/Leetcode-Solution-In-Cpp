/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (48.51%)
 * Likes:    655
 * Dislikes: 92
 * Total Accepted:    161.8K
 * Total Submissions: 324.1K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate a square matrix filled with elements
 * from 1 to n^2 in spiral order.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int count = 1;
        generate(matrix, 0, 0, n - 1, n - 1, count);
        return matrix;
        
    }

private:
    void generate(vector<vector<int>>& matrix, int top, int left, int bottom, int right, int& count){
        if(top < bottom && left < right){
            for(int i = left; i < right; i++){
                matrix[top][i] = count;
                count++;
            }
            for(int i = top; i < bottom; i++){
                matrix[i][right] = count;
                count++;
            }
            for(int i = right; i > left; i--){
                matrix[bottom][i] = count;
                count++;
            }
            for(int i = bottom; i > top; i--){
                matrix[i][left] = count;
                count++;
            }
        }
        else if(top < bottom && left == right){
            for(int i = top; i <= bottom; i++){
                matrix[i][left] = count;
                count++;
            }
        }
        else if(top == bottom && left < right){
            for(int i = left; i <= right; i++){
                matrix[top][i] = count;
                count++;
            }
        }
        else if(top == bottom && left == right){
            matrix[top][left] = count;
            count++;
        }
        else{
            return;
        }
        top++;
        left++;
        right--;
        bottom--;
        generate(matrix, top, left, bottom, right, count);
    }
};
// @lc code=end

