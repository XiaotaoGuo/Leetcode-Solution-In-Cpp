/*
 * @lc app=leetcode id=917 lang=cpp
 *
 * [917] Reverse Only Letters
 *
 * https://leetcode.com/problems/reverse-only-letters/description/
 *
 * algorithms
 * Easy (56.23%)
 * Likes:    324
 * Dislikes: 30
 * Total Accepted:    37.8K
 * Total Submissions: 67K
 * Testcase Example:  '"ab-cd"'
 *
 * Given a string S, return the "reversed" string where all characters that are
 * not a letter stay in the same place, and all letters reverse their
 * positions.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "ab-cd"
 * Output: "dc-ba"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "a-bC-dEf-ghIj"
 * Output: "j-Ih-gfE-dCba"
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "Test1ng-Leet=code-Q!"
 * Output: "Qedo1ct-eeLg=ntse-T!"
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * S.length <= 100
 * 33 <= S[i].ASCIIcode <= 122 
 * S doesn't contain \ or "
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
    string reverseOnlyLetters(string S) {
        int left = 0, right = S.length() -1;
        while(left < right && !isalpha(S[left])) left++;
        while(right > left && !isalpha(S[right])) right--;
        while(left < right){
            swap(S[left], S[right]);
            left++;
            right--;
            while(left < right && !isalpha(S[left])) left++;
            while(right > left && !isalpha(S[right])) right--;
        }
        
        return S;
    }
};
// @lc code=end

