/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (43.76%)
 * Likes:    1089
 * Dislikes: 53
 * Total Accepted:    225.8K
 * Total Submissions: 515.1K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= nums.size(); i++){
            dfs(nums, i, 0, curr, ans);
        }
        return ans;
    }

private:
    void dfs(vector<int>& nums, int k, int s, vector<int>& curr, vector<vector<int>>& ans){
        if(curr.size() == k){
            ans.push_back(curr);
            return;
        }
        
        for(int i = s; i < nums.size(); i++){
            int num = nums[i];
            if(i > s && nums[i] == nums[i-1]) continue;
            curr.push_back(num);
            dfs(nums, k, i + 1, curr, ans);
            curr.pop_back();
        }
    }
};
// @lc code=end

