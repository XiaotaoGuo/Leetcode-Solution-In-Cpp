/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (29.33%)
 * Likes:    2648
 * Dislikes: 767
 * Total Accepted:    293.3K
 * Total Submissions: 984.9K
 * Testcase Example:
 * '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given an m x n matrix board containing 'X' and 'O', capture all regions
 * surrounded by 'X'.
 *
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 *
 *
 * Example 1:
 *
 *
 * Input: board =
 * [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
 * Output:
 * [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
 * Explanation: Surrounded regions should not be on the border, which means
 * that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that
 * is not on the border and it is not connected to an 'O' on the border will be
 * flipped to 'X'. Two cells are connected if they are adjacent cells connected
 * horizontally or vertically.
 *
 *
 * Example 2:
 *
 *
 * Input: board = [["X"]]
 * Output: [["X"]]
 *
 *
 *
 * Constraints:
 *
 *
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 200
 * board[i][j] is 'X' or 'O'.
 *
 *
 */

// @lc code=start
#include <vector>

class Solution {
public:
    void solve(std::vector<std::vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j] && board[i][j] == 'O') {
                    bool is_surrounded = true;
                    std::vector<std::pair<int, int>> grid_list;
                    dfs(board, i, j, visited, is_surrounded, grid_list);

                    if (is_surrounded) {
                        for (auto grid : grid_list) {
                            board[grid.first][grid.second] = 'X';
                        }
                    }
                }
            }
        }
    }

private:
    void dfs(std::vector<std::vector<char>>& board, int row, int col,
             std::vector<std::vector<bool>>& visited, bool& is_surrounded,
             std::vector<std::pair<int, int>>& grid_list) {
        if (row == 0 || row == board.size() - 1 || col == 0 ||
            col == board[0].size() - 1) {
            is_surrounded = false;
        }
        visited[row][col] = true;
        grid_list.push_back({row, col});
        std::vector<std::pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (auto& dir : dirs) {
            int r = row + dir.first;
            int c = col + dir.second;
            if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) {
                continue;
            }

            if (!visited[r][c] && board[r][c] == 'O') {
                dfs(board, r, c, visited, is_surrounded, grid_list);
            }
        }
    }
};
// @lc code=end
