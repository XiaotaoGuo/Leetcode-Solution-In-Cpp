/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (47.56%)
 * Likes:    2032
 * Dislikes: 91
 * Total Accepted:    308K
 * Total Submissions: 641K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 *
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
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
            if (i != idx && nums[i] == nums[i - 1]) continue;
            subset.push_back(nums[i]);
            dfs(nums, i + 1, subset, result);
            subset.pop_back();
        }
    }
};
// @lc code=end
