/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Hard (30.48%)
 * Likes:    2648
 * Dislikes: 140
 * Total Accepted:    264.9K
 * Total Submissions: 868K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * Example:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2.
 * ⁠   Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * 
 * Note:
 * 
 * You can assume that you can always reach the last index.
 * 
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        
        int boundary = 0; // current furthest index from last jump
        int furthest_possible_index = 0; // furthest possible index
        int steps = 0; // steps that we need to reach the end
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > boundary) {
                // if current index has crossed the furthest index from last jump,
                // we need to select an best index from one of the previous indexes and perform a jump
                // it should increase the boundary to furthest possible index
                steps++;
                boundary = furthest_possible_index;
            }
            
            furthest_possible_index = std::max(furthest_possible_index, nums[i] + i);
        }
        
        return steps;
    }
};
// @lc code=end

