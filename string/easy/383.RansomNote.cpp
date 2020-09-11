/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 *
 * https://leetcode.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (53.02%)
 * Likes:    673
 * Dislikes: 204
 * Total Accepted:    232.7K
 * Total Submissions: 438.4K
 * Testcase Example:  '"a"\n"b"'
 *
 * Given an arbitrary ransom note string and another string containing letters
 * from all the magazines, write a function that will return true if the ransom
 * note can be constructed from the magazines ; otherwise, it will return
 * false.
 * 
 * Each letter in the magazine string can only be used once in your ransom
 * note.
 * 
 * 
 * Example 1:
 * Input: ransomNote = "a", magazine = "b"
 * Output: false
 * Example 2:
 * Input: ransomNote = "aa", magazine = "ab"
 * Output: false
 * Example 3:
 * Input: ransomNote = "aa", magazine = "aab"
 * Output: true
 * 
 * 
 * Constraints:
 * 
 * 
 * You may assume that both strings contain only lowercase letters.
 * 
 * 
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::vector<int> count(26, 0);
        for (char letter: magazine) {
            count[letter - 'a']++;
        }

        for (char letter: ransomNote) {
            count[letter - 'a']--;
            if (count[letter - 'a'] < 0) return false;
        }

        return true;
    }
};
// @lc code=end

