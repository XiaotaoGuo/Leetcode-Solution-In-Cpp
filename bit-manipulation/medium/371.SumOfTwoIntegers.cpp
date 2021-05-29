/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 *
 * https://leetcode.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Medium (50.61%)
 * Likes:    1724
 * Dislikes: 2790
 * Total Accepted:    227.8K
 * Total Submissions: 450.1K
 * Testcase Example:  '1\n2'
 *
 * Given two integers a and b, return the sum of the two integers without using
 * the operators + and -.
 * 
 * 
 * Example 1:
 * Input: a = 1, b = 2
 * Output: 3
 * Example 2:
 * Input: a = 2, b = 3
 * Output: 5
 * 
 * 
 * Constraints:
 * 
 * 
 * -1000 <= a, b <= 1000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        
        while (b != 0) {
            int carry = (a & b);
            a ^= b;
            b = (static_cast<unsigned int>(carry) << 1);
        }

        return a;
    }
};
// @lc code=end

