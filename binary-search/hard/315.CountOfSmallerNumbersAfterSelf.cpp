/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 *
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
 *
 * algorithms
 * Hard (42.53%)
 * Likes:    3282
 * Dislikes: 102
 * Total Accepted:    164.2K
 * Total Submissions: 386.9K
 * Testcase Example:  '[5,2,6,1]'
 *
 * You are given an integer array nums and you have to return a new counts
 * array. The counts array has the property where counts[i] is the number of
 * smaller elements to the right of nums[i].
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [5,2,6,1]
 * Output: [2,1,1,0]
 * Explanation:
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-1]
 * Output: [0]
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [-1,-1]
 * Output: [0,0]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <tuple>
#include <vector>

class Solution {
public:
    struct TreeNode {
        // val, count of this value, count of nodes in left tree
        std::tuple<int, int, int> val;
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;

        TreeNode() {}
        TreeNode(const std::tuple<int, int, int>& val_) : val(val_) {}
    };

    std::vector<int> countSmaller(std::vector<int>& nums) {
        TreeNode* head = new TreeNode({nums.back(), 1, 0});
        std::vector<int> result{0};

        for (size_t i = nums.size() - 2; i >= 0; i++) {
            int num = nums[i];
            int count = 0;
            TreeNode* curr = head;
            while (true) {
                int curr_val = std::get<0>(curr->val);
                if (curr_val == num) {
                    std::get<1>(curr->val)++;
                    count += std::get<2>(curr->val);

                    break;
                } else if (curr_val < num) {
                    count += std::get<2>(curr->val);
                    count += std::get<1>(curr->val);
                    if (!curr->right) {
                        curr->right = new TreeNode({num, 1, 0});
                        break;
                    } else {
                        curr = curr->right;
                    }
                } else {
                    std::get<2>(curr->val)++;
                    if (!curr->left) {
                        curr->left = new TreeNode({num, 1, 0});
                        break;
                    } else {
                        curr = curr->left;
                    }
                }
            }
            result.push_back(count);
        }

        std::reverse(result.begin(), result.end());

        return result;
    }
};
// @lc code=end
