/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (29.77%)
 * Likes:    2295
 * Dislikes: 668
 * Total Accepted:    259.5K
 * Total Submissions: 860.1K
 * Testcase Example:  '[1,2,0]'
 *
 * Given an unsorted integer array, find the smallest missing positive
 * integer.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,0]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,4,-1,1]
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,8,9,11,12]
 * Output: 1
 * 
 * 
 * Note:
 * 
 * Your algorithm should run in O(n) time and uses constant extra space.
 * 
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= 0){
                nums[i] = INT_MAX;
            }
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == INT_MAX) continue;
            int idx = abs(nums[i]);
            if(idx > nums.size()) continue;
            nums[idx - 1] = -abs(nums[idx - 1]);
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) return i + 1;
        }
        
        return nums.size() + 1;
    }
};
// @lc code=end

