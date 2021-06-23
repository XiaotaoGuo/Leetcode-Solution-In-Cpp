/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 *
 * https://leetcode.com/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (55.05%)
 * Likes:    3595
 * Dislikes: 280
 * Total Accepted:    190.4K
 * Total Submissions: 345.4K
 * Testcase Example:  '[["a","b"],["b","c"]]\n' +
  '[2.0,3.0]\n' +
  '[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]'
 *
 * You are given an array of variable pairs equations and an array of real
 * numbers values, where equations[i] = [Ai, Bi] and values[i] represent the
 * equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a
 * single variable.
 *
 * You are also given some queries, where queries[j] = [Cj, Dj] represents the
 * j^th query where you must find the answer for Cj / Dj = ?.
 *
 * Return the answers to all queries. If a single answer cannot be determined,
 * return -1.0.
 *
 * Note: The input is always valid. You may assume that evaluating the queries
 * will not result in division by zero and that there is no contradiction.
 *
 *
 * Example 1:
 *
 *
 * Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries =
 * [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
 * Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
 * Explanation:
 * Given: a / b = 2.0, b / c = 3.0
 * queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
 * return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
 *
 *
 * Example 2:
 *
 *
 * Input: equations = [["a","b"],["b","c"],["bc","cd"]], values =
 * [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
 * Output: [3.75000,0.40000,5.00000,0.20000]
 *
 *
 * Example 3:
 *
 *
 * Input: equations = [["a","b"]], values = [0.5], queries =
 * [["a","b"],["b","a"],["a","c"],["x","y"]]
 * Output: [0.50000,2.00000,-1.00000,-1.00000]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= equations.length <= 20
 * equations[i].length == 2
 * 1 <= Ai.length, Bi.length <= 5
 * values.length == equations.length
 * 0.0 < values[i] <= 20.0
 * 1 <= queries.length <= 20
 * queries[i].length == 2
 * 1 <= Cj.length, Dj.length <= 5
 * Ai, Bi, Cj, Dj consist of lower case English letters and digits.
 *
 *
 */

// @lc code=start
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    std::vector<double> calcEquation(
        std::vector<std::vector<std::string>>& equations,
        std::vector<double>& values,
        std::vector<std::vector<std::string>>& queries) {
        for (int i = 0; i < equations.size(); ++i) {
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back(
                {equations[i][0], 1.0 / values[i]});
        }

        // cout << "graph" << endl;
        std::vector<double> results;
        for (auto query : queries) {
            double result = 1.0;
            std::unordered_set<std::string> visited;
            if (dfs(query[0], query[1], result, visited))
                results.push_back(result);
            else
                results.push_back(-1.0);
        }

        return results;
    }

private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, double>>>
        graph;

    bool dfs(const std::string& current, const std::string& target,
             double& result, std::unordered_set<std::string>& visited) {
        if (graph.find(current) == graph.end()) {
            return false;
        }
        if (current == target) {
            return true;
        }

        visited.insert(current);

        for (auto edge : graph[current]) {
            if (visited.count(edge.first)) continue;
            result *= edge.second;
            if (dfs(edge.first, target, result, visited)) {
                return true;
            }
            result /= edge.second;
        }

        return false;
    }
};
// @lc code=end
