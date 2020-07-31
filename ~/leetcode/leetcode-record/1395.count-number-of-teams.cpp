/*
 * @lc app=leetcode id=1395 lang=cpp
 *
 * [1395] Count Number of Teams
 */

// @lc code=start
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int counts = 0;
        
        for (int i = 0; i < rating.size(); i++) {
            int left = 0;
            int right = 0;
            
            for (int j = 0; j < rating.size(); j++) {
                if (j < i && rating[j] < rating[i]) {
                    left++;
                }
                if (j > i && rating[j] > rating[i]) {
                    right++;
                }
                
                // we have left rating is less than rating[i] and right ratings larger than rating[i]
                
            }
            counts += left * right;
            counts += (i - left) * (rating.size() - 1 - i - right);
        }
        
        return counts;
    }
};
// @lc code=end

