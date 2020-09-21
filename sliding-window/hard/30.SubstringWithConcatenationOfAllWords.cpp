/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (25.59%)
 * Likes:    963
 * Dislikes: 1299
 * Total Accepted:    184.9K
 * Total Submissions: 722.8K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * You are given a string s and an array of strings words of the same length.
 * Return all starting indices of substring(s) in s that is a concatenation of
 * each word in words exactly once, in any order, and without any intervening
 * characters.
 * 
 * You can return the answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "barfoothefoobarman", words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar"
 * respectively.
 * The output order does not matter, returning [9,0] is fine too.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
 * Output: [6,9,12]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^4
 * s consists of lower-case English letters.
 * 1 <= words.length <= 5000
 * 1 <= words[i].length <= 30
 * words[i] consists of lower-case English letters.
 * 
 * 
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> inds;

        if (words.empty()) return {};
        int len = words[0].length();
        if (s.length() < words.size() * len) return {};

        std::unordered_map<std::string, int> records;
        for (const std::string& word: words) {
            records[word]++;
        }

        for (int i = 0; i <= s.length() - len * words.size(); i++) {
            std::unordered_map<std::string, int> current_records;
            int count = 0;
            for (; count < words.size(); count++) {
                std::string word = s.substr(i + count * len, len);
                current_records[word]++;
                if (current_records[word] > records[word]) break;
            }

            if (count == words.size()) inds.push_back(i);
        }

        return inds;

    }
};
// @lc code=end

