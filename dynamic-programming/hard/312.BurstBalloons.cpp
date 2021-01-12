/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 *
 * https://leetcode.com/problems/burst-balloons/description/
 *
 * algorithms
 * Hard (52.21%)
 * Likes:    3241
 * Dislikes: 90
 * Total Accepted:    124.6K
 * Total Submissions: 232.5K
 * Testcase Example:  '[3,1,5,8]'
 *
 * You are given n balloons, indexed from 0 to n - 1. Each balloon is painted
 * with a number on it represented by an array nums. You are asked to burst all
 * the balloons.
 * 
 * If you burst the i^th balloon, you will get nums[left] * nums[i] *
 * nums[right] coins. Here left and right are adjacent indices of i. After the
 * burst, the left and right then becomes adjacent.
 * 
 * Return the maximum coins you can collect by bursting the balloons wisely.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,1,5,8]
 * Output: 167
 * Explanation:
 * nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
 * coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,5]
 * Output: 10
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= n <= 500
 * 0 <= nums[i] <= 100
 * 
 * 
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int maxCoins(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::vector<int>> max_coins(n + 2, std::vector<int>(n + 2, 1));

        for (int i = 1; i <= n; ++i) {
            max_coins[i][i] = nums[i];
        }

        // interval length
        for (int len = 1; len <= n; ++len) {
            // left boundary of interval
            for (int left = 0; left <= n - len + 1; ++left) {
                // right boundary of interval
                int right = left + len - 1;
                for (int middle = left + 1; middle <= right - 1; middle++) {
                    max_coins[left][right] = std::max(max_coins[left][right],\
                                             max_coins[left][middle - 1] * nums[middle] * max_coins[middle + 1][right]);
                }
            }
        }

        return max_coins[1][n];
    }
};
// @lc code=end

