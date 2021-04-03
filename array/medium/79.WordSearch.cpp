/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (36.75%)
 * Likes:    5438
 * Dislikes: 240
 * Total Accepted:    637.6K
 * Total Submissions: 1.7M
 * Testcase Example:
 * '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given an m x n grid of characters board and a string word, return true if
 * word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring. The same
 * letter cell may not be used more than once.
 *
 *
 * Example 1:
 *
 *
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCCED"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "SEE"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCB"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * m == board.length
 * n = board[i].length
 * 1 <= m, n <= 6
 * 1 <= word.length <= 15
 * board and word consists of only lowercase and uppercase English letters.
 *
 *
 *
 * Follow up: Could you use search pruning to make your solution faster with a
 * larger board?
 *
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        is_used = std::vector<std::vector<bool>>(
            board.size(), std::vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    std::vector<std::pair<int, int>> directions;
    std::vector<std::vector<bool>> is_used;

    bool dfs(const std::vector<std::vector<char>>& board, int row, int col,
             const std::string& word, int index) {
        if (index == word.size()) {
            return true;
        }

        if (row >= board.size() || row < 0 || col >= board[0].size() ||
            col < 0 || is_used[row][col] || board[row][col] != word[index]) {
            return false;
        }

        is_used[row][col] = true;

        for (int i = 0; i < 4; i++) {
            if (dfs(board, row + directions[i].first,
                    col + directions[i].second, word, index + 1)) {
                return true;
            }
        }

        is_used[row][col] = false;

        return false;
    }
};
// @lc code=end
