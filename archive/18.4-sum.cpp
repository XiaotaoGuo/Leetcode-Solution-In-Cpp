/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (31.52%)
 * Likes:    1360
 * Dislikes: 268
 * Total Accepted:    275.7K
 * Total Submissions: 864.9K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
                if(nums.size() < 4) return {};
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < nums.size() - 3){
            int j = i + 1;
            while(j < nums.size() - 2){
                int l = j + 1, r = nums.size() - 1;
                while(l < r){
                    int currSum = nums[i] + nums[j] + nums[l] + nums[r];
                    if(currSum == target){
                        result.push_back(vector<int>{nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        while(l < r && nums[l] == nums[l-1]) l++;
                    }
                    else if(currSum < target){
                        l++;
                    }
                    else{
                        r--;
                    }
                }
                j++;
                while(j < nums.size() - 2 && nums[j] == nums[j-1]) j++;
            }
            i++;
            while(i < nums.size() - 3 && nums[i] == nums[i-1]) i++;
        }
        return result;
    }
};
// @lc code=end

