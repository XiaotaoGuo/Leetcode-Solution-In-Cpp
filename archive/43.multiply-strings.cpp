/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (31.60%)
 * Likes:    1288
 * Dislikes: 599
 * Total Accepted:    238.8K
 * Total Submissions: 746K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Example 1:
 * 
 * 
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * 
 * 
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Note:
 * 
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
                if(num1 == "0" || num2 == "0") return "0";
        int n1 = num1.length(), n2 = num2.length();
        vector<int> digits(n1 + n2, 0);
        for(int i = n1 - 1; i >= 0; i--){
            for(int j = n2 - 1; j>= 0; j--){
                
                int d1 = num1[i] - '0';
                int d2 = num2[j] - '0';
                int product = d1 * d2;
                int idx = i + j;
                int l = product / 10;
                int r = product % 10;
                digits[idx] += l;
                digits[idx+1] += r;
                
                if(digits[idx+1] >= 10){
                    digits[idx]++;
                    digits[idx+1] -= 10;
                }
                if(digits[idx] >= 10){
                    digits[idx - 1]++;
                    digits[idx] -= 10;
                }
            }
        }
        
        string result = "";
        int i = 0;
        while(i < digits.size() && digits[i] == 0) i++;
        while(i < digits.size()){
            result += to_string(digits[i]);
            i++;
        }
        return result;
    }
};
// @lc code=end

