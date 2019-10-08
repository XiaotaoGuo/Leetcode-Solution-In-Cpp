/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (56.64%)
 * Likes:    2858
 * Dislikes: 244
 * Total Accepted:    316.5K
 * Total Submissions: 556.5K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an array nums of n integers where n > 1,  return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 * 
 * Example:
 * 
 * 
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 * 
 * 
 * Note: Please solve it without division and in O(n).
 * 
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does
 * not count as extra space for the purpose of space complexity analysis.)
 * 
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int n = nums.size();
        vector<int> l(n, 1);
        vector<int> r(n, 1);
        
        for(int i = 1; i < n; i++){
            l[i] = l[i - 1] * nums[i - 1];
        }
        
        for(int i = n - 2; i >= 0; i--){
            r[i] = r[i + 1] * nums[i + 1];
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++) ans.push_back(l[i]*r[i]);
        return ans; 
    }
};
// @lc code=end

