/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 *
 * https://leetcode.com/problems/text-justification/description/
 *
 * algorithms
 * Hard (27.59%)
 * Likes:    746
 * Dislikes: 1663
 * Total Accepted:    143.1K
 * Total Submissions: 509.1K
 * Testcase Example:  '["This", "is", "an", "example", "of", "text", "justification."]\n16'
 *
 * Given an array of words and a width maxWidth, format the text such that each
 * line has exactly maxWidth characters and is fully (left and right)
 * justified.
 * 
 * You should pack your words in a greedy approach; that is, pack as many words
 * as you can in each line. Pad extra spaces ' ' when necessary so that each
 * line has exactly maxWidth characters.
 * 
 * Extra spaces between words should be distributed as evenly as possible. If
 * the number of spaces on a line do not divide evenly between words, the empty
 * slots on the left will be assigned more spaces than the slots on the right.
 * 
 * For the last line of text, it should be left justified and no extra space is
 * inserted between words.
 * 
 * Note:
 * 
 * 
 * A word is defined as a character sequence consisting of non-space characters
 * only.
 * Each word's length is guaranteed to be greater than 0 and not exceed
 * maxWidth.
 * The input array words contains at least one word.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * words = ["This", "is", "an", "example", "of", "text", "justification."]
 * maxWidth = 16
 * Output:
 * [
 * "This    is    an",
 * "example  of text",
 * "justification.  "
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * words = ["What","must","be","acknowledgment","shall","be"]
 * maxWidth = 16
 * Output:
 * [
 * "What   must   be",
 * "acknowledgment  ",
 * "shall be        "
 * ]
 * Explanation: Note that the last line is "shall be    " instead of "shall
 * be",
 * because the last line must be left-justified instead of fully-justified.
 * ⁠            Note that the second line is also left-justified becase it
 * contains only one word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * words =
 * ["Science","is","what","we","understand","well","enough","to","explain",
 * "to","a","computer.","Art","is","everything","else","we","do"]
 * maxWidth = 20
 * Output:
 * [
 * "Science  is  what we",
 * ⁠ "understand      well",
 * "enough to explain to",
 * "a  computer.  Art is",
 * "everything  else  we",
 * "do                  "
 * ]
 * 
 * 
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        int slow = 0, fast = 0;
        int curLen = 0;
        int count = 0;
        std::string line;
        std::vector<std::string> text;
        while (fast < words.size()) {
            curLen = 0;             // current length for all chosen words
            int min_spaces = 0;    // min number of spaces we need for current line

            // keep adding next word to current line until it reach maxWidth
            while (fast < words.size() && curLen + words[fast].length() + min_spaces <= maxWidth) {
                min_spaces++;
                curLen += words[fast].length();
                fast++;
            }

            // we reach the last line
            if (fast == words.size()) break;

            // only 1 word in line
            if (fast == slow + 1) {
                line = words[slow];
                line += std::string(maxWidth - words[slow].length(), ' ');
            } else {
                int count_gap = fast - slow - 1;
                int base_spaces = (maxWidth - curLen) / count_gap;  // should be at least 1
                int res_spaces = (maxWidth - curLen) % count_gap;
                for (int i = slow; i < fast - 1; i++) {
                    line += words[i];
                    line += std::string(base_spaces, ' ');
                    if (res_spaces) {
                        line += ' ';
                        res_spaces--;
                    }
                }
                line += words[fast - 1];
            }
            text.push_back(line);
            line = "";
            slow = fast;
        }

        for (int i = slow; i < fast - 1; i++) {
            line += words[i];
            line += ' ';
        }
        line += words[fast - 1];
        line += std::string(maxWidth - line.length(), ' ');
        text.push_back(line);

        return text;
    }
};
// @lc code=end

