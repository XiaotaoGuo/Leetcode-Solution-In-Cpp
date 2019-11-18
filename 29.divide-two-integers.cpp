/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (16.16%)
 * Likes:    848
 * Dislikes: 4072
 * Total Accepted:    228.4K
 * Total Submissions: 1.4M
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division and mod operator.
 * 
 * Return the quotient after dividing dividend by divisor.
 * 
 * The integer division should truncate toward zero.
 * 
 * Example 1:
 * 
 * 
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * 
 * Note:
 * 
 * 
 * Both dividend and divisor will be 32-bit signed integers.
 * The divisor will never be 0.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 2^31 − 1 when the
 * division result overflows.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
                if(divisor == 0 || (divisor == -1 && dividend == INT_MIN)) return INT_MAX;
        if(divisor == 1) return dividend;
        long l_divisor = abs((long)divisor);
        long l_dividend = abs((long)dividend);
        int sign = (divisor < 0) ^ (dividend < 0) ? -1 : 1;
        int result = 0;
        while(l_dividend >= l_divisor){
            long curr_divisor = l_divisor;
            int coeff = 1;
            while(l_dividend >= curr_divisor << 1){
                curr_divisor <<= 1;
                coeff <<= 1;
            }
            l_dividend -= curr_divisor;
            result += coeff;
        }
        
        if(sign == -1) return -result;
        return result;
    }
};
// @lc code=end

