/*
 * @lc app=leetcode id=398 lang=cpp
 *
 * [398] Random Pick Index
 *
 * https://leetcode.com/problems/random-pick-index/description/
 *
 * algorithms
 * Medium (59.22%)
 * Likes:    679
 * Dislikes: 863
 * Total Accepted:    124.8K
 * Total Submissions: 210.7K
 * Testcase Example:
 * '["Solution","pick","pick","pick"]\n[[[1,2,3,3,3]],[3],[1],[3]]'
 *
 * Given an integer array nums with possible duplicates, randomly output the
 * index of a given target number. You can assume that the given target number
 * must exist in the array.
 *
 * Implement the Solution class:
 *
 *
 * Solution(int[] nums) Initializes the object with the array nums.
 * int pick(int target) Picks a random index i from nums where nums[i] ==
 * target. If there are multiple valid i's, then each index should have an
 * equal probability of returning.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["Solution", "pick", "pick", "pick"]
 * [[[1, 2, 3, 3, 3]], [3], [1], [3]]
 * Output
 * [null, 4, 0, 2]
 *
 * Explanation
 * Solution solution = new Solution([1, 2, 3, 3, 3]);
 * solution.pick(3); // It should return either index 2, 3, or 4 randomly. Each
 * index should have equal probability of returning.
 * solution.pick(1); // It should return 0. Since in the array only nums[0] is
 * equal to 1.
 * solution.pick(3); // It should return either index 2, 3, or 4 randomly. Each
 * index should have equal probability of returning.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 2 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * target is an integer from nums.
 * At most 10^4 calls will be made to pick.
 *
 *
 */

// @lc code=start
#include <unordered_map>
#include <vector>

class Solution {
public:
    Solution(std::vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            hmap_[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        std::vector<int>& indices = hmap_[target];
        return indices[rand() % indices.size()];
    }

private:
    std::unordered_map<int, std::vector<int>> hmap_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end
