/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (32.43%)
 * Likes:    2287
 * Dislikes: 119
 * Total Accepted:    338K
 * Total Submissions: 1M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty()) return false;
        if(word.length() == 0) return true;
        m = board.size();
        n = board[0].size();
        target = word;
        vector<vector<bool>> flag = vector<vector<bool>>(m, vector<bool>(n, false));
        bool ans = false;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dfs(board, flag, i, j, 0, ans);
                if(ans) return ans;
            }
        }
        return false;
    }

private:
    int m;
    int n;
    string target;
    void dfs(vector<vector<char>>& board, 
             vector<vector<bool>>& flag,
             int x, int y, int idx, bool& ans){
        if(x < 0 || x == m || y < 0 || y == n || board[x][y] != target[idx] || flag[x][y]) return;
        idx++;
        if(idx == target.length()){
            ans = true;
            return;
        }
        flag[x][y] = true;
        dfs(board, flag, x + 1, y, idx, ans);
        if(ans) return;
        dfs(board, flag, x - 1, y, idx, ans);
        if(ans) return;
        dfs(board, flag, x, y - 1, idx, ans);
        if(ans) return;
        dfs(board, flag, x, y + 1, idx, ans);
        if(ans) return;
        flag[x][y] = false;
    }
};
// @lc code=end

