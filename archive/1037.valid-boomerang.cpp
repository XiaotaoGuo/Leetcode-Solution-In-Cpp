/*
 * @lc app=leetcode id=1037 lang=cpp
 *
 * [1037] Valid Boomerang
 *
 * https://leetcode.com/problems/valid-boomerang/description/
 *
 * algorithms
 * Easy (37.38%)
 * Likes:    53
 * Dislikes: 161
 * Total Accepted:    10.8K
 * Total Submissions: 28.9K
 * Testcase Example:  '[[1,1],[2,3],[3,2]]'
 *
 * A boomerang is a set of 3 points that are all distinct and not in a straight
 * line.
 * 
 * Given a list of three points in the plane, return whether these points are a
 * boomerang.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,1],[2,3],[3,2]]
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,1],[2,2],[3,3]]
 * Output: false
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * points.length == 3
 * points[i].length == 2
 * 0 <= points[i][j] <= 100
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        set<vector<int>> s(points.begin(), points.end());
        if(s.size() < 3) return false;
        double x1 = points[0][0], x2 = points[1][0], x3 = points[2][0]; 
        double y1 = points[0][1], y2 = points[1][1], y3 = points[2][1];
        if(x1 == x2) return x1 != x3;
        if(y1 == y2) return y1 != y3;
        return (y3 - y2)/(y1 - y2) != (x3 - x2) / (x1 - x2);
    }
};
// @lc code=end

