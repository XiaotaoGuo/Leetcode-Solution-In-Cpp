/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 *
 * https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
 *
 * algorithms
 * Medium (37.65%)
 * Likes:    1941
 * Dislikes: 130
 * Total Accepted:    127.9K
 * Total Submissions: 335.1K
 * Testcase Example:  '[1,7,11]\n[2,4,6]\n3'
 *
 * You are given two integer arrays nums1 and nums2 sorted in ascending order
 * and an integer k.
 *
 * Define a pair (u, v) which consists of one element from the first array and
 * one element from the second array.
 *
 * Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest
 * sums.
 *
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
 * Output: [[1,2],[1,4],[1,6]]
 * Explanation: The first 3 pairs are returned from the sequence:
 * [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
 * Output: [[1,1],[1,1]]
 * Explanation: The first 2 pairs are returned from the sequence:
 * [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 *
 *
 * Example 3:
 *
 *
 * Input: nums1 = [1,2], nums2 = [3], k = 3
 * Output: [[1,3],[2,3]]
 * Explanation: All possible pairs are returned from the sequence:
 * [1,3],[2,3]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums1.length, nums2.length <= 10^4
 * -10^9 <= nums1[i], nums2[i] <= 10^9
 * nums1 and nums2 both are sorted in ascending order.
 * 1 <= k <= 1000
 *
 *
 */

// @lc code=start
#include <queue>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1,
                                                 std::vector<int>& nums2,
                                                 int k) {
        auto comp = [](const std::vector<int>& lhs,
                       const std::vector<int>& rhs) {
            return (lhs[0] + lhs[1]) < (rhs[0] + rhs[1]);
        };

        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>,
                            decltype(comp)>
            pq(comp);

        for (auto n1 : nums1) {
            for (auto n2 : nums2) {
                pq.push({n1, n2});
                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }

        std::vector<std::vector<int>> ret;
        while (!pq.empty()) {
            ret.push_back(pq.top());
            pq.pop();
        }

        return ret;
    }
};
// @lc code=end
