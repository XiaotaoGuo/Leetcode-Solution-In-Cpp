/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (44.62%)
 * Likes:    5514
 * Dislikes: 234
 * Total Accepted:    690.3K
 * Total Submissions: 1.5M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        int ans = INT_MIN;
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            dp[i] = dp[i - 1] > 0 ? dp[i - 1] + nums[i] : nums[i];
        }
        
        for(int i = 0; i < nums.size(); i++){
            ans = max(dp[i], ans);
        }
        
        return ans;
    }
};
// @lc code=end

