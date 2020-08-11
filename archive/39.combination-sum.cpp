/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (50.82%)
 * Likes:    2481
 * Dislikes: 74
 * Total Accepted:    400.5K
 * Total Submissions: 786K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */

#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        int sum = 0;
        dfs(candidates, target, 0, curr, sum, ans);
        return ans;
    }

private:
    void dfs(vector<int>& candidates, const int target, int s, vector<int>& curr, int sum, vector<vector<int>>& ans){
        if(sum == target){
            ans.push_back(curr);
            return;
        }
        else if(sum > target){
            return;
        }
        
        for(int i = s; i < candidates.size(); i++){
            curr.push_back(candidates[i]);
            sum += candidates[i];
            dfs(candidates, target, i, curr, sum,  ans);
            curr.pop_back();
            sum -= candidates[i];
        }
    }
};
// @lc code=end

