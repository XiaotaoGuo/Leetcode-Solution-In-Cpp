/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (50.68%)
 * Likes:    1357
 * Dislikes: 94
 * Total Accepted:    364.2K
 * Total Submissions: 711.4K
 * Testcase Example:  '"leetcode"'
 *
 * 
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contain only lowercase letters.
 * 
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
       int hmap[26];
        memset(hmap, 0, 26 * sizeof(int));
        for(int i = 0; i < s.length(); i++){
            hmap[s[i]-'a']++;
        }
        
        for(int i = 0; i < s.length(); i++){
            if(hmap[s[i]-'a'] == 1) return i;
        }
        
        return -1; 
    }
};
// @lc code=end

