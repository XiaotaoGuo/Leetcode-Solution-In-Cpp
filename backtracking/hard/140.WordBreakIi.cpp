/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 *
 * https://leetcode.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (33.14%)
 * Likes:    2696
 * Dislikes: 427
 * Total Accepted:    287.6K
 * Total Submissions: 847.3K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, add spaces in s to construct a sentence where each word is
 * a valid dictionary word. Return all such possible sentences.
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
 * Input:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * Output:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * Output:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 *
 *
 * Example 3:
 *
 *
 * Input:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output:
 * []
 *
 */

// @lc code=start
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
    std::vector<std::string> wordBreak(std::string s,
                                       std::vector<std::string>& wordDict) {
        std::vector<bool> letter_count(26, false);

        for (const auto& word : wordDict) {
            m_dict.insert(word);
            for (char c : word) {
                letter_count[c - 'a'] = true;
            }
        }

        // check s only contains letters in dict first
        for (char c : s) {
            if (!letter_count[c - 'a']) return {};
        }

        std::string current_sentence;
        findWords(s, 0, current_sentence);
        return m_result;
    }

private:
    std::unordered_set<std::string> m_dict;
    std::vector<std::string> m_result;

    void findWords(const std::string& s, int idx,
                   std::string& current_sentence) {
        // cout << current_word << "\n" << current_sentence << endl;
        if (idx == s.length()) {
            m_result.push_back(current_sentence);
            return;
        }

        std::string current_word = "";
        for (int i = idx; i < s.length(); i++) {
            // expand word
            current_word += s[i];
            // cout << "expand word ->" << current_word << endl;
            // use it as seperate word and find next word
            if (m_dict.count(current_word) != 0) {
                if (idx != 0) current_sentence += " ";
                current_sentence += current_word;
                findWords(s, i + 1, current_sentence);
                if (idx != 0) {
                    current_sentence.erase(current_sentence.length() -
                                           current_word.length() - 1);
                } else {
                    current_sentence = "";
                }
            }
        }
    }
};
// @lc code=end
