/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (31.08%)
 * Likes:    2380
 * Dislikes: 789
 * Total Accepted:    290.8K
 * Total Submissions: 927.5K
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
                if(nums.size() <= 1) return;
        int i;
        
        // O(n)
        for(i = nums.size() - 2; i >= 0; i--){
            if(nums[i] < nums[i+1]) break;
        }
        
        if(i == -1){
            // the largest permutation
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int idx1 = i;
        // O(n)
        for(i = nums.size()  - 1; i > idx1; i--){
            if(nums[i] > nums[idx1]){
                swap(nums[idx1], nums[i]);
                break;
            }
        }
        
        // O(n)
        reverse(nums.begin() + idx1 + 1, nums.end());
    }
};
// @lc code=end

