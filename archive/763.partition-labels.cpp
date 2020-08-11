/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> hmap(26, 0);
        for(const char& c: S) hmap[c - 'a']++;
        unordered_set<char> s_char;
        vector<int> ans;
        int l = -1, r = 0;
        for(int i = 0; i < S.length(); i++){
            s_char.insert(S[i]);
            hmap[S[i] - 'a']--;
            if(hmap[S[i] - 'a'] == 0){
                s_char.erase(S[i]);
            }
            if(s_char.empty()){
                ans.push_back(r - l);
                l = i;
            }
            r++;
        }
        return ans;
    }
};
// @lc code=end

