/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 *
 * https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
 *
 * algorithms
 * Medium (39.74%)
 * Likes:    1405
 * Dislikes: 148
 * Total Accepted:    172.6K
 * Total Submissions: 434K
 * Testcase Example:  '5\n7'
 *
 * Given two integers left and right that represent the range [left, right],
 * return the bitwise AND of all numbers in this range, inclusive.
 *
 *
 * Example 1:
 *
 *
 * Input: left = 5, right = 7
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: left = 0, right = 0
 * Output: 0
 *
 *
 * Example 3:
 *
 *
 * Input: left = 1, right = 2147483647
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= left <= right <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ret = 0;
        for (int i = 30; i >= 0; --i) {
            int mask = (1 << i);
            if ((right & mask) > 0) {
                if ((left & mask) > 0) {
                    ret ^= (1 << i);
                } else {
                    break;
                }
            }
        }
        return ret;
    }
};
// @lc code=end
