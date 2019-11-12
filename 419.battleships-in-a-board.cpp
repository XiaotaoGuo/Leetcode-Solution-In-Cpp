/*
 * @lc app=leetcode id=419 lang=cpp
 *
 * [419] Battleships in a Board
 *
 * https://leetcode.com/problems/battleships-in-a-board/description/
 *
 * algorithms
 * Medium (66.67%)
 * Likes:    505
 * Dislikes: 378
 * Total Accepted:    72K
 * Total Submissions: 107.5K
 * Testcase Example:  '[["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]'
 *
 * Given an 2D board, count how many battleships are in it. The battleships are
 * represented with 'X's, empty slots are represented with '.'s. You may assume
 * the following rules:
 * 
 * 
 * You receive a valid board, made of only battleships or empty slots.
 * Battleships can only be placed horizontally or vertically. In other words,
 * they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1
 * column), where N can be of any size.
 * At least one horizontal or vertical cell separates between two battleships -
 * there are no adjacent battleships.
 * 
 * 
 * Example:
 * X..X
 * ...X
 * ...X
 * 
 * In the above board there are 2 battleships.
 * 
 * Invalid Example:
 * ...X
 * XXXX
 * ...X
 * 
 * This is an invalid board that you will not receive - as battleships will
 * always have a cell separating between them.
 * 
 * Follow up:Could you do it in one-pass, using only O(1) extra memory and
 * without modifying the value of the board?
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if(board.empty()) return 0;
        m = board.size();
        n = board[0].size();
        count = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dfs(board, visited, i, j);
            }
        }
        return count;
        
    }

private:
    int m;
    int n;
    int count;
    void dfs(const vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n) return;
        if(visited[i][j]) return;
        if(board[i][j] == 'X'){
            visited[i][j] = true;
            count++;
            int ni = i+1;
            int nj = j+1;
            while(ni < m && board[ni][j] == 'X'){
                visited[ni][j] = true;
                ni++;
            }
            while(nj < n && board[i][nj] == 'X'){
                visited[i][nj] = true;
                nj++;
            }
        }
    }
};
// @lc code=end

