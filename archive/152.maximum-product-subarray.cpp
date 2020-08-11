/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (30.05%)
 * Likes:    2568
 * Dislikes: 115
 * Total Accepted:    246.6K
 * Total Submissions: 818.3K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int dp_pre_max = nums[0];
        int dp_pre_min = nums[0];
        int dp_max = dp_pre_max;
        int dp_curr_min, dp_curr_max;
        for(int i = 1; i < nums.size(); ++i){
            dp_curr_max = max(dp_pre_max * nums[i], max(dp_pre_min * nums[i], nums[i]));
            dp_curr_min = min(dp_pre_max * nums[i], min(dp_pre_min * nums[i], nums[i]));
            if(dp_curr_max > dp_max) dp_max = dp_curr_max;
            dp_pre_max = dp_curr_max;
            dp_pre_min = dp_curr_min;
        }
        
        return dp_max;
    }
};
// @lc code=end

