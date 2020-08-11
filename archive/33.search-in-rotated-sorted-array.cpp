/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (33.19%)
 * Likes:    3234
 * Dislikes: 374
 * Total Accepted:    517K
 * Total Submissions: 1.5M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
                if(nums.empty()) return -1;
        int l = 0, r = nums.size() - 1;
        
        while(l <= r){
            // cout << "l: " << l << ", r: " << r << endl;
            int mid = (l + r) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] >= nums[l]){
                if(nums[mid] > target && target >= nums[l]){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            else{
                if(nums[mid] < target && target <= nums[r]){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
        }
        
        return -1;
    }
};
// @lc code=end

