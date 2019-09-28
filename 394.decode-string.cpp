/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (46.43%)
 * Likes:    1885
 * Dislikes: 105
 * Total Accepted:    130.9K
 * Total Submissions: 281.9K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 * 
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 * 
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 * 
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 * 
 * Examples:
 * 
 * 
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 * 
 * 
 * 
 * 
 */

#include<stack>
#include<string>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
                string ans = "";
        stack<string> stk1, stk2;
        int pos = 0;
        while(pos < s.length()){
            string curr = "";
            if(isdigit(s[pos])){
                while(isdigit(s[pos])){
                    curr += s[pos++];
                }
                stk1.push(curr);
            }
            else if(isalpha(s[pos])){
                while(isalpha(s[pos])){
                    curr += s[pos++];
                }
                stk2.push(curr);
            }
            else if(s[pos] == '['){
                stk2.push("[");
                pos++;
            }
            else{
                while(stk2.top() != "["){
                    curr = stk2.top() + curr;
                    stk2.pop();
                }
                stk2.pop();
                string next_str = "";
                for(int i = 0; i < stoi(stk1.top()); i++) next_str += curr;
                stk2.push(next_str);
                stk1.pop();
                pos++;
            }
        }
        
        while(!stk2.empty()){
            ans = stk2.top() + ans;
            stk2.pop();
        }
        return ans;
    }
};

