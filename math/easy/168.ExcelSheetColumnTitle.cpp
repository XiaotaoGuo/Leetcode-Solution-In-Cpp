/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 *
 * https://leetcode.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (30.94%)
 * Likes:    1329
 * Dislikes: 264
 * Total Accepted:    227.7K
 * Total Submissions: 729.2K
 * Testcase Example:  '1'
 *
 * Given a positive integer, return its corresponding column title as appear in
 * an Excel sheet.
 * 
 * For example:
 * 
 * 
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB 
 * ⁠   ...
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "A"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 28
 * Output: "AB"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 701
 * Output: "ZY"
 * 
 */

// @lc code=start
#include <string>
#include <algorithm>

class Solution {
public:
    std::string convertToTitle(int n) {
        
        std::string result = "";
        while (n > 0) {
            n--;
            result += 'A' + (n % 26);
            n /= 26;
        }
        std::reverse(result.begin(), result.end());

        return result;
    }
};
// @lc code=end

