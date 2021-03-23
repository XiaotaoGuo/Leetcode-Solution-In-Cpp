/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 *
 * https://leetcode.com/problems/russian-doll-envelopes/description/
 *
 * algorithms
 * Hard (36.23%)
 * Likes:    1660
 * Dislikes: 52
 * Total Accepted:    86.2K
 * Total Submissions: 236.2K
 * Testcase Example:  '[[5,4],[6,4],[6,7],[2,3]]'
 *
 * You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi]
 * represents the width and the height of an envelope.
 *
 * One envelope can fit into another if and only if both the width and height
 * of one envelope is greater than the width and height of the other envelope.
 *
 * Return the maximum number of envelopes can you Russian doll (i.e., put one
 * inside the other).
 *
 * Note: You cannot rotate an envelope.
 *
 *
 * Example 1:
 *
 *
 * Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
 * Output: 3
 * Explanation: The maximum number of envelopes you can Russian doll is 3
 * ([2,3] => [5,4] => [6,7]).
 *
 *
 * Example 2:
 *
 *
 * Input: envelopes = [[1,1],[1,1],[1,1]]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= envelopes.length <= 5000
 * envelopes[i].length == 2
 * 1 <= wi, hi <= 10^4
 *
 *
 */

// @lc code=start

#include <algorithm>
#include <vector>
class Solution {
public:
    int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
        std::sort(
            envelopes.begin(), envelopes.end(),
            [](const std::vector<int>& left, const std::vector<int>& right) {
                if (left[0] != right[0]) {
                    return left[0] < right[0];
                } else {
                    return left[1] > right[1];
                }
            });
        std::vector<int> minHeight{};
        for (const std::vector<int>& envelope : envelopes) {
            int index = binary_search(minHeight, envelope[1]);
            if (index == -1) {
                continue;
            } else if (index == minHeight.size()) {
                minHeight.push_back(envelope[1]);
            } else {
                minHeight[index] = envelope[1];
            }
        }

        return minHeight.size();
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

// #include <algorithm>
// #include <vector>
// class Solution {
// public:
//     int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
//         std::vector<int> maxNumsEnvelopes(envelopes.size(), 1);
//         std::sort(
//             envelopes.begin(), envelopes.end(),
//             [](const std::vector<int>& left, const std::vector<int>& right) {
//                 if (left[0] != right[0]) {
//                     return left[0] < right[0];
//                 } else {
//                     return left[1] > right[1];
//                 }
//             });
//         int result = 1;
//         for (int i = 1; i < envelopes.size(); i++) {
//             for (int j = 0; j < i; j++) {
//                 if (envelopes[i][0] > envelopes[j][0] &&
//                     envelopes[i][1] > envelopes[j][1]) {
//                     maxNumsEnvelopes[i] =
//                         std::max(maxNumsEnvelopes[i], maxNumsEnvelopes[j] +
//                         1);
//                     result = std::max(result, maxNumsEnvelopes[i]);
//                 }
//             }
//         }

//         return result;
//     }
// };

// @lc code=end
