/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (62.36%)
 * Likes:    4895
 * Dislikes: 267
 * Total Accepted:    584.1K
 * Total Submissions: 931.7K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given an integer array nums and an integer k, return the k most frequent
 * elements. You may return the answer in any order.
 *
 *
 * Example 1:
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * Example 2:
 * Input: nums = [1], k = 1
 * Output: [1]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * k is in the range [1, the number of unique elements in the array].
 * It is guaranteed that the answer is unique.
 *
 *
 *
 * Follow up: Your algorithm's time complexity must be better than O(n log n),
 * where n is the array's size.
 *
 */

// @lc code=start
#include <queue>
#include <unordered_map>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> hmap;
        for (int num : nums) {
            if (hmap.find(num) == hmap.end()) {
                hmap[num] = 1;
            } else {
                hmap[num]++;
            }
        }

        using key_freq = std::pair<int, int>;
        auto comp = [](const key_freq& lhs, const key_freq& rhs) {
            return lhs.second >= rhs.second;
        };
        std::priority_queue<key_freq, std::vector<key_freq>, decltype(comp)> pq(
            comp);

        for (auto it : hmap) {
            pq.push({it.first, it.second});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        std::vector<int> ret;
        while (!pq.empty()) {
            ret.push_back(pq.top().first);
            pq.pop();
        }

        return ret;
    }
};
// @lc code=end
