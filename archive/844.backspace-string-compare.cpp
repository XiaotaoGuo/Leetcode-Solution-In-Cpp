/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 *
 * https://leetcode.com/problems/backspace-string-compare/description/
 *
 * algorithms
 * Easy (46.63%)
 * Likes:    824
 * Dislikes: 51
 * Total Accepted:    78.2K
 * Total Submissions: 167.7K
 * Testcase Example:  '"ab#c"\n"ad#c"'
 *
 * Given two strings S and T, return if they are equal when both are typed into
 * empty text editors. # means a backspace character.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: S = "ab#c", T = "ad#c"
 * Output: true
 * Explanation: Both S and T become "ac".
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: S = "ab##", T = "c#d#"
 * Output: true
 * Explanation: Both S and T become "".
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: S = "a##c", T = "#a#c"
 * Output: true
 * Explanation: Both S and T become "c".
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: S = "a#c", T = "b"
 * Output: false
 * Explanation: S becomes "c" while T becomes "b".
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= S.length <= 200
 * 1 <= T.length <= 200
 * S and T only contain lowercase letters and '#' characters.
 * 
 * 
 * Follow up:
 * 
 * 
 * Can you solve it in O(N) time and O(1) space?
 * 
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
#include<string>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int pos1 = S.length() - 1;
        int pos2 = T.length() - 1;
        while(pos1 >= 0 || pos2 >= 0){
            if(pos1 >= 0 && S[pos1] == '#'){
                int count = 1;
                pos1--;
                while(pos1 >= 0 && (count > 0 || S[pos1] == '#')){
                    if(S[pos1] == '#') count++;
                    else count--;
                    pos1--;
                }
            }
            
            if(pos2 >= 0 && T[pos2] == '#'){
                int count = 1;
                pos2--;
                while(pos2 >= 0 && (count > 0 || T[pos2] == '#')){
                    if(T[pos2] == '#') count++;
                    else count--;
                    pos2--;
                }
            }
            if(pos1 == -1 && pos2 != -1) return false;
            if(pos2 == -1 && pos1 != -1) return false;
            if(pos1 == -1 && pos2 == -1) return true;
            if(S[pos1] != T[pos2]) return false;
            pos1--;
            pos2--;
        }
        return true;
    }
};
// @lc code=end

