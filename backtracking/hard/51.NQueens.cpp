/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (49.49%)
 * Likes:    2832
 * Dislikes: 104
 * Total Accepted:    249.5K
 * Total Submissions: 496.5K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n
 * chessboard such that no two queens attack each other.
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space,
 * respectively.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4
 * Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: [["Q"]]
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
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> result;
        std::unordered_set<int> col_used;
        std::unordered_set<int> diag1;
        std::unordered_set<int> diag2;
        std::vector<std::string> curr;
        dfs(0, n, col_used, diag1, diag2, curr, result);
        return result;
    }

private:
    void dfs(int row, int n, std::unordered_set<int>& col_used,
             std::unordered_set<int>& diag1, std::unordered_set<int>& diag2,
             std::vector<std::string>& curr,
             std::vector<std::vector<std::string>>& result) {
        if (row == n) {
            result.push_back(curr);
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
            curr.push_back(curr_row);
            dfs(row + 1, n, col_used, diag1, diag2, curr, result);
            curr.pop_back();
            curr_row[col] = '.';
            col_used.erase(col);
            diag1.erase(col - row);
            diag2.erase(col + row);
        }
    }
};
// @lc code=end
