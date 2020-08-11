/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() <= 1 || k % nums.size() == 0) {
            return;
        }
        
        k %= nums.size();
        
        
        
        int count = 0, index = 0;
        while (count < nums.size()) {
            int prev_index = index;
            int correct_index = (prev_index + k) % nums.size();
            while (correct_index != index) {
                count++;
                swap(nums[correct_index], nums[index]);
                prev_index = correct_index;
                correct_index = (prev_index + k) % nums.size();
            }
            count++;
            index++;
        }
        
    }

public:
//     void rotate(vector<int>& nums, int k) {
//         if (nums.size() <= 1) {
//             return;
//         }
        
//         k %= nums.size();
        
//         reverse(nums, 0, nums.size() - 1);
//         reverse(nums, 0, k - 1);
//         reverse(nums, k, nums.size() - 1);
//     }

// private:
//     void reverse(vector<int>& nums, int front, int back) {
//         while (front < back) {
//             swap(nums[front++], nums[back--]);
//         }
//     }
};
// @lc code=end

