/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (26.49%)
 * Likes:    2442
 * Dislikes: 3616
 * Total Accepted:    619K
 * Total Submissions: 2.3M
 * Testcase Example:  '"the sky is blue"'
 *
 * Given an input string s, reverse the order of the words.
 * 
 * A word is defined as a sequence of non-space characters. The words in s will
 * be separated by at least one space.
 * 
 * Return a string of the words in reverse order concatenated by a single
 * space.
 * 
 * Note that s may contain leading or trailing spaces or multiple spaces
 * between two words. The returned string should only have a single space
 * separating the words. Do not include any extra spaces.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "the sky is blue"
 * Output: "blue is sky the"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "  hello world  "
 * Output: "world hello"
 * Explanation: Your reversed string should not contain leading or trailing
 * spaces.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "a good   example"
 * Output: "example good a"
 * Explanation: You need to reduce multiple spaces between two words to a
 * single space in the reversed string.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "  Bob    Loves  Alice   "
 * Output: "Alice Loves Bob"
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: s = "Alice does not even like bob"
 * Output: "bob like even not does Alice"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^4
 * s contains English letters (upper-case and lower-case), digits, and spaces '
 * '.
 * There is at least one word in s.
 * 
 * 
 * 
 * Follow-up: If the string data type is mutable in your language, can you
 * solve it in-place with O(1) extra space?
 * 
 */

// @lc code=start
#include<string>
#include<algorithm>

class Solution {
public:
    std::string reverseWords(std::string s) {
        int back = 0;
        int front = 0;

        // filter spaces
        while (front < s.length())
        {
            while (front < s.length() && s[front] == ' ') front++;

            if (front == s.length()) break;

            if (back != 0){
                s[back] = ' ';
                back++;
            }
            
            while (front < s.length() && s[front] != ' ')
            {
                s[back] = s[front];
                back++;
                front++;
            }
        }
        
        // remove extra space
        while(back < front) {
            s.pop_back();
            front--;
        }
        
        // reverse whole string, words would be reversed as well
        std::reverse(s.begin(), s.end());
        back = 0;
        front = 0;

        // for each word, reverse it back to normal order
        while (front < s.length())
        {
            while (front < s.length() && s[front] != ' ')
            {
                front++;
            }
            std::reverse(s.begin() + back, s.begin() + front);
            back = front + 1;
            front = back;
        }

        return s;
    }

};
// @lc code=end

