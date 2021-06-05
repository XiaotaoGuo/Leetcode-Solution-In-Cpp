/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 *
 * https://leetcode.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (54.43%)
 * Likes:    2663
 * Dislikes: 407
 * Total Accepted:    291.1K
 * Total Submissions: 534.3K
 * Testcase Example:  '[2,2,3,2]'
 *
 * Given an integer array nums where every element appears three times except
 * for one, which appears exactly once. Find the single element and return it.
 *
 * You must implement a solution with a linear runtime complexity and use only
 * constant extra space.
 *
 *
 * Example 1:
 * Input: nums = [2,2,3,2]
 * Output: 3
 * Example 2:
 * Input: nums = [0,1,0,1,0,1,99]
 * Output: 99
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 3 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * Each element in nums appears exactly three times except for one element
 * which appears once.
 *
 *
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            int count = 0;
            for (int num : nums) {
                count += ((num >> i) & 0x1);
            }
            result |= ((count % 3) << i);
        }

        return result;
    }
};
// @lc code=end
