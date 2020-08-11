/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (49.44%)
 * Likes:    2209
 * Dislikes: 137
 * Total Accepted:    434.3K
 * Total Submissions: 856.5K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * Example:
 * 
 * 
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note:
 * 
 * 
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hmap;
        for(int i = 0; i < strs.size();i++){
            string curr = strs[i];
            sort(curr.begin(), curr.end());
            if(hmap.find(curr) == hmap.end()){
                hmap[curr] = vector<string>{strs[i]};
            }
            else{
                hmap[curr].push_back(strs[i]);
            }
        }
        
        vector<vector<string>> result;
        for(auto iter = hmap.begin(); iter != hmap.end(); iter++){
            result.push_back(iter->second);
        }
        return result;
    }
};
// @lc code=end

