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
        vector<vector<int>> ans;
        vector<int> curr;
        for(int i = 0; i <= nums.size(); i++)
            dfs(nums, i, 0, curr, ans);
        
        return ans;
    }
    
private:
    void dfs(const vector<int>& nums, int n, int s, vector<int>& curr, vector<vector<int>>& ans){
        if(curr.size()==n){
            ans.push_back(curr);
            return;
        }
        
        for(int i = s; i < nums.size(); i++){
            curr.push_back(nums[i]);
            dfs(nums, n, i + 1, curr, ans);
            curr.pop_back();
        }
    }
};
// @lc code=end

