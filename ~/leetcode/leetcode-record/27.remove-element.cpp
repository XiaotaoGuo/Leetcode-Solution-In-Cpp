/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int count = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[count] = nums[i];
                count++;
            }
        }
        
        return count;
    }
    
//     int removeElement(vector<int>& nums, int val) {
        
//         int front = 0, back = nums.size() - 1;
        
//         while (front <= back) {
//             // make sure back pointer not pointing to a value to remove
//             while (front < back && nums[back] == val) {
//                     back--;
//             }
            
//             if (nums[front] == val) {
//                 swap(nums[front], nums[back]);
//                 back--;
//             }
//             front++;
//         }
        
//         return back + 1;
//     }
};
// @lc code=end

