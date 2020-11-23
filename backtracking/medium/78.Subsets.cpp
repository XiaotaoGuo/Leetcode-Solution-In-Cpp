/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (62.86%)
 * Likes:    4748
 * Dislikes: 96
 * Total Accepted:    667.6K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums, return all possible subsets (the power set).
 *
 * The solution set must not contain duplicate subsets.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0]
 * Output: [[],[0]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<int> subset;
        std::vector<std::vector<int>> result;

        std::sort(nums.begin(), nums.end());
        dfs(nums, 0, subset, result);
        return result;
    }

private:
    void dfs(const std::vector<int>& nums, size_t idx, std::vector<int>& subset,
             std::vector<std::vector<int>>& result) {
        result.push_back(subset);
        if (idx >= nums.size()) {
            return;
        }

        for (int i = idx; i < nums.size(); ++i) {
            subset.push_back(nums[i]);
            dfs(nums, i + 1, subset, result);
            subset.pop_back();
        }
    }
};
// @lc code=end
