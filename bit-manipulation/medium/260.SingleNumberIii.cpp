/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 *
 * https://leetcode.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (65.53%)
 * Likes:    2393
 * Dislikes: 137
 * Total Accepted:    194K
 * Total Submissions: 296.1K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * Given an integer array nums, in which exactly two elements appear only once
 * and all the other elements appear exactly twice. Find the two elements that
 * appear only once. You can return the answer in any order.
 *
 * You must write an algorithm that runs in linear runtime complexity and uses
 * only constant extra space.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,1,3,2,5]
 * Output: [3,5]
 * Explanation:  [5, 3] is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-1,0]
 * Output: [-1,0]
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [0,1]
 * Output: [1,0]
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 3 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * Each integer in nums will appear twice, only two integers will appear once.
 *
 *
 */

// @lc code=start
#include <vector>
class Solution {
public:
    std::vector<int> singleNumber(std::vector<int>& nums) {
        // xormask = a ^  b
        long xormask = 0;
        for (int num : nums) {
            xormask ^= num;
        }

        // in bit mask, the right most different bit beween a and b is set to 1,
        // others are set to 0
        int bitmask = xormask & (~(xormask - 1));

        std::vector<int> ans(2, 0);
        for (int num : nums) {
            if ((num & bitmask) == 0) {
                ans[0] ^= num;
            } else {
                ans[1] ^= num;
            }
        }

        return ans;
    }
};
// @lc code=end
