/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (43.06%)
 * Likes:    2784
 * Dislikes: 349
 * Total Accepted:    476.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return {};
        unordered_map<char, string> hmap;
        hmap['2'] = "abc";
        hmap['3'] = "def";
        hmap['4'] = "ghi";
        hmap['5'] = "jkl";
        hmap['6'] = "mno";
        hmap['7'] = "pqrs";
        hmap['8'] = "tuv";
        hmap['9'] = "wxyz";
        string currResult = "";
        vector<string> result = {};
        dfs(digits, hmap, 0, currResult, result);
        return result;
        
    }
private:
    void dfs(const string& digits, unordered_map<char, string>& hmap, int idx, string& currResult, vector<string>& result){
        if(idx == digits.size()){
            result.push_back(currResult);
        }
        for(int i = 0; i < hmap[digits[idx]].size(); i++){
            currResult.push_back(hmap[digits[idx]][i]);
            dfs(digits, hmap, idx+1, currResult, result);
            currResult.pop_back();
        }
    }
};
// @lc code=end

