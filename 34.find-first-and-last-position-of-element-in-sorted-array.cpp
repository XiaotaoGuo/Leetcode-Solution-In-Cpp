/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (34.24%)
 * Likes:    2204
 * Dislikes: 103
 * Total Accepted:    378.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
                if(nums.empty() || nums.front() > target || nums.back() < target) return vector<int>{-1, -1};
        int leftmost = 0, rightmost = nums.size() - 1;
        int l = 0, r = nums.size() - 1;
        int mid;
        while(l <= r){
            mid = (l + r) / 2;
            if(nums[mid] == target) break;
            else if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        
        if(nums[mid] != target) return vector<int>{-1, -1};
        
        // looking for left boundary
        l = 0, r = mid -1;
        while(l <= r){
            int mid_l = (l + r) / 2;
            if(nums[mid_l] < target){
                if(nums[mid_l + 1] == target){
                    leftmost = mid_l + 1;
                    break;
                }
                else{
                    l = mid_l + 1;
                }
                
            }
            else if(nums[mid_l] == target){
                r = mid_l - 1;
            }
        }
        if(nums[leftmost] != target) leftmost = mid;
        // looking for right boundary
        l = mid + 1;
        r = nums.size() - 1;
        while(l <= r){
            int mid_r = (l + r) / 2;
            if(nums[mid_r] > target){
                if(nums[mid_r - 1] == target){
                    rightmost = mid_r - 1;
                    break;
                }
                else{
                    r = mid_r - 1;
                }
                
            }
            else if(nums[mid_r] == target){
                l = mid_r + 1;
            }
        }
        if(nums[rightmost] != target) rightmost = mid;
        
        return vector<int>{leftmost, rightmost};
    }
};
// @lc code=end

