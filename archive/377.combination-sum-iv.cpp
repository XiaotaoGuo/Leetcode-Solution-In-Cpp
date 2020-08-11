/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 *
 * https://leetcode.com/problems/combination-sum-iv/description/
 *
 * algorithms
 * Medium (43.92%)
 * Likes:    986
 * Dislikes: 119
 * Total Accepted:    98.9K
 * Total Submissions: 224.3K
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
#include<vector>
using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(nums.empty() || target < 0) return 0;
        vector<unsigned long> dp(target + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= target; i++){
            int currSol = 0;
            for(const int num: nums){
                if(i - num >= 0)
                    dp[i] += dp[i - num];    
            }
            
        }
        return dp.back();
    }
};
// @lc code=end

