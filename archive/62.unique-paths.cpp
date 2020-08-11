/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (49.26%)
 * Likes:    2066
 * Dislikes: 153
 * Total Accepted:    354K
 * Total Submissions: 708.3K
 * Testcase Example:  '3\n2'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * How many possible unique paths are there?
 * 
 * 
 * Above is a 7 x 3 grid. How many possible unique paths are there?
 * 
 * Note: m and n will be at most 100.
 * 
 * Example 1:
 * 
 * 
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the
 * bottom-right corner:
 * 1. Right -> Right -> Down
 * 2. Right -> Down -> Right
 * 3. Down -> Right -> Right
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: m = 7, n = 3
 * Output: 28
 * 
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        if(m <= 1 || n <= 1) return min(m, n);
        vector<int> Prevways(n, 0);
        for(int i = 0; i < m; i++){
            vector<int> Currways(n, 0);
            Currways[0] = 1;
            for(int j = 1; j < n; j++){
                Currways[j] = Currways[j - 1] + Prevways[j];
            }
            Prevways = Currways;
        }
        return Prevways[n - 1];
    }
};
// @lc code=end

