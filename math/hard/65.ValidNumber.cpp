/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 *
 * https://leetcode.com/problems/valid-number/description/
 *
 * algorithms
 * Hard (15.25%)
 * Likes:    766
 * Dislikes: 5041
 * Total Accepted:    177.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '"0"'
 *
 * Validate if a given string can be interpreted as a decimal number.
 * 
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * " -90e3   " => true
 * " 1e" => false
 * "e3" => false
 * " 6e-1" => true
 * " 99e2.5 " => false
 * "53.5e93" => true
 * " --6 " => false
 * "-+3" => false
 * "95a54e53" => false
 * 
 * Note: It is intended for the problem statement to be ambiguous. You should
 * gather all requirements up front before implementing one. However, here is a
 * list of characters that can be in a valid decimal number:
 * 
 * 
 * Numbers 0-9
 * Exponent - "e"
 * Positive/negative sign - "+"/"-"
 * Decimal point - "."
 * 
 * 
 * Of course, the context of these characters also matters in the input.
 * 
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your
 * function signature accepts a const char * argument, please click the reload
 * button to reset your code definition.
 * 
 */

// @lc code=start
#include <string>
#include <unordered_set>
#include <cctype>

class Solution {
public:
    bool isNumber(std::string s) {
        int front = 0, back = s.length(); // 前闭后开区间
        while (front < back && s[front] == ' ') front++;
        while (front < back && s[back - 1] == ' ') back--;
        if (front == back) return false;
        int med = -1;
        for (int i = front; i < back; i++) {
            if (s[i] == 'e') {
                if (med != -1) return false; // find 2 e!
                else med = i;
            }
        }

        if (med == -1) { // find no e!
            return isValidNumber(s, front, back, true);
        }
        else {
            bool is_valid = isValidNumber(s, front, med, true); // the first part can be decimal
            if (!is_valid) return false;
            is_valid = isValidNumber(s, med + 1, back, false);  // the second part can't be decimal
            return is_valid;
        }
        
        return true;
    }

private:
    bool isValidNumber(const std::string& s, int front, int back, bool can_be_decimal) {
        if (front == back) {
            return false;
        }
        if (back == front + 1) {
            return std::isdigit(s[front]);
        }
        std::unordered_set<char> symbols_record;
        for (int i = front; i < back; i++) {
            char symbol = s[i];
            if (symbol == '+' || symbol == '-') { // if we find a sign, it must be at the begin
                if (i != front) return false;
            } else if (symbol == '.') { // if we find a '.'
                if (!can_be_decimal ||                                              // can't be decimal
                     symbols_record.count('.')) return false;  // or find two '.'
                else {
                    symbols_record.insert('.');
                }
            } else if (std::isdigit(symbol)) {  // a valid number at least have 1 digit
                symbols_record.insert('0'); // use '0' represent digit
                continue;
            } else {
                return false;
            }
        }

        return symbols_record.count('0');
    }
};
// @lc code=end

