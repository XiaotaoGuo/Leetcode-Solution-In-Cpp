/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || s.length() <= numRows) return s;
        
        vector<string> rows(numRows, "");
        
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
        
        string result = "";
        for (int i = 0; i < numRows; i++) {
            result += rows[i];
        }
        
        return result;
    }
};
// @lc code=end

