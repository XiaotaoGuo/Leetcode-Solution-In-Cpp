/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (39.72%)
 * Likes:    1523
 * Dislikes: 376
 * Total Accepted:    308.7K
 * Total Submissions: 773.5K
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "egg", t = "add"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "foo", t = "bar"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: s = "paper", t = "title"
 * Output: true
 * 
 * Note:
 * You may assume both s and t have the same length.
 * 
 */

// @lc code=start
#include <unordered_map>
#include <string>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        std::unordered_map<char, char> dist;
        std::unordered_map<char, char> rev_dist;
        for (int i = 0; i < s.length(); i++) {
            if (dist.find(s[i]) == dist.end()) {
                dist[s[i]] = t[i];
            } else if (dist[s[i]] != t[i]) {
                return false;
            }
            if (rev_dist.find(t[i]) == rev_dist.end()) {
                rev_dist[t[i]] = s[i];
            } else if (rev_dist[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

