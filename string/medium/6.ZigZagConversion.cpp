/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (36.15%)
 * Likes:    1722
 * Dislikes: 4697
 * Total Accepted:    469K
 * Total Submissions: 1.3M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * 
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 */

// @lc code=start

#include <vector>
#include <string>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows <= 1 || s.length() <= numRows) return s;
        
        std::vector<std::string> rows(numRows, "");
        
        for (int i = 0; i < s.length(); i++) {
            /**
             *   x  x  x
             *   x xx x
             *   xx xx
             *   x  x
             *
             *   say we have n row, then 2(n - 1) forms a cycle of positions
             */
            
            int row = i % (2 * numRows - 2);
            if (row >= numRows) {
                row = 2 * numRows - 2 - row;
            }
            rows[row] += s[i];
        }
        
        std::string result = "";
        for (int i = 0; i < numRows; i++) {
            result += rows[i];
        }
        
        return result;
    }
};
// @lc code=end

