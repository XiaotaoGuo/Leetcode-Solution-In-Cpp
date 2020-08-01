/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 *
 * https://leetcode.com/problems/detect-capital/description/
 *
 * algorithms
 * Easy (53.41%)
 * Likes:    561
 * Dislikes: 269
 * Total Accepted:    136.1K
 * Total Submissions: 250.3K
 * Testcase Example:  '"USA"'
 *
 * Given a word, you need to judge whether the usage of capitals in it is right
 * or not.
 * 
 * We define the usage of capitals in a word to be right when one of the
 * following cases holds:
 * 
 * 
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital, like "Google".
 * 
 * Otherwise, we define that this word doesn't use capitals in a right way.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "USA"
 * Output: True
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "FlaG"
 * Output: False
 * 
 * 
 * 
 * 
 * Note: The input will be a non-empty word consisting of uppercase and
 * lowercase latin letters.
 * 
 */

// @lc code=start
#include <string>
#include <cctype>

class Solution {
public:
    bool detectCapitalUse(std::string word) {
        if (word.length() <= 1) return true;
        
        bool is_all_capital = false;
        if (isupper(word[1])) {
            if (!isupper(word[0])) return false;
            else is_all_capital = true;
        }
        
        for (int i = 2; i < word.length(); i++) {
            if (is_all_capital ^ (bool)(std::isupper(word[i]))) {
                return false;
            }
        }
        
        return true;
    }
};
// @lc code=end

