/*
 * @lc app=leetcode id=398 lang=cpp
 *
 * [398] Random Pick Index
 *
 * https://leetcode.com/problems/random-pick-index/description/
 *
 * algorithms
 * Medium (51.30%)
 * Likes:    321
 * Dislikes: 530
 * Total Accepted:    66.1K
 * Total Submissions: 126.4K
 * Testcase Example:  '["Solution","pick"]\n[[[1,2,3,3,3]],[3]]'
 *
 * Given an array of integers with possible duplicates, randomly output the
 * index of a given target number. You can assume that the given target number
 * must exist in the array.
 * 
 * Note:
 * The array size can be very large. Solution that uses too much extra space
 * will not pass the judge.
 * 
 * Example:
 * 
 * 
 * int[] nums = new int[] {1,2,3,3,3};
 * Solution solution = new Solution(nums);
 * 
 * // pick(3) should return either index 2, 3, or 4 randomly. Each index should
 * have equal probability of returning.
 * solution.pick(3);
 * 
 * // pick(1) should return 0. Since in the array only nums[0] is equal to 1.
 * solution.pick(1);
 * 
 * 
 */

// @lc code=start
class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int>& nums):nums(nums) {
        
    }
    
    int pick(int target) {
        int count = 0;
        int idx;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                count++;
                if(count == 1 || rand() % count == 0){
                    idx = i;
                }
            }
        }
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end

