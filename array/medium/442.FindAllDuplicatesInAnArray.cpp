/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 *
 * https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
 *
 * algorithms
 * Medium (65.97%)
 * Likes:    2409
 * Dislikes: 152
 * Total Accepted:    186.6K
 * Total Submissions: 278.7K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements
 * appear twice and others appear once.
 * 
 * Find all the elements that appear twice in this array.
 * 
 * Could you do it without extra space and in O(n) runtime?
 * 
 * Example:
 * 
 * Input:
 * [4,3,2,7,8,2,3,1]
 * 
 * Output:
 * [2,3]
 * 
 */

// @lc code=start
#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) {

// method 1
//         vector<int> duplicates;
//         int index = 0;
//         while (index < nums.size()) {
            
//             while (nums[index] != index + 1 && nums[index] != 0) {
//                 int correct_index = nums[index] - 1;
//                 if (nums[correct_index] == correct_index + 1) {
//                     duplicates.push_back(nums[correct_index]);
//                     nums[index] = 0;
//                     break;
//                 }
//                 swap(nums[index], nums[correct_index]);
//             }
//             index++;
//         }
        
//         return duplicates;
        
        // method 2
        std::vector<int> duplicates;
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]);
            if (nums[index - 1] > 0) {
                nums[index - 1] = -nums[index - 1];
            } else {
                duplicates.push_back(index);
            }
        }
        
        return duplicates;
    }
};
// @lc code=end

