/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Hard (38.67%)
 * Likes:    1927
 * Dislikes: 346
 * Total Accepted:    214.5K
 * Total Submissions: 549.8K
 * Testcase Example:  '3\n3'
 *
 * The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
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
 * 
 * Example 1:
 * Input: n = 3, k = 3
 * Output: "213"
 * Example 2:
 * Input: n = 4, k = 9
 * Output: "2314"
 * Example 3:
 * Input: n = 3, k = 1
 * Output: "123"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 9
 * 1 <= k <= n!
 * 
 * 
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
public:
    std::string getPermutation(int n, int k) {
        std::vector<int> nums;
        std::vector<int> factorial(10, 1);
        for (int i = 1; i <= 9; i++) {
            nums.push_back(i);
            factorial[i] = factorial[i - 1] * i;
        }

        std::string perm = "";
        k--;
        while (n > 0) {
            int select = k / factorial[n - 1];
            k %= factorial[n - 1];

            perm += '0' + nums[select];
            for (int i = select; i < nums.size() - 1; ++i) {
                nums[i] = nums[i + 1];
            }

            n--;
        }

        return perm;
    }
};
// @lc code=end

