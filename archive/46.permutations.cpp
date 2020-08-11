/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (57.52%)
 * Likes:    2658
 * Dislikes: 86
 * Total Accepted:    466.7K
 * Total Submissions: 797K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
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
            curr.push_back(nums[i]);
            flags[i] = true;
            dfs(nums,curr, result, flags);
            curr.pop_back();
            flags[i] = false;
        }
    }
};
// @lc code=end

