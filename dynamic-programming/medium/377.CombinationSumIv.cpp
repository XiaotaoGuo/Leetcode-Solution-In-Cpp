/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 *
 * https://leetcode.com/problems/combination-sum-iv/description/
 *
 * algorithms
 * Medium (45.51%)
 * Likes:    1721
 * Dislikes: 208
 * Total Accepted:    140.2K
 * Total Submissions: 306.9K
 * Testcase Example:  '[1,2,3]\n4'
 *
 * Given an integer array with all positive numbers and no duplicates, find the
 * number of possible combinations that add up to a positive integer target.
 * 
 * Example:
 * 
 * 
 * nums = [1, 2, 3]
 * target = 4
 * 
 * The possible combination ways are:
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 * 
 * Note that different sequences are counted as different combinations.
 * 
 * Therefore the output is 7.
 * 
 * 
 * 
 * 
 * Follow up:
 * What if negative numbers are allowed in the given array?
 * How does it change the problem?
 * What limitation we need to add to the question to allow negative numbers?
 * 
 * Credits:
 * Special thanks to @pbrother for adding this problem and creating all test
 * cases.
 * 
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int combinationSum4(std::vector<int>& nums, int target) {

        // memo[idx] = n means there are n subsets of nums sum up to idx
        std::vector<unsigned long> memo(target + 1, 0);

        // only empty set sums up to 0
        memo[0] = 1;

        // iterate each target
        for (int i = 0; i <= target; i++) {
            // for each target iterate all num in nums and
            // use memo to find the result of current target
            for (const int& num: nums) {
                // if current target is greater than num
                // then memo[i] could use all subsets belong to the memo[i - m] and add num
                if (i >= num) {
                    memo[i] += memo[i - num];
                }
            }
        }

        return memo[target];
    }
};
// @lc code=end

