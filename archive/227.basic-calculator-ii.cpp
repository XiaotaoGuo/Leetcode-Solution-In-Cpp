/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 *
 * https://leetcode.com/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (34.55%)
 * Likes:    923
 * Dislikes: 163
 * Total Accepted:    135.9K
 * Total Submissions: 389K
 * Testcase Example:  '"3+2*2"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string contains only non-negative integers, +, -, *, /
 * operators and empty spaces  . The integer division should truncate toward
 * zero.
 * 
 * Example 1:
 * 
 * 
 * Input: "3+2*2"
 * Output: 7
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: " 3/2 "
 * Output: 1
 * 
 * Example 3:
 * 
 * 
 * Input: " 3+5 / 2 "
 * Output: 5
 * 
 * 
 * Note:
 * 
 * 
 * You may assume that the given expression is always valid.
 * Do not use the eval built-in library function.
 * 
 * 
 */

// @lc code=start
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int calculate(string s) {
                stack<string> ops;
        vector<string> postorder;
        int begin = 0;
        while(begin < s.length()){
            // if it is a number
            if(isdigit(s[begin])){
                int len = 1;
                int after = begin + 1; 
                while(after < s.length() && isdigit(s[after])){
                    len++;
                    after++;
                }
                postorder.push_back(s.substr(begin, len));
                // if the top of stack is * or /
                if(!ops.empty()){
                    if(ops.top() == "*" || ops.top() == "/"){     
                        postorder.push_back(ops.top());
                        ops.pop();
                    }
                }
                begin = after;
            }
            else if(s[begin] == ' '){
                begin++;
            }
            else{
                if(s[begin] == '+' || s[begin] == '-'){
                    if(!ops.empty() && ops.top() == "-"){     
                        postorder.push_back(ops.top());
                        ops.pop();
                    }
                }
                ops.push(s.substr(begin, 1));
                begin++;
            }
        }
        while(!ops.empty()){
            postorder.push_back(ops.top());
            ops.pop();
        }
        stack<int> nums;
        for(uint i = 0; i < postorder.size(); i++){
            if(postorder[i] == "+"){
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                nums.push(num1 + num2);
            }
            else if(postorder[i] == "-"){
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                nums.push(num2- num1);
            }
            else if(postorder[i] == "*"){
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                nums.push(num1 * num2);
            }
            else if(postorder[i] == "/"){
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                nums.push(int(num2 / num1));
            }
            else{
                nums.push(stoi(postorder[i]));
            }
        }
        return nums.top();
    }
};
// @lc code=end

