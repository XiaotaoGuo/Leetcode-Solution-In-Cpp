/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 *
 * https://leetcode.com/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (29.47%)
 * Likes:    439
 * Dislikes: 835
 * Total Accepted:    107.5K
 * Total Submissions: 364K
 * Testcase Example:  '[3,2,1]'
 *
 * Given a non-empty array of integers, return the third maximum number in this
 * array. If it does not exist, return the maximum number. The time complexity
 * must be in O(n).
 * 
 * Example 1:
 * 
 * Input: [3, 2, 1]
 * 
 * Output: 1
 * 
 * Explanation: The third maximum is 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1, 2]
 * 
 * Output: 2
 * 
 * Explanation: The third maximum does not exist, so the maximum (2) is
 * returned instead.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: [2, 2, 3, 1]
 * 
 * Output: 1
 * 
 * Explanation: Note that the third maximum here means the third maximum
 * distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 * 
 * 
 */

// @lc code=start
#include<vector>
using namespace std;
/**
 *  use three flag to track the status of three maximum
 */ 
class Solution {
public:
    int thirdMax(vector<int>& nums) {
                int first = INT_MIN;
        int second = INT_MIN;
        int third = INT_MIN;
        bool flag_1 = false;
        bool flag_2 = false;
        bool flag_3 = false;
        for(auto num: nums){
            if(num >= first){
                if(num == first){
                    flag_1 = true;
                    continue;
                }
                third = second;
                second = first;
                first = num;
                if(flag_2 && !flag_3) flag_3 = true;
                if(flag_1 && !flag_2) flag_2 = true;
                if(!flag_1) flag_1 = true;
            }
            else if(num >= second){
                if(num == second){
                    flag_2 = true;
                    continue;
                }
                third = second;
                second = num;
                if(flag_2 && !flag_3) flag_3 = true;
                if(!flag_2) flag_2 = true;
            }
            else if(num >= third){
                flag_3 = true;
                third = num;
            }
        }
        int ans = third;
        if(!flag_3){
            ans = first;
        }
        return ans;
    }
};
// @lc code=end

