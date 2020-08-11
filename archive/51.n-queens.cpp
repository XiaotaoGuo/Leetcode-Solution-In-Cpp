/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (41.48%)
 * Likes:    1269
 * Dislikes: 58
 * Total Accepted:    167K
 * Total Submissions: 394.2K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: [
 * ⁠[".Q..",  // Solution 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // Solution 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        cols_ = vector<bool>(n, false);
        left_diag_ = vector<bool>(2 * n, false);
        right_diag_ = vector<bool>(2 * n, false);
        
        vector<string> board = vector<string>(n, string(n, '.'));
        vector<vector<string>> result;
        dfs(board, 0, result);
        
        return result;
        
        
    }

private:
    vector<bool> cols_;
    vector<bool> left_diag_;
    vector<bool> right_diag_;
    
    void dfs(vector<string>& board, int row, vector<vector<string>>& result){
        int n = board.size();
        if(row == n){
            result.push_back(board);
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

