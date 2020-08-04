/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 *
 * https://leetcode.com/problems/power-of-four/description/
 *
 * algorithms
 * Easy (41.62%)
 * Likes:    583
 * Dislikes: 217
 * Total Accepted:    169.5K
 * Total Submissions: 407.5K
 * Testcase Example:  '16'
 *
 * Given an integer (signed 32 bits), write a function to check whether it is a
 * power of 4.
 * 
 * Example 1:
 * 
 * 
 * Input: 16
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 5
 * Output: false
 * 
 * 
 * Follow up: Could you solve it without loops/recursion?
 */

// @lc code=start
#include <cmath>

class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num > 0 && (int(log10(num) / log10(4)) == log10(num) / log10(4)));
    }
};
// @lc code=end

