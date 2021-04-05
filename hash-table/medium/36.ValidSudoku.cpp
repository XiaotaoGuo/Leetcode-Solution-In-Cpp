/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (50.47%)
 * Likes:    2453
 * Dislikes: 550
 * Total Accepted:    463.8K
 * Total Submissions: 912.7K
 * Testcase Example:
 * '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be
 * validated according to the following rules:
 *
 *
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9
 * without repetition.
 *
 *
 * Note:
 *
 *
 * A Sudoku board (partially filled) could be valid but is not necessarily
 * solvable.
 * Only the filled cells need to be validated according to the mentioned
 * rules.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: board =
 * [["5","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: board =
 * [["8","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner
 * being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it
 * is invalid.
 *
 *
 *
 * Constraints:
 *
 *
 * board.length == 9
 * board[i].length == 9
 * board[i][j] is a digit or '.'.
 *
 *
 */

// @lc code=start
#include <vector>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::vector<bool> is_used(10, false);

        // iterate each block
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                is_used = std::vector<bool>(10, false);
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        int val = board[r * 3 + i][c * 3 + j] - '0';
                        if (val > 9 || val < 1) continue;
                        if (is_used[val]) {
                            return false;
                        }
                        is_used[val] = true;
                    }
                }
            }
        }

        // iterate each row
        for (int r = 0; r < 9; r++) {
            is_used = std::vector<bool>(10, false);
            for (int c = 0; c < 9; ++c) {
                int val = board[r][c] - '0';
                if (val > 9 || val < 1) continue;
                if (is_used[val]) {
                    return false;
                }
                is_used[val] = true;
            }
        }

        // iterate each coloumn
        for (int c = 0; c < 9; c++) {
            is_used = std::vector<bool>(10, false);
            for (int r = 0; r < 9; ++r) {
                int val = board[r][c] - '0';
                if (val > 9 || val < 1) continue;
                if (is_used[val]) {
                    return false;
                }
                is_used[val] = true;
            }
        }

        return true;
    }
};
// @lc code=end
