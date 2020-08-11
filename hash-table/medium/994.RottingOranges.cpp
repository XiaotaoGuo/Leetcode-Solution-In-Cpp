/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 *
 * https://leetcode.com/problems/rotting-oranges/description/
 *
 * algorithms
 * Medium (47.65%)
 * Likes:    2188
 * Dislikes: 188
 * Total Accepted:    142.9K
 * Total Submissions: 290.4K
 * Testcase Example:  '[[2,1,1],[1,1,0],[0,1,1]]'
 *
 * In a given grid, each cell can have one of three values:
 * 
 * 
 * the value 0 representing an empty cell;
 * the value 1 representing a fresh orange;
 * the value 2 representing a rotten orange.
 * 
 * 
 * Every minute, any fresh orange that is adjacent (4-directionally) to a
 * rotten orange becomes rotten.
 * 
 * Return the minimum number of minutes that must elapse until no cell has a
 * fresh orange.  If this is impossible, return -1 instead.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: [[2,1,1],[1,1,0],[0,1,1]]
 * Output: 4
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[2,1,1],[0,1,1],[1,0,1]]
 * Output: -1
 * Explanation:  The orange in the bottom left corner (row 2, column 0) is
 * never rotten, because rotting only happens 4-directionally.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [[0,2]]
 * Output: 0
 * Explanation:  Since there are already no fresh oranges at minute 0, the
 * answer is just 0.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= grid.length <= 10
 * 1 <= grid[0].length <= 10
 * grid[i][j] is only 0, 1, or 2.
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <queue>

class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        
        std::queue<std::pair<int, int>> current_rotten_oranges;
        int count_fresh_oranges = 0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == 2) {
                    current_rotten_oranges.push({i, j});
                } else if (grid[i][j] == 1) {
                    count_fresh_oranges++;
                }
            }
        }
        
        int iteration = 0;
        while (true) {
            std::queue<std::pair<int, int>> newly_rotten_oranges;
            while (!current_rotten_oranges.empty()) {
                std::pair<int, int> index = current_rotten_oranges.front();
                current_rotten_oranges.pop();
                int y = index.first, x = index.second;
                if (hasFreshOrange(y + 1, x, height, width, grid)) {
                    grid[y + 1][x] = 2;
                    newly_rotten_oranges.push({y + 1, x});
                    count_fresh_oranges--;
                }
                if (hasFreshOrange(y - 1, x, height, width, grid)) {
                    grid[y - 1][x] = 2;
                    newly_rotten_oranges.push({y - 1, x});
                    count_fresh_oranges--;
                }
                if (hasFreshOrange(y, x + 1, height, width, grid)) {
                    grid[y][x + 1] = 2;
                    newly_rotten_oranges.push({y, x + 1});
                    count_fresh_oranges--;
                }
                if (hasFreshOrange(y, x - 1, height, width, grid)) {
                    grid[y][x - 1] = 2;
                    newly_rotten_oranges.push({y, x - 1});
                    count_fresh_oranges--;
                }
            }
            if (newly_rotten_oranges.empty()) break;
            iteration++;
            current_rotten_oranges = newly_rotten_oranges;
        }
        
        return count_fresh_oranges == 0? iteration : -1;
    }
    
private:
    bool hasFreshOrange(int y, int x, int height, int width, const std::vector<std::vector<int>>& grid) {
        return (y >= 0 && x >= 0 && y < height && x < width && grid[y][x] == 1);
    }
    
    
};
// @lc code=end

