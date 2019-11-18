/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.79%)
 * Likes:    4875
 * Dislikes: 580
 * Total Accepted:    699.6K
 * Total Submissions: 2.8M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
                if(nums.size() < 3) return {};
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2;){
            int num = nums[i];
            int l = i + 1, r = nums.size() - 1;
            while(l < r){
                int currSum = num + nums[l] + nums[r];
                if(currSum == 0){
                    result.push_back(vector<int>{num, nums[l], nums[r]});
                    l++;
                    while(l < r && nums[l] == nums[l - 1]) l++;
                }
                else if(currSum < 0){
                    l++;
                }
                else{
                    r--;
                }
            }
            ++i;
            while(i < nums.size()-2 && nums[i] == nums[i-1]) ++i;
        }
        return result;
    }
};
// @lc code=end

