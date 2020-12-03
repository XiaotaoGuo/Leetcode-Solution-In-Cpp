/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (47.02%)
 * Likes:    2545
 * Dislikes: 71
 * Total Accepted:    410.6K
 * Total Submissions: 845.9K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers, nums, that might contain duplicates, return
 * all possible unique permutations in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,2]
 * Output:
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 8
 * -10 <= nums[i] <= 10
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<int> perm;
        std::vector<std::vector<int>> result;
        std::unordered_map<int, int> visited;

        for (auto&& num: nums) {
            visited[num]++;
        }

        std::sort(nums.begin(), nums.end());
        iterate(nums, perm, result, visited);
        return result;
    }

private:
    void iterate(const std::vector<int>& nums, std::vector<int>& perm, std::vector<std::vector<int>>& result, std::unordered_map<int, int>& visisted) {
        if (perm.size() == nums.size()) {
            result.push_back(perm);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            if (visisted[nums[i]] > 0) {
                perm.push_back(nums[i]);
                visisted[nums[i]]--;
                iterate(nums, perm, result, visisted);
                perm.pop_back();
                visisted[nums[i]]++;
            }
        }
    }
};
// @lc code=end

