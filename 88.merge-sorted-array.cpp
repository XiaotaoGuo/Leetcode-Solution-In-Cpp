/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (36.90%)
 * Likes:    1335
 * Dislikes: 3130
 * Total Accepted:    427.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * Note:
 * 
 * 
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * Output: [1,2,2,3,5,6]
 * 
 * 
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // trick: use the space in the back of nums1
        int ptr1 = m - 1, ptr2 = n - 1, curr = m + n - 1;
        while(ptr2 >= 0)
            nums1[curr--] = (ptr1 >= 0 && nums1[ptr1] > nums2[ptr2]) ? nums1[ptr1--] : nums2[ptr2--];
    }
};
// @lc code=end

