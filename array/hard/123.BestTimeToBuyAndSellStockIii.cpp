/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
 *
 * algorithms
 * Hard (37.26%)
 * Likes:    2366
 * Dislikes: 78
 * Total Accepted:    225K
 * Total Submissions: 595.7K
 * Testcase Example:  '[3,3,5,0,0,3,1,4]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most two
 * transactions.
 * 
 * Note: You may not engage in multiple transactions at the same time (i.e.,
 * you must sell the stock before you buy again).
 * 
 * Example 1:
 * 
 * 
 * Input: [3,3,5,0,0,3,1,4]
 * Output: 6
 * Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit
 * = 3-0 = 3.
 * Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 =
 * 3.
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit
 * = 5-1 = 4.
 * Note that you cannot buy on day 1, buy on day 2 and sell them later, as you
 * are
 * engaging multiple transactions at the same time. You must sell before buying
 * again.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 * 
 */

// @lc code=start
#include <vector>
#include<bits/stdc++.h>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int firstBuy = INT_MIN; //profit after first buy in, should be negative
        int firstSell = 0; // profit after fisrt sell, should be positive
        int secondBuy = INT_MIN; //profit after second buy in, might be negative or positive
        int secondSell = 0; // profit after second sell, final answer 
        
        for (int currentPrice: prices) {
            secondSell = std::max(secondSell, currentPrice + secondBuy);
            secondBuy = std::max(secondBuy, firstSell - currentPrice);
            firstSell = std::max(firstSell, currentPrice + firstBuy);
            firstBuy = std::max(firstBuy, -currentPrice);
        }
        
        return secondSell < 0 ? 0 : secondSell;
        
    }
};
// @lc code=end

