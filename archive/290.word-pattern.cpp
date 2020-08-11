/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (35.60%)
 * Likes:    780
 * Dislikes: 104
 * Total Accepted:    158.3K
 * Total Submissions: 442.9K
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
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
                unordered_map<char, string> hash;
        unordered_map<string, char> rehash;
        int pos = 0;
        for(int i = 0; i < pattern.size(); i++){
            if(pos == str.length()) return false;
            string word = "";
            while(pos < str.length() && str[pos] != ' '){
                word += to_string(str[pos]);
                pos++;
            }
            if(hash.find(pattern[i]) == hash.end()){
                hash[pattern[i]] = word;
            }
            else if(hash[pattern[i]] != word){
                return false;
            }
            if(rehash.find(word) == rehash.end()){
                rehash[word] = pattern[i];
            }
            else if(rehash[word] != pattern[i]){
                return false;
            }
            while(pos < str.length() && str[pos] == ' ') pos++;
        }
        if(pos != str.length()) return false;
        return true;
    }
};
// @lc code=end

