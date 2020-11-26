/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (56.81%)
 * Likes:    4929
 * Dislikes: 137
 * Total Accepted:    640.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given an array of distinct integers candidates and a target integer target,
 * return a list of all unique combinations of candidates where the chosen
 * numbers sum to target. You may return the combinations in any order.
 * 
 * The same number may be chosen from candidates an unlimited number of times.
 * Two combinations are unique if the frequency of at least one of the chosen
 * numbers is different.
 * 
 * It is guaranteed that the number of unique combinations that sum up to
 * target is less than 150 combinations for the given input.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7
 * Output: [[2,2,3],[7]]
 * Explanation:
 * 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple
 * times.
 * 7 is a candidate, and 7 = 7.
 * These are the only two combinations.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8
 * Output: [[2,2,2,2],[2,3,3],[3,5]]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: candidates = [2], target = 1
 * Output: []
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: candidates = [1], target = 1
 * Output: [[1]]
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: candidates = [1], target = 2
 * Output: [[1,1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= candidates.length <= 30
 * 1 <= candidates[i] <= 200
 * All elements of candidates are distinct.
 * 1 <= target <= 500
 * 
 * 
 */

// @lc code=start
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<int> candidate;
        std::vector<std::vector<int>> result;
        dfs(candidates, 0, target, candidate, result);
        return result;
    }

private:
    void dfs(const std::vector<int>& candidates, int idx, int res, std::vector<int>& candidate, std::vector<std::vector<int>>& result) {
        if (res == 0) {
            result.push_back(candidate);
        } else if (res < 0) {
            return;
        }

        for (int i = idx; i < candidates.size(); ++i) {
            candidate.push_back(candidates[i]);
            dfs(candidates, i, res - candidates[i], candidate, result);
            candidate.pop_back();
        }
    }
};
// @lc code=end

