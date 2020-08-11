/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (42.26%)
 * Likes:    1367
 * Dislikes: 47
 * Total Accepted:    288.5K
 * Total Submissions: 670.3K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<bool> flags(n, false);
        vector<int> curr;
        vector<vector<int>> result;
        dfs(nums, curr, result, flags);
        
        return result;
    }

private:
    void dfs(vector<int>& nums, vector<int>& curr, vector<vector<int>>& result, vector<bool>& flags){
        if(curr.size() == nums.size()){
            result.push_back(curr);
            return;
        }
        
        for(int i = 0; i < flags.size(); i++){
            if(flags[i]) continue;
            if(i > 0 && nums[i] == nums[i - 1] && !flags[i - 1]) continue;
            curr.push_back(nums[i]);
            flags[i] = true;
            dfs(nums,curr, result, flags);
            curr.pop_back();
            flags[i] = false;
        }
    }
};
// @lc code=end

