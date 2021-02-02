/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (40.51%)
 * Likes:    5945
 * Dislikes: 283
 * Total Accepted:    698.5K
 * Total Submissions: 1.7M
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 *
 * Note:
 *
 *
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 *
 *
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::unordered_set<std::string> dict(wordDict.begin(), wordDict.end());

        return wordBreak(s, dict);
    }

    bool wordBreak(const std::string& word,
                   const std::unordered_set<std::string>& dict) {
        if (m_notes.count(word)) return m_notes[word];

        if (word.empty() || dict.count(word)) return true;

        for (int i = 1; i < word.length(); i++) {
            std::string first = word.substr(0, i);
            std::string second = word.substr(i);
            if (wordBreak(first, dict) && dict.count(second)) {
                m_notes[word] = true;
                return true;
            }
        }

        m_notes[word] = false;
        return false;
    }

private:
    std::unordered_map<std::string, bool> m_notes;
};
// @lc code=end
