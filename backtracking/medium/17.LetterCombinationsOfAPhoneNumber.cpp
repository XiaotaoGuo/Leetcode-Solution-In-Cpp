/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (47.38%)
 * Likes:    4844
 * Dislikes: 462
 * Total Accepted:    709.7K
 * Total Submissions: 1.5M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent. Return the answer in
 * any order.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 *
 *
 * Example 2:
 *
 *
 * Input: digits = ""
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: digits = "2"
 * Output: ["a","b","c"]
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= digits.length <= 4
 * digits[i] is a digit in the range ['2', '9'].
 *
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) return {};
        std::vector<std::string> nums{"",    "abc",  "def", "ghi", "jkl",
                                      "mno", "pqrs", "tuv", "wxyz"};
        std::string combination;
        std::vector<std::string> result;
        iterate(nums, 0, digits, combination, result);
        return result;
    }

private:
    void iterate(const std::vector<std::string>& nums, int idx,
                 const std::string& digits, std::string& combination,
                 std::vector<std::string>& result) {
        if (idx == digits.length()) {
            result.push_back(combination);
            return;
        }

        int digit = digits[idx] - '0' - 1;
        for (int i = 0; i < nums[digit].length(); i++) {
            combination.push_back(nums[digit][i]);
            iterate(nums, idx + 1, digits, combination, result);
            combination.pop_back();
        }
    }
};
// @lc code=end
