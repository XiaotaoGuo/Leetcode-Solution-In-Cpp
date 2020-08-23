/*
 * @lc app=leetcode id=497 lang=cpp
 *
 * [497] Random Point in Non-overlapping Rectangles
 *
 * https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/description/
 *
 * algorithms
 * Medium (37.71%)
 * Likes:    248
 * Dislikes: 398
 * Total Accepted:    21.2K
 * Total Submissions: 55.2K
 * Testcase Example:  '["Solution", "pick", "pick", "pick"]\n[[[[1, 1, 5, 5]]], [], [], []]'
 *
 * Given a list of non-overlapping axis-aligned rectangles rects, write a
 * function pick which randomly and uniformily picks an integer point in the
 * space covered by the rectangles.
 * 
 * Note:
 * 
 * 
 * An integer point is a point that has integer coordinates. 
 * A point on the perimeter of a rectangle is included in the space covered by
 * the rectangles. 
 * ith rectangle = rects[i] = [x1,y1,x2,y2], where [x1, y1] are the integer
 * coordinates of the bottom-left corner, and [x2, y2] are the integer
 * coordinates of the top-right corner.
 * length and width of each rectangle does not exceed 2000.
 * 1 <= rects.length <= 100
 * pick return a point as an array of integer coordinates [p_x, p_y]
 * pick is called at most 10000 times.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * ["Solution","pick","pick","pick"]
 * [[[[1,1,5,5]]],[],[],[]]
 * Output: 
 * [null,[4,1],[4,1],[3,3]]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * ["Solution","pick","pick","pick","pick","pick"]
 * [[[[-2,-2,-1,-1],[1,0,3,0]]],[],[],[],[],[]]
 * Output: 
 * [null,[-1,-2],[2,0],[-2,-1],[3,0],[-2,-2]]
 * 
 * 
 * 
 * Explanation of Input Syntax:
 * 
 * The input is two lists: the subroutines called and their arguments.
 * Solution's constructor has one argument, the array of rectangles rects. pick
 * has no arguments. Arguments are always wrapped with a list, even if there
 * aren't any.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <cstdlib>
#include <algorithm>

class Solution {
public:
    Solution(std::vector<std::vector<int>>& rects) {
        m_rects = rects;
        m_sum_areas = std::vector<int>(m_rects.size());
        for (int i = 0; i < m_rects.size(); i++) {
            // this area represents available points in that rectangle
            m_sum_areas[i] = (m_rects[i][2] - m_rects[i][0] + 1) * (m_rects[i][3] - m_rects[i][1] + 1);
            if (i > 0) {
                m_sum_areas[i] += m_sum_areas[i - 1];
            }
        }
    }
    
    std::vector<int> pick() {
        int index = std::lower_bound(m_sum_areas.begin(), m_sum_areas.end(), randInt(m_sum_areas.back()) + 1) -\
                    m_sum_areas.begin();
        const std::vector<int>& chosen_rect = m_rects[index];
        return { chosen_rect[0] + randInt(chosen_rect[2] - chosen_rect[0] + 1),\
                 chosen_rect[1] + randInt(chosen_rect[3] - chosen_rect[1] + 1)};
    }

private:
    std::vector<std::vector<int>> m_rects;
    std::vector<int> m_sum_areas;
    
    // return an integer between [0, n)
    int randInt(int n) {
        return rand() / static_cast<double>(RAND_MAX) * n;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
// @lc code=end

