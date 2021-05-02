/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (37.05%)
 * Likes:    5704
 * Dislikes: 112
 * Total Accepted:    356.8K
 * Total Submissions: 950.3K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given an array of integers heights representing the histogram's bar height
 * where the width of each bar is 1, return the area of the largest rectangle
 * in the histogram.
 *
 *
 * Example 1:
 *
 *
 * Input: heights = [2,1,5,6,2,3]
 * Output: 10
 * Explanation: The above is a histogram where width of each bar is 1.
 * The largest rectangle is shown in the red area, which has an area = 10
 * units.
 *
 *
 * Example 2:
 *
 *
 * Input: heights = [2,4]
 * Output: 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= heights.length <= 10^5
 * 0 <= heights[i] <= 10^4
 *
 *
 */

// @lc code=start
#include <stack>
#include <vector>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        // place holder
        heights.push_back(0);
        std::stack<int> stk;
        int result = 0;
        int idx = 0;
        while (idx < heights.size()) {
            // #1 stack empty, push the height to the stack
            // #2 current height higher than the previous highest height
            if (stk.empty() || heights[idx] >= heights[stk.top()]) {
                stk.push(idx++);
            } else {
                // #3 meet a lower bar, the previous highest bar is unuseable,
                // hence remove it from stack, update the result (compare to use
                // current height to the top of stack), keep doing this step,
                // until meet another lower bar
                int h = heights[stk.top()];
                stk.pop();
                int w = stk.empty() ? idx : idx - stk.top() - 1;
                result = std::max(result, h * w);
            }
        }

        return result;
    }
};
// @lc code=end
