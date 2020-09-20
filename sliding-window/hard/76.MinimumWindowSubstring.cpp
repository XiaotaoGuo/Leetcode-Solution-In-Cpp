/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (34.51%)
 * Likes:    5079
 * Dislikes: 343
 * Total Accepted:    431.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * Example:
 * 
 * 
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * 
 * 
 * Note:
 * 
 * 
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 * 
 * 
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include<bits/stdc++.h>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        std::unordered_map<char, int> record;
        for (char c: t) record[c]++;
        int begin = 0;              // final string begin index
        int final_length = INT_MAX; // final string length
        int to_match = t.length();  // character to be matched

        int front = 0, back = 0;    // two-pointer defining sliding window

        while (back < s.length()) { // expanding sliding window

            if (record[s[back]] > 0) {  // target char
                to_match--;
            }

            record[s[back]]--;

            while(to_match == 0) {  // now we have all needed chars in sliding window, so compress it
                int len = back - front + 1;
                if (len < final_length) {   // if current substr is shorter update final result
                    final_length = len;
                    begin = front;
                }
                record[s[front]]++;
                if (record[s[front]] > 0) to_match++;
                front++;
            }

            back++;
        }

        return final_length == INT_MAX ? "" : s.substr(begin, final_length);

    }
};
// @lc code=end

