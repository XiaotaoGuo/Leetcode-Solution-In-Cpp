/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (36.02%)
 * Likes:    5634
 * Dislikes: 168
 * Total Accepted:    529.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 *
 * You may assume that you have an infinite number of each kind of coin.
 *
 *
 * Example 1:
 *
 *
 * Input: coins = [1,2,5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 *
 *
 * Example 2:
 *
 *
 * Input: coins = [2], amount = 3
 * Output: -1
 *
 *
 * Example 3:
 *
 *
 * Input: coins = [1], amount = 0
 * Output: 0
 *
 *
 * Example 4:
 *
 *
 * Input: coins = [1], amount = 1
 * Output: 1
 *
 *
 * Example 5:
 *
 *
 * Input: coins = [1], amount = 2
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= coins.length <= 12
 * 1 <= coins[i] <= 2^31 - 1
 * 0 <= amount <= 10^4
 *
 *
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> minCount(amount + 1, amount + 1);
        minCount[0] = 0;

        for (int i = 0; i < coins.size(); ++i) {
            // iterate all possible coin
            int coin = coins[i];
            // iterate all amount that larger than coin
            for (int j = coin; j <= amount; j++) {
                minCount[j] = std::min(minCount[j], minCount[j - coin] + 1);
            }
        }

        return minCount.back() == amount + 1 ? -1 : minCount.back();
    }
};
// @lc code=end
