/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (36.92%)
 * Likes:    1412
 * Dislikes: 181
 * Total Accepted:    221.2K
 * Total Submissions: 582.6K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 * 
 * Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in str.
 * 
 * Example 1:
 * 
 * 
 * Input: pattern = "abba", str = "dog cat cat dog"
 * Output: true
 * 
 * Example 2:
 * 
 * 
 * Input:pattern = "abba", str = "dog cat cat fish"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: pattern = "aaaa", str = "dog cat cat dog"
 * Output: false
 * 
 * Example 4:
 * 
 * 
 * Input: pattern = "abba", str = "dog dog dog dog"
 * Output: false
 * 
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains
 * lowercase letters that may be separated by a single space.
 * 
 */

// @lc code=start
#include <string>
#include <unordered_map>

class Solution {
public:
    bool wordPattern(std::string pattern, std::string str) {
        std::unordered_map<char, std::string> dist;
        std::unordered_map<std::string, char> rev_dist;
        int ptr = 0;
        for (int i = 0; i < pattern.length(); i++) {
            char key = pattern[i];
            std::string word = "";
            while (ptr < str.length() && str[ptr] == ' ') ptr++;
            while (ptr < str.length() && str[ptr] != ' ') {
                word += str[ptr];
                ptr++;
            }
            if (word.empty()) return false;

            if (dist.find(key) == dist.end()) {
                dist[key] = word;
            } else if (dist[key] != word) {
                return false;
            }
            if (rev_dist.find(word) == rev_dist.end()) {
                rev_dist[word] = key;
            } else if (rev_dist[word] != key) {
                return false;
            }
        }
        if (ptr != str.length()) return false;
        
        return true;
    }
};
// @lc code=end

