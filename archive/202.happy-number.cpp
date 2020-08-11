/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (46.65%)
 * Likes:    1229
 * Dislikes: 305
 * Total Accepted:    298.8K
 * Total Submissions: 626.6K
 * Testcase Example:  '19'
 *
 * Write an algorithm to determine if a number is "happy".
 * 
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 * 
 * Example: 
 * 
 * 
 * Input: 19
 * Output: true
 * Explanation: 
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * 
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        
        while(n != 1){
            s.insert(n);
            int n1 = n;
            int result = 0;
            while(n1){
                int res = n1 % 10;
                n1 /= 10;
                result += res * res; 
            }
            n = result;
            if(s.count(n) != 0) return false;
        }
        
        return true;
    }
};
// @lc code=end

