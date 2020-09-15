/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 *
 * https://leetcode.com/problems/remove-duplicate-letters/description/
 *
 * algorithms
 * Hard (35.67%)
 * Likes:    1486
 * Dislikes: 113
 * Total Accepted:    83.1K
 * Total Submissions: 230K
 * Testcase Example:  '"bcabc"'
 *
 * Given a string which contains only lowercase letters, remove duplicate
 * letters so that every letter appears once and only once. You must make sure
 * your result is the smallest in lexicographical order among all possible
 * results.
 * 
 * Example 1:
 * 
 * 
 * Input: "bcabc"
 * Output: "abc"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbacdcbc"
 * Output: "acdb"
 * 
 * 
 * Note: This question is the same as 1081:
 * https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
 * 
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
public:
    std::string removeDuplicateLetters(std::string s) {
        std::vector<int> count(26, 0);
        std::vector<bool> used(26, false);
        std::string result = "";
        if (s.empty()) return result;
        for(char c: s) {
            count[c - 'a']++;
        }

        for(int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']--;
            if (used[s[i] - 'a']) continue;
            while (!result.empty() && s[i] < result.back() && count[result.back() - 'a'] > 0) {
                used[result.back() - 'a'] = false;
                result.pop_back();
            }
            result += s[i];
            used[s[i] - 'a'] = true;
        }

        return result;
    }
};
// @lc code=end

