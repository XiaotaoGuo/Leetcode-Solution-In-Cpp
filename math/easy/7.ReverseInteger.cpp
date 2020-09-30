/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.82%)
 * Likes:    3763
 * Dislikes: 5883
 * Total Accepted:    1.2M
 * Total Submissions: 4.8M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 * 
 */

// @lc code=start
#include <cmath>

class Solution {
public:
    int reverse(int x) {
        long rev = 0;
        long copy = x;
        bool is_negative = copy < 0;
        copy = copy > 0 ? copy : -copy;
        while (copy) {
            rev *= 10;
            rev += (copy % 10);
            copy /= 10;
        }
        if (is_negative) rev = -rev;
        if (rev < -1 * pow(2, 31) || rev > pow(2, 31) - 1) return 0;
        return rev;
    }
};
// @lc code=end

