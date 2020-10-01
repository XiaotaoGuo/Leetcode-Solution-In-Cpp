/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 *
 * https://leetcode.com/problems/max-points-on-a-line/description/
 *
 * algorithms
 * Hard (17.04%)
 * Likes:    964
 * Dislikes: 2118
 * Total Accepted:    161.6K
 * Total Submissions: 948.4K
 * Testcase Example:  '[[1,1],[2,2],[3,3]]'
 *
 * Given n points on a 2D plane, find the maximum number of points that lie on
 * the same straight line.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,1],[2,2],[3,3]]
 * Output: 3
 * Explanation:
 * ^
 * |
 * |        o
 * |     o
 * |  o  
 * +------------->
 * 0  1  2  3  4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * Output: 4
 * Explanation:
 * ^
 * |
 * |  o
 * |     o        o
 * |        o
 * |  o        o
 * +------------------->
 * 0  1  2  3  4  5  6
 * 
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    int maxPoints(std::vector<std::vector<int>>& points) {
        
        if (points.size() < 3) return points.size();
        
        std::unordered_map<long double, std::unordered_map<long double, std::unordered_set<int>>> line_points;
        std::unordered_map<long double, std::unordered_set<int>> vertical_points;
        int curMax = 0;
        
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                long double x1 = points[i][0], y1 = points[i][1];
                long double x2 = points[j][0], y2 = points[j][1];
                
                if (x1 == x2) { // x1 == x2, its on vertical line
                    vertical_points[x1].insert(i);
                    vertical_points[x1].insert(j);
                    curMax = std::max((int)vertical_points[points[i][0]].size(), curMax);
                    continue;
                }
                
                long double slope = (y1 - y2) / (x1 - x2);
                long double offset = y1 - slope * x1;
                line_points[slope][offset].insert(i);
                line_points[slope][offset].insert(j);
                curMax = std::max((int)line_points[slope][offset].size(), curMax);
                
            }
        }
        
        return curMax;
    }
};
// @lc code=end

