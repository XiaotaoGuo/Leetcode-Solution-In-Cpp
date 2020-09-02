/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (27.91%)
 * Likes:    1667
 * Dislikes: 104
 * Total Accepted:    136.9K
 * Total Submissions: 488.1K
 * Testcase Example:  '2\n[2,4,1]'
 *
 * Say you have an array for which the i-th element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most k
 * transactions.
 * 
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 * 
 * Example 1:
 * 
 * 
 * Input: [2,4,1], k = 2
 * Output: 2
 * Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit
 * = 4-2 = 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,6,5,0,3], k = 2
 * Output: 7
 * Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit
 * = 6-2 = 4.
 * Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 =
 * 3.
 * 
 * 
 */

// @lc code=start
#include <vector>
#include<bits/stdc++.h> 

class Solution {
public:
    int maxProfit(int k, std::vector<int>& prices) {
        if (k == 0 || prices.size() <= 1) return 0;
        if (k > prices.size()) k = prices.size() / 2;
        std::vector<int> kth_buy(k, INT_MIN);
        std::vector<int> kth_sell(k, 0);
        
        for (int currentPrice: prices) {
            for (int i = k - 1; i > 0; i--) {
                kth_sell[i] = std::max(kth_sell[i], currentPrice + kth_buy[i]);
                kth_buy[i] = std::max(kth_buy[i], kth_sell[i - 1] - currentPrice);
            }
            kth_sell[0] = std::max(kth_sell[0], currentPrice + kth_buy[0]);
            kth_buy[0] = std::max(kth_buy[0], -currentPrice);
        }
        
        return kth_sell.back() < 0? 0 : kth_sell.back();
    }
};
// @lc code=end

