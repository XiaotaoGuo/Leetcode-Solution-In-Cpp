/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (55.92%)
 * Likes:    918
 * Dislikes: 741
 * Total Accepted:    586.9K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3,1]'
 *
 * Given an array of integers, find if the array contains any duplicates.
 * 
 * Your function should return true if any value appears at least twice in the
 * array, and it should return false if every element is distinct.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,1]
 * Output: true
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,4]
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 * 
 */

// @lc code=start

#include <vector>
#include <algorithm>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
//         std::unordered_set<int> seen_nums;
//         for (int num: nums) {
//             if (seen_nums.count(num) != 0) return true;
//             seen_nums.insert(num);
//         }
        
//         return false;
        
        if (nums.empty()) return false;
        
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) return true;
        }
        return false;
    }
};
// @lc code=end

