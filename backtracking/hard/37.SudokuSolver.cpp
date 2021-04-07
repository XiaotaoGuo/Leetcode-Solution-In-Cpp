/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (46.39%)
 * Likes:    2650
 * Dislikes: 103
 * Total Accepted:    231K
 * Total Submissions: 491.6K
 * Testcase Example:
 * '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * A sudoku solution must satisfy all of the following rules:
 *
 *
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 *
 *
 * The '.' character indicates empty cells.
 *
 *
 * Example 1:
 *
 *
 * Input: board =
 * [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
 * Output:
 * [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
 * Explanation: The input board is shown above and the only valid solution is
 * shown below:
 *
 *
 *
 *
 *
 * Constraints:
 *
 *
 * board.length == 9
 * board[i].length == 9
 * board[i][j] is a digit or '.'.
 * It is guaranteed that the input board has only one solution.
 *
 *
 */

// @lc code=start
#include <vector>

class Solution {
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        std::vector<std::vector<bool>> used(27, std::vector<bool>(10, false));

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                int block_index = int(i / 3.0) * 3 + j / 3;
                int row_index = 9 + i;
                int col_index = 18 + j;

                if (board[i][j] != '.') {
                    int index = board[i][j] - '0';
                    used[block_index][index] = true;
                    used[row_index][index] = true;
                    used[col_index][index] = true;
                }
            }
        }

        solve(board, used, 0, 0);
    }

private:
    bool solve(std::vector<std::vector<char>>& board,
               std::vector<std::vector<bool>>& used, int row, int col) {
        // reach the end of board
        if (row == 9) return true;

        if (board[row][col] != '.') {
            int r = row;
            int c = col;
            if (c == 8) {
                r++;
                c = 0;
            } else {
                c++;
            }

            if (solve(board, used, r, c)) {
                return true;
            } else {
                return false;
            }
        }

        // calcualte index of hashable
        int block_index = int(row / 3.0) * 3 + col / 3;

        int row_index = 9 + row;
        int col_index = 9 * 2 + col;

        for (int i = 1; i <= 9; ++i) {
            if (!used[block_index][i] && !used[row_index][i] &&
                !used[col_index][i]) {
                used[block_index][i] = true;
                used[row_index][i] = true;
                used[col_index][i] = true;
                board[row][col] = '0' + i;
                int r = row;
                int c = col;
                if (c == 8) {
                    r++;
                    c = 0;
                } else {
                    c++;
                }

                if (solve(board, used, r, c)) {
                    return true;
                }

                used[block_index][i] = false;
                used[row_index][i] = false;
                used[col_index][i] = false;
                board[row][col] = '.';
            }
        }

        return false;
    }
};
// @lc code=end
