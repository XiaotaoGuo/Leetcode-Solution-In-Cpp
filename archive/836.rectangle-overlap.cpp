/*
 * @lc app=leetcode id=836 lang=cpp
 *
 * [836] Rectangle Overlap
 *
 * https://leetcode.com/problems/rectangle-overlap/description/
 *
 * algorithms
 * Easy (47.38%)
 * Likes:    444
 * Dislikes: 86
 * Total Accepted:    34.7K
 * Total Submissions: 72.7K
 * Testcase Example:  '[0,0,2,2]\n[1,1,3,3]'
 *
 * A rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) are
 * the coordinates of its bottom-left corner, and (x2, y2) are the coordinates
 * of its top-right corner.
 * 
 * Two rectangles overlap if the area of their intersection is positive.  To be
 * clear, two rectangles that only touch at the corner or edges do not
 * overlap.
 * 
 * Given two (axis-aligned) rectangles, return whether they overlap.
 * 
 * Example 1:
 * 
 * 
 * Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
 * Output: false
 * 
 * 
 * Notes:
 * 
 * 
 * Both rectangles rec1 and rec2 are lists of 4 integers.
 * All coordinates in rectangles will be between -10^9 and 10^9.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
                int min_x1 = rec1[0], min_y1 = rec1[1], max_x1 = rec1[2], max_y1 = rec1[3];
        int min_x2 = rec2[0], min_y2 = rec2[1], max_x2 = rec2[2], max_y2 = rec2[3];
        
        if(max_x1 <= min_x2) return false;
        if(max_y1 <= min_y2) return false;
        if(min_x1 >= max_x2) return false;
        if(min_y1 >= max_y2) return false;
        return true;
    }
};
// @lc code=end

