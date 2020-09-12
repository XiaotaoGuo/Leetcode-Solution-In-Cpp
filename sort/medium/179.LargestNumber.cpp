/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (28.62%)
 * Likes:    2152
 * Dislikes: 253
 * Total Accepted:    194.5K
 * Total Submissions: 669.5K
 * Testcase Example:  '[10,2]'
 *
 * Given a list of non negative integers, arrange them such that they form the
 * largest number.
 * 
 * Example 1:
 * 
 * 
 * Input: [10,2]
 * Output: "210"
 * 
 * Example 2:
 * 
 * 
 * Input: [3,30,34,5,9]
 * Output: "9534330"
 * 
 * 
 * Note: The result may be very large, so you need to return a string instead
 * of an integer.
 * 
 */

// @lc code=start
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    std::string largestNumber(std::vector<int>& nums) {
        std::vector<std::string> nums_str;
        bool has_non_zero = false;
        for (int num: nums) {
            nums_str.push_back(std::to_string(num));
            if (num && !has_non_zero) has_non_zero = true;
        }
        if (!has_non_zero) return "0";

        std::sort(nums_str.begin(), nums_str.end(), [](const std::string& lhs, const std::string& rhs) {
            if (lhs == rhs) return true;
            
            return (lhs + rhs) > (rhs + lhs);
        });

        std::string result;
        for (int i = 0; i < nums_str.size(); i++) result += nums_str[i];

        return result;
    }
};
// @lc code=end

