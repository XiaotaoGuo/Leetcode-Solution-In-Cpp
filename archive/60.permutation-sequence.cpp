/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (34.14%)
 * Likes:    1068
 * Dislikes: 275
 * Total Accepted:    156.4K
 * Total Submissions: 452.1K
 * Testcase Example:  '3\n3'
 *
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order, we get the
 * following sequence for n = 3:
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * Given n and k, return the k^th permutation sequence.
 * 
 * Note:
 * 
 * 
 * Given n will be between 1 and 9 inclusive.
 * Given k will be between 1 and n! inclusive.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, k = 3
 * Output: "213"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 4, k = 9
 * Output: "2314"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        if(n == 0) return "";
        string result = "";
        vector<int> numSubgroup(n, 1);
        numSubgroup[0] = 1;
        for(int i = 1; i < n; i++){
           numSubgroup[i] = numSubgroup[i - 1] * i; 
        }
        string nums = "123456789";
        
        k--;
        for(int i = n - 1; i >= 0; i--){
            int idx = k / numSubgroup[i];
            k %= numSubgroup[i];
            result += nums[idx];
            nums.erase(idx, 1);
            
        }
        
        return result;
    }
};
// @lc code=end

