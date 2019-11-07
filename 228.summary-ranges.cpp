/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 *
 * https://leetcode.com/problems/summary-ranges/description/
 *
 * algorithms
 * Medium (36.89%)
 * Likes:    447
 * Dislikes: 440
 * Total Accepted:    144.7K
 * Total Submissions: 388.5K
 * Testcase Example:  '[0,1,2,4,5,7]'
 *
 * Given a sorted integer array without duplicates, return the summary of its
 * ranges.
 * 
 * Example 1:
 * 
 * 
 * Input:  [0,1,2,4,5,7]
 * Output: ["0->2","4->5","7"]
 * Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:  [0,2,3,4,6,8,9]
 * Output: ["0","2->4","6","8->9"]
 * Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
                if(nums.empty()) return {};
        if(nums.size() == 1) return vector<string>{to_string(nums[0])};
        string curr = "";
        int begin = nums[0], end = begin;
        vector<string> ranges;
        for(int i = 1; i < nums.size() - 1; i++){
            if(nums[i] == end + 1){
                end++;
            }
            else{
                curr += to_string(begin);
                if(end != begin){
                    curr += "->";
                    curr += to_string(end);
                }
                ranges.push_back(curr);
                begin = nums[i];
                end = begin;
                curr = "";
            }
        }
        
        curr += to_string(begin);
        if(nums.back() == end + 1){
            curr += "->";
            curr += to_string(nums.back());
            ranges.push_back(curr);
        }
        else{
            if(end != begin){
                curr += "->";
                curr += to_string(end);
            }
            ranges.push_back(curr);
            ranges.push_back(to_string(nums.back()));
        }
        
        return ranges;
    }
};
// @lc code=end

