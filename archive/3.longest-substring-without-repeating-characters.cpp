/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.87%)
 * Likes:    6831
 * Dislikes: 403
 * Total Accepted:    1.2M
 * Total Submissions: 4M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 *
 *
 * Example 1:
 *
 *
 * Input: "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 *
 *
 * Example 3:
 *
 *
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 *
 *
 *
 *
 *
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        if (!s.length()) return 0;
        int ans = 0;
        int l = 0, r = 0;
        bool flags[128];
        memset(flags, 0, 120 * sizeof(bool));
        int currLength = 0;
        while (r < s.length()) {
            // keep right shift right point until we found a char discovered
            // before or reach the end of string
            while (r < s.length() && !flags[s[r] - ' ']) {
                flags[s[r] - ' '] = true;
                r++;
                currLength++;
            }
            ans = currLength > ans ? currLength : ans;
            // if haven't reach the end of string, we can right shift the left
            // ptr to start next run
            if (r < s.length()) {
                while (s[l] != s[r]) {
                    flags[s[l] - ' '] = false;  // reset the flag
                    l++;
                    currLength--;
                }
                l++;
                // currLength--;
            }
            r++;
        }
        ans = currLength > ans ? currLength : ans;
        return ans;
    }
};
// @lc code=end
