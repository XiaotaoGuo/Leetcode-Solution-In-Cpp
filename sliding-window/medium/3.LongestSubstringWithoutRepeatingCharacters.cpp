/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (30.61%)
 * Likes:    10848
 * Dislikes: 615
 * Total Accepted:    1.7M
 * Total Submissions: 5.6M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string s, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not
 * a substring.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = ""
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
 * 
 * 
 */

// @lc code=start
#include <string>
#include <vector>
#include <climits>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::vector<int> record(256, -1);
        int len = 0;
        int front = 0, back = 0;

        while (back < s.length()) {
            int ind = static_cast<int>(s[back]);
            if (record[ind] == -1) {
                record[ind] = back;
                len = std::max(len, back - front + 1);
            } else {    // found repeat characters
                while (front != record[ind]) {
                    record[s[front]] = -1;
                    front++;
                }
                front++;
                record[ind] = back;
            }
            back++;
        }

        return len;
    }
};
// @lc code=end

