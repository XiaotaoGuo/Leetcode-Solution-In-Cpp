/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (40.60%)
 * Likes:    1246
 * Dislikes: 233
 * Total Accepted:    361.4K
 * Total Submissions: 874.1K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        bool flag = false;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int idx = 0;
        string ans = "";
        while(idx < a.length() && idx < b.length()){
            if(a[idx] != b[idx]){
                ans += '1' + flag;
                flag = false;
            }
            else if(a[idx] == '1'){
                ans += '0' + flag;
                flag = true;
            }
            else{
                ans += '0' + flag;
                flag = false;
            }
            if(ans.back() == '2'){
                ans.back() = '0';
                flag = true;
            }
            idx++;
        }
        
        if(idx < a.length()){
            while(flag && idx < a.length()){
                flag = false;
                ans += (a[idx] + 1);
                if(ans.back() == '2'){
                    flag = true;
                    ans.back() = '0';
                }
                idx++;
            }
            if(idx < a.length()){
                ans += a.substr(idx, a.length() - idx);
            }
        }
        else if(idx < b.length()){
            while(flag && idx < b.length()){
                flag = false;
                ans += (b[idx] + 1);
                if(ans.back() == '2'){
                    flag = true;
                    ans.back() = '0';
                }
                idx++;
            }
            if(idx < b.length()){
                ans += b.substr(idx, b.length() - idx);
            }
        }
        if(flag) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

