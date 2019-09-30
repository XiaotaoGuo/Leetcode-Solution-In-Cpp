/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (49.86%)
 * Likes:    943
 * Dislikes: 55
 * Total Accepted:    229.5K
 * Total Submissions: 459.3K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 */

#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(n, k, 1, curr, ans);
        return ans;
    }

private:
    void dfs(const int n, const int k, int s,  vector<int>& curr, vector<vector<int>>& ans){
        if(curr.size() == k){
            ans.push_back(curr);
            return;
        }
        for(int i = s; i <= n; i++){
            curr.push_back(i);
            dfs(n, k, i+1, curr, ans);
            curr.pop_back();
        }
    }
};
// @lc code=end

