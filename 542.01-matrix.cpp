/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        if(!matrix.size() || !matrix[0].size()) return matrix;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0) q.push({i, j});
                else matrix[i][j] = INT_MAX;
            }
        }
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int i = curr.first, j = curr.second;
            for(auto& dir : dirs){
                int ni = i + dir[0], nj = j + dir[1];
                if(ni < 0 || nj < 0 || ni >= m || nj >= n || matrix[ni][nj] <= matrix[i][j]) continue;
                matrix[ni][nj] = matrix[i][j] + 1;
                q.push({ni, nj});
            }
        }
        
        return matrix;
    }
};
// @lc code=end

