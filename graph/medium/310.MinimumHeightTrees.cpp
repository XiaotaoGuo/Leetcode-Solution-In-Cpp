/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 *
 * https://leetcode.com/problems/minimum-height-trees/description/
 *
 * algorithms
 * Medium (35.13%)
 * Likes:    3284
 * Dislikes: 139
 * Total Accepted:    139.4K
 * Total Submissions: 396.1K
 * Testcase Example:  '4\n[[1,0],[1,2],[1,3]]'
 *
 * A tree is an undirected graph in which any two vertices are connected by
 * exactly one path. In other words, any connected graph without simple cycles
 * is a tree.
 *
 * Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1
 * edges where edges[i] = [ai, bi] indicates that there is an undirected edge
 * between the two nodes ai and bi in the tree, you can choose any node of the
 * tree as the root. When you select a node x as the root, the result tree has
 * height h. Among all possible rooted trees, those with minimum height (i.e.
 * min(h))  are called minimum height trees (MHTs).
 *
 * Return a list of all MHTs' root labels. You can return the answer in any
 * order.
 *
 * The height of a rooted tree is the number of edges on the longest downward
 * path between the root and a leaf.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4, edges = [[1,0],[1,2],[1,3]]
 * Output: [1]
 * Explanation: As shown, the height of the tree is 1 when the root is the node
 * with label 1 which is the only MHT.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
 * Output: [3,4]
 *
 *
 * Example 3:
 *
 *
 * Input: n = 1, edges = []
 * Output: [0]
 *
 *
 * Example 4:
 *
 *
 * Input: n = 2, edges = [[0,1]]
 * Output: [0,1]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 2 * 10^4
 * edges.length == n - 1
 * 0 <= ai, bi < n
 * ai != bi
 * All the pairs (ai, bi) are distinct.
 * The given input is guaranteed to be a tree and there will be no repeated
 * edges.
 *
 *
 */

// @lc code=start
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    std::vector<int> findMinHeightTrees(int n,
                                        std::vector<std::vector<int>>& edges) {
        std::vector<int> roots;

        std::vector<std::unordered_set<int>> graph(n);

        for (auto edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        std::queue<int> leaves;
        std::unordered_set<int> visited;

        for (int i = 0; i < n; ++i) {
            if (graph[i].size() == 1) {
                leaves.push(i);
            } else if (graph[i].empty()) {
                return {i};
            }
        }

        while (!leaves.empty()) {
            std::queue<int> next_leaves;

            while (!leaves.empty()) {
                int node = leaves.front();
                leaves.pop();
                roots.push_back(node);
                for (int nei : graph[node]) {
                    // remove this edge
                    graph[nei].erase(node);
                    // if it becomes a new node, add it to the queue
                    if (graph[nei].size() == 1) {
                        next_leaves.push(nei);
                    }
                }
                graph[node].clear();
            }

            if (!next_leaves.empty()) {
                roots.clear();
                std::swap(next_leaves, leaves);
            }
        }
        return roots;
    }
};

/// method 2: use bfs to calculate height with every node as root
// class Solution {
// public:
//     std::vector<int> findMinHeightTrees(int n,
//                                         std::vector<std::vector<int>>& edges)
//                                         {
//         int min_height = INT_MAX;
//         graph g;
//         for (auto edge : edges) {
//             g[edge[0]].push_back(edge[1]);
//             g[edge[1]].push_back(edge[0]);
//         }
//         std::vector<int> roots;
//         for (auto node : g) {
//             int height = bfs(node.first, g);
//             if (height <= min_height) {
//                 if (height < min_height) {
//                     min_height = height;
//                     roots.clear();
//                 }
//                 roots.push_back(node.first);
//             }
//         }

//         return roots;
//     }

// private:
//     using graph = std::unordered_map<int, std::vector<int>>;

//     int bfs(int root, const graph& g) {
//         if (g.find(root) == g.end()) {
//             return 0;
//         }

//         int height = 0;
//         std::queue<int> level;
//         level.push(root);
//         std::unordered_set<int> visited;
//         visited.insert(root);

//         while (!level.empty()) {
//             std::queue<int> next_level;
//             height++;
//             while (!level.empty()) {
//                 int node = level.front();
//                 for (auto nei : g[node]) {
//                     if (visited.count(nei) == 0) {
//                         visited.insert(nei);
//                         next_level.push(nei);
//                     }
//                 }
//             }

//             std::swap(level, next_level);
//         }

//         return height;
//     }
// };
// @lc code=end
