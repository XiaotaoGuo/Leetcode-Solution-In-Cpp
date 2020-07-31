/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
        return 0;
    }

    int slow = 0, count = 1;
    for (int fast = 1; fast < nums.size(); fast++) {
        if (nums[fast] != nums[slow]) {
            nums[++slow] = nums[fast];
            count = 1;
        }
        else if (count < 2) {
            nums[++slow] = nums[fast];
            count++;
        }
    }

    return slow + 1;
    }
};
// @lc code=end

