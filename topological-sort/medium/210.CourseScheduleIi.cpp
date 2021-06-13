/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 *
 * https://leetcode.com/problems/course-schedule-ii/description/
 *
 * algorithms
 * Medium (43.40%)
 * Likes:    3932
 * Dislikes: 172
 * Total Accepted:    412.6K
 * Total Submissions: 947.9K
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
 * Return the ordering of courses you should take to finish all courses. If
 * there are many valid answers, return any of them. If it is impossible to
 * finish all courses, return an empty array.
 *
 *
 * Example 1:
 *
 *
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: [0,1]
 * Explanation: There are a total of 2 courses to take. To take course 1 you
 * should have finished course 0. So the correct course order is [0,1].
 *
 *
 * Example 2:
 *
 *
 * Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
 * Output: [0,2,1,3]
 * Explanation: There are a total of 4 courses to take. To take course 3 you
 * should have finished both courses 1 and 2. Both courses 1 and 2 should be
 * taken after you finished course 0.
 * So one correct course order is [0,1,2,3]. Another correct ordering is
 * [0,2,1,3].
 *
 *
 * Example 3:
 *
 *
 * Input: numCourses = 1, prerequisites = []
 * Output: [0]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= numCourses * (numCourses - 1)
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * ai != bi
 * All the pairs [ai, bi] are distinct.
 *
 *
 */

// @lc code=start
#include <stack>
#include <vector>

class Solution {
public:
    std::vector<int> findOrder(int numCourses,
                               std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> hmap(numCourses);
        std::vector<int> status(numCourses, 0);
        for (auto preq : prerequisites) {
            hmap[preq[1]].push_back(preq[0]);
        }

        // std::vector<int> total_orders;
        std::stack<int> order;
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(hmap, status, i, order)) {
                return {};
            }
        }

        std::vector<int> ans;

        while (order.size()) {
            ans.push_back(order.top());
            order.pop();
        }

        return ans;
    }

private:
    bool dfs(const std::vector<std::vector<int>>& hmap,
             std::vector<int>& status, int current_course,
             std::stack<int>& order) {
        if (status[current_course] == 1)
            return true;
        else if (status[current_course] == -1)
            return false;
        else {
            status[current_course] = -1;
            for (int preq : hmap[current_course]) {
                if (!dfs(hmap, status, preq, order)) {
                    return false;
                }
            }
            status[current_course] = 1;
            order.push(current_course);
        }

        return true;
    }
};
// @lc code=end
