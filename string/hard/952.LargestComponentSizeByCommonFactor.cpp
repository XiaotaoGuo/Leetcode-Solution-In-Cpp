/*
 * @lc app=leetcode id=952 lang=cpp
 *
 * [952] Largest Component Size by Common Factor
 *
 * https://leetcode.com/problems/largest-component-size-by-common-factor/description/
 *
 * algorithms
 * Hard (30.15%)
 * Likes:    343
 * Dislikes: 52
 * Total Accepted:    15.5K
 * Total Submissions: 46.8K
 * Testcase Example:  '[4,6,15,35]'
 *
 * Given a non-empty array of unique positive integers A, consider the
 * following graph:
 * 
 * 
 * There are A.length nodes, labelled A[0] to A[A.length - 1];
 * There is an edge between A[i] and A[j] if and only if A[i] and A[j] share a
 * common factor greater than 1.
 * 
 * 
 * Return the size of the largest connected component in the graph.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [4,6,15,35]
 * Output: 4
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [20,50,9,63]
 * Output: 2
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [2,3,6,7,4,12,21,39]
 * Output: 8
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 20000
 * 1 <= A[i] <= 100000
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

class DisjointSet {
public:
    DisjointSet(int n) : m_parents(n) {
        for (int i = 0; i < n; i++) {
            m_parents[i] = i;
        }
    }
    
    void Union(int x, int y) {
        m_parents[Find(x)] = m_parents[Find(y)];
    }
    
    int Find(int x) {
        // reset all nodes with same parents
        if (m_parents[x] != x)  {
            m_parents[x] = Find(m_parents[x]);
        }
        return m_parents[x];
    }
private:
    std::vector<int> m_parents;
};

class Solution {
public:
    int largestComponentSize(std::vector<int>& A) {
        int n = *std::max_element(A.begin(), A.end());
        DisjointSet ds(n + 1);
        for (int a: A) {
            for (int factor = 2; factor <= std::sqrt(a); factor++) {
                if (a % factor == 0) {
                    ds.Union(a, factor);
                    ds.Union(a, a / factor);
                }
            }
        }
        
        std::unordered_map<int, int> count; // component size for all parents
        int max_size = 1;
        for (int a : A) {
            max_size = std::max(max_size, ++count[ds.Find(a)]);
        }
        return max_size;
    }
};
// @lc code=end

