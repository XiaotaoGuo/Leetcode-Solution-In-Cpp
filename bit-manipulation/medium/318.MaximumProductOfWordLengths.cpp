/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 *
 * https://leetcode.com/problems/maximum-product-of-word-lengths/description/
 *
 * algorithms
 * Medium (52.61%)
 * Likes:    1043
 * Dislikes: 83
 * Total Accepted:    109.1K
 * Total Submissions: 207.3K
 * Testcase Example:  '["abcw","baz","foo","bar","xtfn","abcdef"]'
 *
 * Given a string array words, return the maximum value of length(word[i]) *
 * length(word[j]) where the two words do not share common letters. If no such
 * two words exist, return 0.
 *
 *
 * Example 1:
 *
 *
 * Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
 * Output: 16
 * Explanation: The two words can be "abcw", "xtfn".
 *
 *
 * Example 2:
 *
 *
 * Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
 * Output: 4
 * Explanation: The two words can be "ab", "cd".
 *
 *
 * Example 3:
 *
 *
 * Input: words = ["a","aa","aaa","aaaa"]
 * Output: 0
 * Explanation: No such pair of words.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= words.length <= 1000
 * 1 <= words[i].length <= 1000
 * words[i] consists only of lowercase English letters.
 *
 *
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
public:
    int maxProduct(std::vector<std::string>& words) {
        int n = words.size();
        bool letters[n][26];
        for (int i = 0; i < n; ++i) {
            memset(letters[i], 0, 26);
            std::string word = words[i];
            for (char l : word) {
                letters[i][l - 'a'] = true;
            }
        }

        int max_len = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                bool shared = false;
                for (int k = 0; k < 26; ++k) {
                    if (letters[i][k] && letters[j][k]) {
                        shared = true;
                        break;
                    }
                }

                if (!shared) {
                    max_len = std::max(
                        static_cast<int>(words[i].length() * words[j].length()),
                        max_len);
                }
            }
        }
        return max_len;
    }
};
// @lc code=end
