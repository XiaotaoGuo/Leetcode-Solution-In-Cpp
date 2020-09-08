/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (53.32%)
 * Likes:    2146
 * Dislikes: 120
 * Total Accepted:    580.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '"leetcode"'
 *
 * Given a string, find the first non-repeating character in it and return its
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode"
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contains only lowercase English letters.
 * 
 */

// @lc code=start
#include <vector>
#include <string>

class Solution {
public:
    int firstUniqChar(std::string s) {
        std::vector<int> count(26, 0);
        for (char letter: s) {
            count[letter - 'a']++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (count[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};
// @lc code=end

