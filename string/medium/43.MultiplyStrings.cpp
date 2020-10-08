/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (34.17%)
 * Likes:    1949
 * Dislikes: 862
 * Total Accepted:    317.9K
 * Total Submissions: 928.8K
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
//
#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        std::vector<std::string> prods;
        for (int i = num1.length() - 1; i >= 0; i--) {
            std::string prod = multiplyOneDigit(num2, num1[i] - '0');
            prod += std::string(num1.length() - 1 - i, '0');
            prods.push_back(prod);
        }

        std::string result = prods[0];
        for (int i = 1; i < prods.size(); i++) {
            result = addTwoInt(result, prods[i]);
        }

        return result;
    }

private:
    std::string multiplyOneDigit(const std::string& num, int digit) {
        std::string result = "";
        int res = 0;
        for (int i = num.length() - 1; i >= 0; i--) {
            int prod = (num[i] - '0') * digit;
            std::string prod_s =
                std::to_string(prod) + std::string(num.length() - 1 - i, '0');
            result = addTwoInt(result, prod_s);
        }

        if (res > 0) {
            result += ('0' + res);
        }
        return result;
    }

    std::string addTwoInt(const std::string& num1, const std::string& num2) {
        std::string result = "";
        int ptr1 = num1.length() - 1, ptr2 = num2.length() - 1;
        int res = 0;
        while (ptr1 >= 0 || ptr2 >= 0) {
            int sum = 0;
            if (ptr2 >= 0) {
                sum += num2[ptr2] - '0';
            }
            if (ptr1 >= 0) {
                sum += num1[ptr1] - '0';
            }
            sum += res;
            res = 0;
            if (sum >= 10) {
                res = 1;
                sum -= 10;
            }
            ptr1--;
            ptr2--;
            result += ('0' + sum);
        }
        if (res > 0) {
            result += ('0' + res);
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end
