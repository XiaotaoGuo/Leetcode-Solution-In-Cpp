/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (43.54%)
 * Likes:    1089
 * Dislikes: 50
 * Total Accepted:    252.9K
 * Total Submissions: 579.2K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
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
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, curr, ans);
        return ans;
    }
private:
    void dfs(vector<int>& nums, const int target, int s, vector<int>& curr, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        
        for(int i = s; i < nums.size(); i++){
            int num = nums[i];
            if(num > target){
                return;
            }
            if(i > s && nums[i] == nums[i-1]) continue; 
            curr.push_back(nums[i]);
            dfs(nums, target - num, i + 1, curr, ans);
            curr.pop_back();
        }
    }
};
// @lc code=end

