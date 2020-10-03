/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (42.97%)
 * Likes:    1785
 * Dislikes: 2625
 * Total Accepted:    697.3K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer,
 * increment one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contains a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: digits = [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: digits = [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: digits = [0]
 * Output: [1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= digits.length <= 100
 * 0 <= digits[i] <= 9
 * 
 * 
 */

// @lc code=start
#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        bool flag = true;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (!flag) break;
            flag = false;
            digits[i]++;
            if (digits[i] == 10) {
                digits[i] = 0;
                flag = true;
            }
        }
        if (flag) {
            digits.insert(digits.begin(), {1});
        }
        return digits;
    }
};
// @lc code=end

