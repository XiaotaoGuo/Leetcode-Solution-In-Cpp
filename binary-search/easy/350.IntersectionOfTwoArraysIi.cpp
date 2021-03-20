/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 *
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (51.96%)
 * Likes:    2096
 * Dislikes: 510
 * Total Accepted:    475.7K
 * Total Submissions: 915K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two integer arrays nums1 and nums2, return an array of their
 * intersection. Each element in the result must appear as many times as it
 * shows in both arrays and you may return the result in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2,2]
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [4,9]
 * Explanation: [9,4] is also accepted.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 1000
 *
 *
 *
 * Follow up:
 *
 *
 * What if the given array is already sorted? How would you optimize your
 * algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is
 * better?
 * What if elements of nums2 are stored on disk, and the memory is limited such
 * that you cannot load all elements into the memory at once?
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1,
                               std::vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        std::vector<int> result;

        int left = 0;
        int right = nums1.size() - 1;
        int count = 0;
        for (size_t i = 0; i < nums2.size(); ++i) {
            if (i > 0 && nums2[i] == nums2[i - 1]) {
                if (count > 0) {
                    result.push_back(nums2[i]);
                    count--;
                }
            } else {
                int target = nums2[i];
                count = binary_search(nums1, left, right, target);
                if (count > 0) {
                    result.push_back(nums2[i]);
                    count--;
                }
            }
        }

        return result;
    }

private:
    int binary_search(const std::vector<int>& nums, int& n_left, int n_right,
                      int target) {
        int left = n_left;
        int right = n_right;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                int count = 1;
                left = mid - 1;
                while (left >= n_left && nums[left] == target) {
                    left--;
                    count++;
                }
                n_left = mid + 1;
                while (n_left <= n_right && nums[n_left] == target) {
                    n_left++;
                    count++;
                }
                return count;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return 0;
    }
};
// @lc code=end
