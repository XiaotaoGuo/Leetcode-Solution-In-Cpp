/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        int index = 0;
        while (index < n) {
            while (nums[index] > 0 && nums[index] <= n && nums[index] != index + 1) {
                int correct_index = nums[index] - 1;
                if (nums[index] == nums[correct_index]) {
                    break;
                }
                swap(nums[index], nums[correct_index]);
            }
            index++;
        }

        int first_missing_positive = n + 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] != (i + 1)) {
                first_missing_positive = i + 1;
                break;
            }
        }

        return first_missing_positive;
    }
};
// @lc code=end

