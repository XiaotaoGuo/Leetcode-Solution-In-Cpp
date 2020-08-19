/*
 * @lc app=leetcode id=824 lang=cpp
 *
 * [824] Goat Latin
 *
 * https://leetcode.com/problems/goat-latin/description/
 *
 * algorithms
 * Easy (63.22%)
 * Likes:    377
 * Dislikes: 761
 * Total Accepted:    87.2K
 * Total Submissions: 133.5K
 * Testcase Example:  '"I speak Goat Latin"'
 *
 * A sentence S is given, composed of words separated by spaces. Each word
 * consists of lowercase and uppercase letters only.
 * 
 * We would like to convert the sentence to "Goat Latin" (a made-up language
 * similar to Pig Latin.)
 * 
 * The rules of Goat Latin are as follows:
 * 
 * 
 * If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of
 * the word.
 * For example, the word 'apple' becomes 'applema'.
 * 
 * If a word begins with a consonant (i.e. not a vowel), remove the first
 * letter and append it to the end, then add "ma".
 * For example, the word "goat" becomes "oatgma".
 * 
 * Add one letter 'a' to the end of each word per its word index in the
 * sentence, starting with 1.
 * For example, the first word gets "a" added to the end, the second word gets
 * "aa" added to the end and so on.
 * 
 * 
 * Return the final sentence representing the conversion from S to Goat
 * Latin. 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "I speak Goat Latin"
 * Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "The quick brown fox jumped over the lazy dog"
 * Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa
 * hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
 * 
 * 
 * 
 * 
 * Notes:
 * 
 * 
 * S contains only uppercase, lowercase and spaces. Exactly one space between
 * each word.
 * 1 <= S.length <= 150.
 * 
 * 
 */

// @lc code=start
#include <string>
#include <cctype>

class Solution {
public:
    std::string toGoatLatin(std::string S) {
        
        int count = 0, index = 0;
        std::string resultS;
        while (index < S.length()) {
            std::string word;
            while (index < S.length() && S[index] != ' ') {
                word += S[index];
                index++;
            }
            
            if (word.empty()) continue;
            
            if (isVowel(word[0]) || word.length() == 1) {
                resultS += word;
                

            } 
            else {
                resultS += word.substr(1);
                resultS += word[0];
            }
            
            count++;
            resultS += "ma";
            for (int i = 1; i <=  count; i++) {
                resultS += "a";
            }
            resultS += " ";
            index++;
        }
        
        return resultS.substr(0, resultS.length() - 1);
        
    }

private:
    bool isVowel(char letter) {
        char lower_letter = std::tolower(letter);
        return (lower_letter == 'a' || 
                lower_letter == 'e' || 
                lower_letter == 'i' ||
                lower_letter == 'o' ||
                lower_letter == 'u');
    }
};
// @lc code=end

