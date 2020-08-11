/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (32.13%)
 * Likes:    941
 * Dislikes: 1577
 * Total Accepted:    438.9K
 * Total Submissions: 1.4M
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 * 
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 * 
 * Example 1:
 * 
 * 
 * Input: 4
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since 
 * the decimal part is truncated, 2 is returned.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        long l = 0, r = x;
        while(l <= r){
            long mid = (l + r) / 2;
            if(mid * mid == x) return mid;
            else if(mid * mid < x){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        
        return l - 1;
    }
};
// @lc code=end

