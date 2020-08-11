/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (53.78%)
 * Likes:    350
 * Dislikes: 129
 * Total Accepted:    113.7K
 * Total Submissions: 208.7K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown below.
 * [
 * [".Q..",  // Solution 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // Solution 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
        cols_ = vector<bool>(n, false);
        left_diag_ = vector<bool>(2 * n, false);
        right_diag_ = vector<bool>(2 * n, false);
        count = 0;
        
        vector<string> board = vector<string>(n, string(n, '.'));
        dfs(board, 0, count);
        
        return count;
        
        
    }

private:
    vector<bool> cols_;
    vector<bool> left_diag_;
    vector<bool> right_diag_;
    int count;
    
    void dfs(vector<string>& board, int row, int& result){
        int n = board.size();
        if(row == n){
            result++;
            return;
        }
        
        for(int col = 0; col < n; col++){
            int idx_left_diag = (n - 1 - row + col);
            int idx_right_diag = row + col;
            if(cols_[col] || left_diag_[idx_left_diag] || right_diag_[idx_right_diag]) continue;
            cols_[col] = true;
            left_diag_[idx_left_diag] = true;
            right_diag_[idx_right_diag] = true;
            board[row][col] = 'Q';
            dfs(board, row + 1, result);
            cols_[col] = false;
            left_diag_[idx_left_diag] = false;
            right_diag_[idx_right_diag] = false;
            board[row][col] = '.';
        }
    }
};
// @lc code=end

