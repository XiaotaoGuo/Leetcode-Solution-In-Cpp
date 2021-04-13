/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (60.03%)
 * Likes:    800
 * Dislikes: 182
 * Total Accepted:    159.6K
 * Total Submissions: 263.3K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n
 * chessboard such that no two queens attack each other.
 *
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 9
 *
 *
 */

// @lc code=start
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
    int totalNQueens(int n) {
        int result = 0;
        std::unordered_set<int> col_used;
        std::unordered_set<int> diag1;
        std::unordered_set<int> diag2;
        dfs(0, n, col_used, diag1, diag2, result);
        return result;
    }

private:
    void dfs(int row, int n, std::unordered_set<int>& col_used,
             std::unordered_set<int>& diag1, std::unordered_set<int>& diag2,
             int& result) {
        if (row == n) {
            result++;
            return;
        }

        std::string curr_row(n, '.');
        for (int col = 0; col < n; ++col) {
            if (col_used.count(col) || diag1.count(col - row) ||
                diag2.count(col + row))
                continue;
            curr_row[col] = 'Q';
            col_used.insert(col);
            diag1.insert(col - row);
            diag2.insert(col + row);
            dfs(row + 1, n, col_used, diag1, diag2, result);
            col_used.erase(col);
            diag1.erase(col - row);
            diag2.erase(col + row);
        }
    }
};
// @lc code=end
