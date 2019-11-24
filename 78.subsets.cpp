/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (55.18%)
 * Likes:    2379
 * Dislikes: 58
 * Total Accepted:    421.1K
 * Total Submissions: 761.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> result;
        dfs(nums, 0, curr, result);
        return result;
    }

private:
    void dfs(const vector<int>& nums, int s, vector<int>& curr, vector<vector<int>>& result){
        int n = nums.size();
        result.push_back(curr);
        if(curr.size() >= n) return;
        
        for(int i = s; i < n; i++){
            curr.push_back(nums[i]);
            dfs(nums, i + 1, curr, result);
            curr.pop_back();
        }
    }
};
// @lc code=end

