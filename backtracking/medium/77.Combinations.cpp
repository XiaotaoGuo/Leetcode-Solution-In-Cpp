/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (55.48%)
 * Likes:    1844
 * Dislikes: 76
 * Total Accepted:    323.6K
 * Total Submissions: 575.7K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 *
 * You may return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1, k = 1
 * Output: [[1]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 20
 * 1 <= k <= n
 *
 *
 */

// @lc code=start
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<int> comb;
        std::vector<std::vector<int>> result;
        dfs(1, n, k, comb, result);
        return result;
    }

private:
    void dfs(int idx, int n, int k, std::vector<int> comb,
             std::vector<std::vector<int>>& result) {
        if (comb.size() == k) {
            result.push_back(comb);
            return;
        }
        for (int i = idx; i <= n; ++i) {
            comb.push_back(i);
            dfs(i + 1, n, k, comb, result);
            comb.pop_back();
        }
    }
};
// @lc code=end
