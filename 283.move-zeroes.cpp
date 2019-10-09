/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (55.19%)
 * Likes:    2419
 * Dislikes: 88
 * Total Accepted:    538.3K
 * Total Submissions: 973.3K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Note:
 * 
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                nums[pos] = nums[i];
                pos++;
            }
        }
        
        while(pos < nums.size()){
            nums[pos++] = 0;
        }
    }
};
// @lc code=end

