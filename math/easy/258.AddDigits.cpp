/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 *
 * https://leetcode.com/problems/add-digits/description/
 *
 * algorithms
 * Easy (57.91%)
 * Likes:    929
 * Dislikes: 1182
 * Total Accepted:    325.4K
 * Total Submissions: 561.4K
 * Testcase Example:  '38'
 *
 * Given a non-negative integer num, repeatedly add all its digits until the
 * result has only one digit.
 *
 * Example:
 *
 *
 * Input: 38
 * Output: 2
 * Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2.
 * Since 2 has only one digit, return it.
 *
 *
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        int result = 0;
        while (num > 9) {
            int next_num = 0;
            while (num > 0) {
                next_num += (num % 10);
                num /= 10;
            }
            num = next_num;
        }
        return num;
    }
};
// @lc code=end
