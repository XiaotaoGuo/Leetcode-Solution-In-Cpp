/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (44.08%)
 * Likes:    746
 * Dislikes: 1210
 * Total Accepted:    233.2K
 * Total Submissions: 526K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and reverse only the vowels of
 * a string.
 * 
 * Example 1:
 * 
 * 
 * Input: "hello"
 * Output: "holle"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "leetcode"
 * Output: "leotcede"
 * 
 * 
 * Note:
 * The vowels does not include the letter "y".
 * 
 * 
 * 
 */

// @lc code=start
#include <string>
#include <ctype.h>

class Solution {
public:
    std::string reverseVowels(std::string s) {
        int front = 0, back = s.length() - 1;
        while (front < back && !isVowel(s[front])) front++;
        while (front < back && !isVowel(s[back])) back--;
        while (front < back) {
            std::swap(s[front], s[back]);
            front++; back--;
            while (front < back && !isVowel(s[front])) front++;
            while (front < back && !isVowel(s[back])) back--;
        }
        return s;
    }

private:
    bool isVowel(char letter) {
        letter = tolower(letter);
        return (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u');
    }
};
// @lc code=end

