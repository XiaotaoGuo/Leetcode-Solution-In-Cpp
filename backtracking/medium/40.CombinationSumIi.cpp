/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (48.83%)
 * Likes:    2250
 * Dislikes: 77
 * Total Accepted:    366.3K
 * Total Submissions: 740.5K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sum to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note: The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8
 * Output: 
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5
 * Output: 
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<int> candidate;
        std::vector<std::vector<int>> result;
        std::sort(candidates.begin(), candidates.end());
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
            if (i != idx && candidates[i] == candidates[i - 1]) continue;
            candidate.push_back(candidates[i]);
            dfs(candidates, i + 1, res - candidates[i], candidate, result);
            candidate.pop_back();
        }
    }
};
// @lc code=end

