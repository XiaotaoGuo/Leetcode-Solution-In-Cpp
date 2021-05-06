/*
 * @lc app=leetcode id=313 lang=cpp
 *
 * [313] Super Ugly Number
 *
 * https://leetcode.com/problems/super-ugly-number/description/
 *
 * algorithms
 * Medium (46.10%)
 * Likes:    852
 * Dislikes: 167
 * Total Accepted:    87.5K
 * Total Submissions: 188.2K
 * Testcase Example:  '12\n[2,7,13,19]'
 *
 * A super ugly number is a positive integer whose prime factors are in the
 * array primes.
 *
 * Given an integer n and an array of integers primes, return the n^th super
 * ugly number.
 *
 * The n^th super ugly number is guaranteed to fit in a 32-bit signed
 * integer.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 12, primes = [2,7,13,19]
 * Output: 32
 * Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first
 * 12 super ugly numbers given primes = [2,7,13,19].
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1, primes = [2,3,5]
 * Output: 1
 * Explanation: 1 has no prime factors, therefore all of its prime factors are
 * in the array primes = [2,3,5].
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 10^6
 * 1 <= primes.length <= 100
 * 2 <= primes[i] <= 1000
 * primes[i] is guaranteed to be a prime number.
 * All the values of primes are unique and sorted in ascending order.
 *
 *
 */

// @lc code=start
#include <limits.h>
#include <queue>
#include <unordered_set>
#include <vector>

class Solution {
public:
    int nthSuperUglyNumber(int n, std::vector<int>& primes) {
        if (n == 1) {
            return 1;  // the first super ugly number
        }

        int count = 0;
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        std::unordered_set<int> hset;

        pq.push(1);
        hset.insert(1);
        for (auto prime : primes) {
            pq.push(prime);
            hset.insert(prime);
        }

        int num = 1;
        while (count < n) {
            num = pq.top();
            pq.pop();
            for (auto prime : primes) {
                long new_ugly_num = num * prime;
                if (new_ugly_num <= INT_MAX && hset.count(new_ugly_num) == 0) {
                    hset.insert(new_ugly_num);
                    pq.push(new_ugly_num);
                }
            }
            count++;
        }

        return num;
    }
};
// @lc code=end
