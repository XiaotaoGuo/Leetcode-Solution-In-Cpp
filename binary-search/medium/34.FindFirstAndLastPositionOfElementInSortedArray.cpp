/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (37.25%)
 * Likes:    5148
 * Dislikes: 196
 * Total Accepted:    665.9K
 * Total Submissions: 1.8M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 *
 * If target is not found in the array, return [-1, -1].
 *
 * Follow up: Could you write an algorithm with O(log n) runtime complexity?
 *
 *
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * Example 2:
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * Example 3:
 * Input: nums = [], target = 0
 * Output: [-1,-1]
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums is a non-decreasing array.
 * -10^9 <= target <= 10^9
 *
 *
 */

// @lc code=start
#include <vector>
class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }

        int first = -1;
        int last = -1;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                // find first element
                int first_right = mid;
                int first_left = left;
                while (first_left < first_right) {
                    int first_mid = (first_left + first_right) / 2;
                    if (nums[first_mid] >= target) {
                        first_right = first_mid;
                    } else {
                        first_left = first_mid + 1;
                    }
                }

                // find last element
                int last_right = right;
                int last_left = mid;
                while (last_left < last_right) {
                    int last_mid = (last_left + last_right) / 2;
                    if (nums[last_mid + 1] <= target) {
                        last_left = last_mid + 1;
                    } else {
                        last_right = last_mid;
                    }
                }

                first = first_left;
                last = last_right;
                break;

            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // if last iteration end because of left == right, need to confirm the
        // only element is target
        if (left == right && nums[left] == target) {
            first = left;
            last = left;
        }

        return {first, last};
    }
};
// @lc code=end
