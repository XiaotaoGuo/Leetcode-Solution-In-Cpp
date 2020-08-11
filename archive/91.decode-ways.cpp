/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (22.91%)
 * Likes:    1760
 * Dislikes: 1995
 * Total Accepted:    303.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 * 
 * Example 1:
 * 
 * 
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 * 
 */

// @lc code=start
#include<string>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        if(!size or s[0] == '0')  return 0;
        if(size == 1) return 1;        
        int last = 1, secondlast = 1, res = 0;

        for(int i = 1; i < s.size(); i++)
        {
            res = 0;
            int first = stoi(s.substr(i, 1));
            int second = stoi(s.substr(i-1, 2));
            if(first >= 1 and first <= 9)
                res += last;
            if(second >= 10 and second <= 26)
                res += secondlast;
            secondlast = last;
            last = res;
        }
        return res;
    }
};
// @lc code=end

