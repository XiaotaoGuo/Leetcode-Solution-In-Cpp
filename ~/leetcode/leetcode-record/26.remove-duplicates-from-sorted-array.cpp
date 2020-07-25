/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int slow = 0, fast = 0;
        for (fast = 1; fast < nums.size(); fast++) {
            if (nums[fast] != nums[fast - 1]) {
                nums[++slow] = nums[fast];
            }
        }
        
        return slow + 1;
    }
};
// @lc code=end

