/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (41.18%)
 * Likes:    1628
 * Dislikes: 207
 * Total Accepted:    480.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,5,6], 5
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,3,5,6], 2
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,3,5,6], 7
 * Output: 4
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [1,3,5,6], 0
 * Output: 0
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
                if(nums.empty()) return 0;
        
        int l = 0, r = nums.size() - 1;
        
        if(nums[l] > target) return 0;
        if(nums[r] < target) return nums.size();
        
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                if(nums[mid + 1] > target){
                    return mid + 1;
                }
                else{
                    l = mid + 1;
                }
            }
            else{
                if(nums[mid - 1] < target){
                    return mid;
                }
                else{
                    r = mid - 1;
                }
            }
        }
        
        return 0;
    }
};
// @lc code=end

