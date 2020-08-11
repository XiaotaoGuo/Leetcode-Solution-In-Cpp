/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.50%)
 * Likes:    2593
 * Dislikes: 4062
 * Total Accepted:    863.6K
 * Total Submissions: 3.4M
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
class Solution {
public:
    int reverse(int x) {
                int sign = x > 0 ? 1 : -1;
        long new_x = x;
        new_x = max(new_x, -new_x);
        long result = 0;
        while(new_x > 0){
            int digit = new_x % 10;
            result *= 10;
            result += digit;
            new_x = int(new_x/10);
            
        }
        if(sign == -1 && result > pow(2,31))
            return 0;
        if(sign == 1 && result > (pow(2,31) - 1))
            return 0;
        
        return sign * result;
    }
};
// @lc code=end

