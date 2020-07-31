/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;
        for(int i = 0; i < nums.size(); i++) {
            if (seen.find(target - nums[i]) != seen.end()) {
                return {seen[target - nums[i]], i};
            }
            seen[nums[i]] = i;
        }

        return {};
    }
};
// @lc code=end

