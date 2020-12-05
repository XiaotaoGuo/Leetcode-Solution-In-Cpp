/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (32.81%)
 * Likes:    4384
 * Dislikes: 1543
 * Total Accepted:    433.3K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such an arrangement is not possible, it must rearrange it as the lowest
 * possible order (i.e., sorted in ascending order).
 * 
 * The replacement must be in place and use only constant extra memory.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [1,3,2]
 * Example 2:
 * Input: nums = [3,2,1]
 * Output: [1,2,3]
 * Example 3:
 * Input: nums = [1,1,5]
 * Output: [1,5,1]
 * Example 4:
 * Input: nums = [1]
 * Output: [1]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 100
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int right = nums.size() - 1;
        int left = nums.size() - 2;
        while (left >= 0 && nums[left] >= nums[left + 1]) --left;
        
        if (left < 0) {
            std::reverse(nums.begin(), nums.end());
            return;
        }

        while (left < right && nums[right] <= nums[left]) --right;
        std::swap(nums[right], nums[left]);
        std::reverse(nums.begin() + left + 1, nums.end());
    }
};
// @lc code=end

