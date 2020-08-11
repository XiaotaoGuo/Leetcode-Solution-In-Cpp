/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 *
 * https://leetcode.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Easy (50.78%)
 * Likes:    871
 * Dislikes: 1631
 * Total Accepted:    150.7K
 * Total Submissions: 296.7K
 * Testcase Example:  '1\n2'
 *
 * Calculate the sum of two integers a and b, but you are not allowed to use
 * the operator + and -.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: a = 1, b = 2
 * Output: 3
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: a = -2, b = 3
 * Output: 1
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        long long carry; // 64-bit
        while (b != 0) {
            carry = a & b;
            a = a ^ b;
            b = ((carry & 0xffffffff) << 1); // limited to 32 bits
        }
        return a;
    }
};
// @lc code=end

