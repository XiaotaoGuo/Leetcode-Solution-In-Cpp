/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 *
 * https://leetcode.com/problems/find-peak-element/description/
 *
 * algorithms
 * Medium (43.94%)
 * Likes:    2637
 * Dislikes: 2575
 * Total Accepted:    468.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,1]'
 *
 * A peak element is an element that is strictly greater than its neighbors.
 *
 * Given an integer array nums, find a peak element, and return its index. If
 * the array contains multiple peaks, return the index to any of the peaks.
 *
 * You may imagine that nums[-1] = nums[n] = -∞.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,1]
 * Output: 2
 * Explanation: 3 is a peak element and your function should return the index
 * number 2.
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,1,3,5,6,4]
 * Output: 5
 * Explanation: Your function can return either index number 1 where the peak
 * element is 2, or index number 5 where the peak element is 6.
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 1000
 * -2^31 <= nums[i] <= 2^31 - 1
 * nums[i] != nums[i + 1] for all valid i.
 *
 *
 *
 * Follow up: Could you implement a solution with logarithmic complexity?
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) >> 2;

            if (nums[mid] > nums[mid + 1]) {
                // if nums[mid] > nums[mid + 1], there is at least 1 peak
                // between [0, mid], even if nums[0] > nums[1] > ... >
                // nums[mid], (and neiboring element can't be the same) in this
                // case, nums[0] is the peak since nums[-1] = -inf
                right = mid;
            } else {
                // same rule applies to cases when nums[mid] < nums[mid], in
                // this case there is at least 1 peak between [mid + 1, N-1]
                left = mid;
            }
        }
        return left;
    }
};
// @lc code=end
