/*
 * @lc app=leetcode id=282 lang=cpp
 *
 * [282] Expression Add Operators
 *
 * https://leetcode.com/problems/expression-add-operators/description/
 *
 * algorithms
 * Hard (35.73%)
 * Likes:    1475
 * Dislikes: 244
 * Total Accepted:    119.4K
 * Total Submissions: 328.3K
 * Testcase Example:  '"123"\n6'
 *
 * Given a string that contains only digits 0-9 and a target value, return all
 * possibilities to add binary operators (not unary) +, -, or * between the
 * digits so they evaluate to the target value.
 * 
 * Example 1:
 * 
 * 
 * Input: num = "123", target = 6
 * Output: ["1+2+3", "1*2*3"] 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: num = "232", target = 8
 * Output: ["2*3+2", "2+3*2"]
 * 
 * Example 3:
 * 
 * 
 * Input: num = "105", target = 5
 * Output: ["1*0+5","10-5"]
 * 
 * Example 4:
 * 
 * 
 * Input: num = "00", target = 0
 * Output: ["0+0", "0-0", "0*0"]
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: num = "3456237490", target = 9191
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= num.length <= 10
 * num only contain digits.
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> addOperators(std::string num, int target) {

        m_target = target;
        std::string path;
        generatePath(num, 0, path, 0, 0);

        return m_result;
    }

private:
    std::vector<std::string> m_result;
    int m_target;

    void generatePath(const std::string& num, int idx, std::string& path, long curr_eval, long prev_eval) {
        if (idx == num.length()) {
            if (curr_eval == m_target) {
                m_result.push_back(path);
            }
            return;
        }

        long candidate = 0;
        for (int i = idx; i < num.length(); ++i) {
            if (i != idx && num[idx] == '0') break; // number begins with 0 and not 0 (e.g 01) is invalid

            candidate *= 10;
            candidate += (num[i] - '0');

            std::string candidate_str = std::to_string(candidate);
            if (idx == 0) {
                // if this is the beginning of path, (e.g path == ""), no previous operator is required
                path += candidate_str;
                generatePath(num, i + 1, path, candidate, candidate);
                path.erase(path.length() - candidate_str.length());
            }
            else {
                // #1 : addition
                path += "+";
                path += candidate_str;
                generatePath(num, i + 1, path, curr_eval + candidate, candidate);
                
                // #2 : substraction
                path[path.length() - candidate_str.length() - 1] = '-';
                generatePath(num, i + 1, path, curr_eval - candidate, - candidate);

                // #3 : multiplication
                path[path.length() - candidate_str.length() - 1] = '*';
                generatePath(num, i + 1, path, curr_eval - prev_eval + prev_eval * candidate, prev_eval * candidate);

                // reset path by erase operator and new number
                path.erase(path.length() - candidate_str.length() - 1);
            }
        }
    }
};
// @lc code=end

