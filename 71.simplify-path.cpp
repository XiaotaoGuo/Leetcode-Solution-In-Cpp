/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 *
 * https://leetcode.com/problems/simplify-path/description/
 *
 * algorithms
 * Medium (29.67%)
 * Likes:    506
 * Dislikes: 1339
 * Total Accepted:    164.4K
 * Total Submissions: 554.1K
 * Testcase Example:  '"/home/"'
 *
 * Given an absolute path for a file (Unix-style), simplify it. Or in other
 * words, convert it to the canonical path.
 * 
 * In a UNIX-style file system, a period . refers to the current directory.
 * Furthermore, a double period .. moves the directory up a level. For more
 * information, see: Absolute path vs relative path in Linux/Unix
 * 
 * Note that the returned canonical path must always begin with a slash /, and
 * there must be only a single slash / between two directory names. The last
 * directory name (if it exists) must not end with a trailing /. Also, the
 * canonical path must be the shortest string representing the absolute
 * path.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "/home/"
 * Output: "/home"
 * Explanation: Note that there is no trailing slash after the last directory
 * name.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "/../"
 * Output: "/"
 * Explanation: Going one level up from the root directory is a no-op, as the
 * root level is the highest level you can go.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "/home//foo/"
 * Output: "/home/foo"
 * Explanation: In the canonical path, multiple consecutive slashes are
 * replaced by a single one.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "/a/./b/../../c/"
 * Output: "/c"
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "/a/../../b/../c//.//"
 * Output: "/c"
 * 
 * 
 * Example 6:
 * 
 * 
 * Input: "/a//b////c/d//././/.."
 * Output: "/a/b/c"
 * 
 * 
 */

#include<stack>
#include<string>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        if(!path.length()) return "";
        int pos = 0;
        while(pos < path.length()){
            
            if(path[pos] == '/'){
                while(pos < path.length() && path[pos] == '/') pos++;
            }
            else{
                
                string curr = "";
                while(pos < path.length() && path[pos] != '/'){
                    curr += string(1, path[pos]);
                    pos++;
                }
                if(curr == "."){
                    continue;
                }
                else if(curr == ".."){
                    if(!s.empty()){ 
                        s.pop(); // pop the previous folder id
                    }
                }
                else{
                    s.push(curr);
                }
            }
        }
        string ans = "";
        
        while(!s.empty()){
            if(!ans.empty()) ans = "/" + ans;
            ans = s.top() + ans;
            s.pop();
        }
        ans = "/" + ans;
        return ans;
    }
};

