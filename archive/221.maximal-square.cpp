/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (34.13%)
 * Likes:    1697
 * Dislikes: 41
 * Total Accepted:    157.9K
 * Total Submissions: 459.1K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Output: 4
 * 
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // method 1 O(n^3) prute force with storing result
        /*
        if(matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        
        // trick: take one more column and row to avoid memory error
        vector<vector<int>> sum(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                sum[i][j] = matrix[i - 1][j - 1] - '0' + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];        
            }
        }
        
        int ans = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                for(int k = min(m - i + 1, n - j + 1); k > 0; k--){
                    int area = sum[i+k-1][j+k-1] - sum[i+k-1][j-1] - sum[i-1][j+k-1] + sum[i-1][j-1];
                    if(area == k*k){
                        ans = max(ans, area);
                        break;
                    }
                }
            }
        }
        return ans;
        */

       if (matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> area(m + 1, vector<int>(n + 1, 0));
        int len = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(matrix[i-1][j-1] == '0'){
                    area[i][j] = 0;
                }
                else{
                    area[i][j] = min(min(area[i-1][j], area[i][j-1]), area[i-1][j-1]) + 1;
                    len = max(area[i][j], len);
                }
            }
        }
        
 
        return len*len;
    }
};
// @lc code=end

