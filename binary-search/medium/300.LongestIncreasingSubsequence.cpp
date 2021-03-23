/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (43.95%)
 * Likes:    6721
 * Dislikes: 153
 * Total Accepted:    514.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an integer array nums, return the length of the longest strictly
 * increasing subsequence.
 *
 * A subsequence is a sequence that can be derived from an array by deleting
 * some or no elements without changing the order of the remaining elements.
 * For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [10,9,2,5,3,7,101,18]
 * Output: 4
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,1,0,3,2,3]
 * Output: 4
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [7,7,7,7,7,7,7]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 2500
 * -10^4 <= nums[i] <= 10^4
 *
 *
 *
 * Follow up:
 *
 *
 * Could you come up with the O(n^2) solution?
 * Could you improve it to O(n log(n)) time complexity?
 *
 *
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> lastElementOFLISatLen;
        for (const int num : nums) {
            int index = binary_search(lastElementOFLISatLen, num);
            if (index == lastElementOFLISatLen.size()) {
                lastElementOFLISatLen.push_back(num);
            } else {
                lastElementOFLISatLen[index] = num;
            }
        }

        return lastElementOFLISatLen.size();
    }

private:
    int binary_search(const std::vector<int>& nums, int target) {
        if (nums.empty() || nums.back() < target) return nums.size();
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};
// @lc code=end
