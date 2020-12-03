/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (64.33%)
 * Likes:    4910
 * Dislikes: 119
 * Total Accepted:    707K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an array nums of distinct integers, return all the possible
 * permutations. You can return the answer in any order.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * Example 2:
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 * Example 3:
 * Input: nums = [1]
 * Output: [[1]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * All the integers of nums are unique.
 * 
 * 
 */

// @lc code=start
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<int> perm;
        std::vector<std::vector<int>> result;
        std::vector<bool> visisted(nums.size(), false);
        iterate(nums, perm, result, visisted);
        return result;
    }

private:
    void iterate(const std::vector<int>& nums, std::vector<int>& perm, std::vector<std::vector<int>>& result, std::vector<bool>& visisted) {
        if (perm.size() == nums.size()) {
            result.push_back(perm);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!visisted[i]) {
                perm.push_back(nums[i]);
                visisted[i] = true;
                iterate(nums, perm, result, visisted);
                perm.pop_back();
                visisted[i] = false;
            }
        }
    }
};
// @lc code=end

