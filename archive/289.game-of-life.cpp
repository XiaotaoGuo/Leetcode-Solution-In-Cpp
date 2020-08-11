/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> dirs{{-1,-1}, {-1, 0}, {-1, 1},
                                 {0, -1}, {0, 0}, {0, 1},
                                 {1, -1}, {1, 0}, {1,1}};
        if(!board.size() || !board[0].size()) return;
        int m = board.size(), n = board[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int lives = 0;
                for(auto& dir: dirs){
                    int ni = i + dir[0], nj = j + dir[1];
                    if(ni < 0 || nj < 0 || ni >= m || nj >= n) continue;
                    lives += (board[ni][nj] & 0x1);
                }
                if(lives == 3 || lives - board[i][j] == 3) board[i][j] ^= 0x2;
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                board[i][j] >>= 1;
            }
        }
    }
};
// @lc code=end

