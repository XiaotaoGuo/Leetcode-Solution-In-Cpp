/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (38.83%)
 * Likes:    1200
 * Dislikes: 76
 * Total Accepted:    152.2K
 * Total Submissions: 384.4K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * A sudoku solution must satisfy all of the following rules:
 * 
 * 
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 * 
 * 
 * Empty cells are indicated by the character '.'.
 * 
 * 
 * A sudoku puzzle...
 * 
 * 
 * ...and its solution numbers marked in red.
 * 
 * Note:
 * 
 * 
 * The given board contain only digits 1-9 and the character '.'.
 * You may assume that the given Sudoku puzzle will have a single unique
 * solution.
 * The given board size is always 9x9.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        cols_ = vector<vector<bool>>(9, vector<bool>(10, false));
        rows_ = vector<vector<bool>>(9, vector<bool>(10, false));
        boxes_ = vector<vector<bool>>(9, vector<bool>(10, false));
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0';
                    int idx_col = j;
                    int idx_row = i;
                    int idx_box = 3 * (i / 3) + j / 3;
                    cols_[idx_col][num] = true;
                    rows_[idx_row][num] = true;
                    boxes_[idx_box][num] = true;
                    
                }
            }
        }
        
        solve(board, 0, 0);
    }

private:
    vector<vector<bool>> cols_;
    vector<vector<bool>> rows_;
    vector<vector<bool>> boxes_;
    
    bool solve(vector<vector<char>>& board, int row, int col){
        if(row == 9) return true;
        int n_row = row, n_col = col;
        if(col < 8){
            n_col++;
        }
        else{
            n_row++;
            n_col = 0;
        }
        
        if(board[row][col] != '.'){
            return solve(board, n_row, n_col);
        }
        
        for(int i = 1; i < 10; i++){
            if(cols_[col][i] || rows_[row][i] || boxes_[3 * (row / 3) + (col / 3)][i]) continue;
            board[row][col] = '0' + i;
            cols_[col][i] = true;
            rows_[row][i] = true;
            boxes_[3 * (row / 3) + (col / 3)][i] = true;
            if(solve(board, n_row, n_col)) return true;
            board[row][col] = '.';
            cols_[col][i] = false;
            rows_[row][i] = false;
            boxes_[3 * (row / 3) + (col / 3)][i] = false;
        }
        return false;
    }
};
// @lc code=end

