/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Medium (32.76%)
 * Likes:    872
 * Dislikes: 371
 * Total Accepted:    198.9K
 * Total Submissions: 605.9K
 * Testcase Example:  '[2,5,6,0,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return true,
 * otherwise return false.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,5,6,0,0,1,2], target = 0
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,5,6,0,0,1,2], target = 3
 * Output: false
 * 
 * Follow up:
 * 
 * 
 * This is a follow up problem to Search in Rotated Sorted Array, where nums
 * may contain duplicates.
 * Would this affect the run-time complexity? How and why?
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        
        int left = 0, right = nums.size()-1;
        while(left!= right && nums[left] == nums[right]) left++;
        if(left == right) return nums[left]==target;
        while(left < right){
            int mid = (left + right)/2;
            if(nums[mid] == target){
                return true;
            }
            else if (nums[mid] < nums[left]){
                if(nums[mid] < target && target <= nums[right]){
                    left = mid+1;
                    while(left != right && nums[left] == nums[mid]) left++;
                }
                else{
                    right = mid - 1;
                    while(left != right && nums[right] == nums[mid]) right--;
                }
            }
            else{
                if(nums[mid] > target && target >= nums[left]){
                    right = mid - 1;
                    while(left != right && nums[right] == nums[mid]) right--;
                }
                else{
                    left = mid + 1;
                    while(left != right && nums[left] == nums[mid]) left++;
                }
            }
        }
        
        if(nums[left] == target) return true;
        return false;
    }
};
// @lc code=end

