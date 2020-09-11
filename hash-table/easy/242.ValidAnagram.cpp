/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (56.69%)
 * Likes:    1765
 * Dislikes: 148
 * Total Accepted:    619.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t , write a function to determine if t is an anagram
 * of s.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 * 
 */

// @lc code=start
#include <string>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()) return false;
        std::unordered_map<char, int> count;
        for (char letter: s) {
            if (count.find(letter) == count.end()) {
                count[letter] = 0;
            }
            count[letter]++;
        }
        for (char letter: t) {
            if (count.find(letter) == count.end() || count[letter] == 0) return false;
            count[letter]--;
        }
        return true;
    }
};
// @lc code=end

