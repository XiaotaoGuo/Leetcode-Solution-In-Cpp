/*
 * @lc app=leetcode id=967 lang=cpp
 *
 * [967] Numbers With Same Consecutive Differences
 *
 * https://leetcode.com/problems/numbers-with-same-consecutive-differences/description/
 *
 * algorithms
 * Medium (39.33%)
 * Likes:    377
 * Dislikes: 92
 * Total Accepted:    27.7K
 * Total Submissions: 65.1K
 * Testcase Example:  '3\n7'
 *
 * Return all non-negative integers of length N such that the absolute
 * difference between every two consecutive digits is K.
 * 
 * Note that every number in the answer must not have leading zeros except for
 * the number 0 itself. For example, 01 has one leading zero and is invalid,
 * but 0 is valid.
 * 
 * You may return the answer in any order.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: N = 3, K = 7
 * Output: [181,292,707,818,929]
 * Explanation: Note that 070 is not a valid number, because it has leading
 * zeroes.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: N = 2, K = 1
 * Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 9
 * 0 <= K <= 9
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> numsSameConsecDiff(int N, int K) {
        if (N == 1) {
            return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        }
        std::string curr_num;
        std::vector<int> candidates;
        for (int i = 1; i < 10; i++) {
            curr_num = std::to_string(i);
            findNumbers(N, K, curr_num, candidates);
        }
        return candidates;
    }

private:
    void findNumbers(int N, int K, std::string& curr_num, std::vector<int>& candidates) {
        if (curr_num.length() == N) {
            candidates.push_back(std::stoi(curr_num));
            return;
        }
        
        char last_digit = curr_num.back();
        char next_digit = last_digit - K;
        if (std::isdigit(next_digit)) {
            curr_num.push_back(next_digit);
            findNumbers(N, K, curr_num, candidates);
            curr_num.pop_back();
        }
        
        if (K != 0) {
            next_digit = last_digit + K;
            if (std::isdigit(next_digit)) {
                curr_num.push_back(next_digit);
                findNumbers(N, K, curr_num, candidates);
                curr_num.pop_back();
            }
        }
    }
};
// @lc code=end

