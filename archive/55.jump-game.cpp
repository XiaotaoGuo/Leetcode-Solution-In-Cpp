/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {

        // greedy
        int furthest_index = 0;
        int current_index = 0;
        while (current_index <= furthest_index && current_index < nums.size()) {
            furthest_index = max(furthest_index, current_index + nums[current_index]);
            current_index++;
        }

        return furthest_index >= nums.size() - 1;

    }
};
// @lc code=end

