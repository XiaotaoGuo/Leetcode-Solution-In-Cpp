/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (42.74%)
 * Likes:    2457
 * Dislikes: 140
 * Total Accepted:    250.8K
 * Total Submissions: 577.4K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 * 
 * Your algorithm should run in O(n) complexity.
 * 
 * Example:
 * 
 * 
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> h;
        int ans = 0;
        for (int num : nums) {
            if (h.count(num)) continue;
            
            auto it_l = h.find(num - 1);
            auto it_r = h.find(num + 1);
            
            int l = it_l != h.end() ? it_l->second : 0;
            int r = it_r != h.end() ? it_r->second : 0;
            int t = l + r + 1;
            
            h[num] = h[num - l] = h[num + r] = t;
            
            ans = max(ans, t);            
        }
        
        return ans;
    }
};
// @lc code=end

