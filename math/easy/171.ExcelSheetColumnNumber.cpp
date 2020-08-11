/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 *
 * https://leetcode.com/problems/excel-sheet-column-number/description/
 *
 * algorithms
 * Easy (54.45%)
 * Likes:    1158
 * Dislikes: 165
 * Total Accepted:    315.6K
 * Total Submissions: 567.9K
 * Testcase Example:  '"A"'
 *
 * Given a column title as appear in an Excel sheet, return its corresponding
 * column number.
 * 
 * For example:
 * 
 * 
 * ⁠   A -> 1
 * ⁠   B -> 2
 * ⁠   C -> 3
 * ⁠   ...
 * ⁠   Z -> 26
 * ⁠   AA -> 27
 * ⁠   AB -> 28 
 * ⁠   ...
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "A"
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "AB"
 * Output: 28
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "ZY"
 * Output: 701
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 7
 * s consists only of uppercase English letters.
 * s is between "A" and "FXSHRXW".
 * 
 * 
 */

// @lc code=start
#include <string>

class Solution {
public:
    int titleToNumber(std::string s) {
        
        int number = 0;
        long coeff = 1;
        for (int i = s.length() - 1; i >= 0; i--) {
            number += (s[i] - 'A' + 1) * coeff;
            coeff *= 26;
        }
        
        return number;
        
    }
};
// @lc code=end

