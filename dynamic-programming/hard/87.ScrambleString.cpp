/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 *
 * https://leetcode.com/problems/scramble-string/description/
 *
 * algorithms
 * Hard (33.62%)
 * Likes:    598
 * Dislikes: 739
 * Total Accepted:    113.5K
 * Total Submissions: 334.7K
 * Testcase Example:  '"great"\n"rgeat"'
 *
 * We can scramble a string s to get a string t using the following
 * algorithm:
 * 
 * 
 * If the length of the string is 1, stop.
 * If the length of the string is > 1, do the following:
 * 
 * Split the string into 2 non-empty substrings at a random index, i.e. if the
 * string is s, divide it to x and y where s = x + y.
 * Randomly, decide to swap the two substrings or to keep them in the same
 * order. i.e. after this step, s may become s = x + y or s = y + x.
 * Apply step 1 recursively on each of the two substrings x and y.
 * 
 * 
 * 
 * 
 * Given two strings s1 and s2 of the same length, return true if s2 is a
 * scrambled string of s1, otherwise, return false.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "great", s2 = "rgeat"
 * Output: true
 * Explanation: One possible scenario applied on s1 is:
 * "great" --> "gr/eat" // divide at random index.
 * "gr/eat" --> "gr/eat" // random decision is not to swap the two substrings
 * and keep them in order.
 * "gr/eat" --> "g/r / e/at" // apply the same algorith recursively on both
 * substrings. divide at ranom index each of them.
 * "g/r / e/at" --> "r/g / e/at" // random decision was to swap the first
 * substing and to keep the second substring in the same order.
 * "r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively,
 * divide "at" to "a/t".
 * "r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both
 * substings in the same order.
 * The algorithm stops now and the result string is "rgeat" which is s2.
 * As there is one possible scenario that led s1 to be scrambled to s2, we
 * return true.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s1 = "abcde", s2 = "caebd"
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s1 = "a", s2 = "a"
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * s1.length == s2.length
 * 1 <= s1.length <= 30
 * s1 and s2 consist of lower-case English letters.
 * 
 * 
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    bool isScramble(std::string s1, std::string s2) {
        return Scramble(s1, s2);
    }

private:
    std::unordered_map<std::string, std::unordered_map<std::string, bool>> record;
    
    bool Scramble(const std::string& s1, const std::string& s2) {
        if (record.find(s1) != record.end() && record[s1].find(s2) != record[s1].end()) return record[s1][s2];
        if (s1.length() == 1) {
            return s1 == s2;
        } else if (s1 == s2) {
            return true;
        }

        std::vector<int> count(26, 0);
        for (char letter: s1) {
            count[letter - 'a']++;
        }
        for (char letter: s2) {
            if (count[letter - 'a'] == 0) {
                record[s1][s2] = false;
                return false;
            }
            count[letter - 'a']--;
        }
        
        for (int i = 1; i < s1.length(); i++) {
            std::string s1_sub1 = s1.substr(0, i);
            std::string s1_sub2 = s1.substr(i, s1.length() - i);
            record[s1_sub1][s2.substr(0, i)] = Scramble(s1_sub1, s2.substr(0, i));
            if (record[s1_sub1][s2.substr(0, i)]) {
                record[s1_sub2][s2.substr(i, s1.length() - i)] = Scramble(s1_sub2, s2.substr(i, s1.length() - i));
                if (record[s1_sub2][s2.substr(i, s1.length() - i)]) {
                    return true;
                }
            }

            record[s1_sub2][s2.substr(0, s1.length() - i)] = Scramble(s1_sub2, s2.substr(0, s1.length() - i));
            if (record[s1_sub2][s2.substr(0, s1.length() - i)]) {
                record[s1_sub1][s2.substr(s1.length() - i, i)] = Scramble(s1_sub1, s2.substr(s1.length() - i, i));
                if (record[s1_sub1][s2.substr(s1.length() - i, i)]) {
                    return true;
                }
            }
            
        }
        return false;
    }
};
// @lc code=end

