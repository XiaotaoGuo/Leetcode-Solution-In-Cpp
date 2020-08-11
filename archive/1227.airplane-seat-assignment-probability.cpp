/*
 * @lc app=leetcode id=1227 lang=cpp
 *
 * [1227] Airplane Seat Assignment Probability
 */

// @lc code=start
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return n == 1 ? 1.0 : 0.5;
    }
};
// @lc code=end

