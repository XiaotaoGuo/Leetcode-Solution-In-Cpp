/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (44.40%)
 * Likes:    6061
 * Dislikes: 254
 * Total Accepted:    603.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of numCourses courses you have to take, labeled from 0 to
 * numCourses - 1. You are given an array prerequisites where prerequisites[i]
 * = [ai, bi] indicates that you must take course bi first if you want to take
 * course ai.
 *
 *
 * For example, the pair [0, 1], indicates that to take course 0 you have to
 * first take course 1.
 *
 *
 * Return true if you can finish all courses. Otherwise, return false.
 *
 *
 * Example 1:
 *
 *
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0. So it is possible.
 *
 *
 * Example 2:
 *
 *
 * Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should also have finished course 1. So it is impossible.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= numCourses <= 10^5
 * 0 <= prerequisites.length <= 5000
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * All the pairs prerequisites[i] are unique.
 *
 *
 */

// @lc code=start
#include <vector>

class Solution {
public:
    bool canFinish(int numCourses,
                   std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> hmap(numCourses);
        std::vector<int> status(numCourses, 0);
        for (auto preq : prerequisites) {
            hmap[preq[0]].push_back(preq[1]);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(hmap, status, i)) {
                return false;
            }
        }

        return true;
    }

private:
    bool dfs(const std::vector<std::vector<int>>& hmap,
             std::vector<int>& status, int current_course) {
        for (int preq : hmap[current_course]) {
            if (status[preq] == 1) {
                continue;
            } else if (status[preq] == -1) {
                return false;
            } else {
                status[preq] = -1;
                if (!dfs(hmap, status, preq)) {
                    return false;
                }
                status[preq] = 1;
            }
        }

        return true;
    }
};
// @lc code=end
