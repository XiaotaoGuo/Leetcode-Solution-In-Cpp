/*
 * @lc app=leetcode id=1093 lang=cpp
 *
 * [1093] Statistics from a Large Sample
 *
 * https://leetcode.com/problems/statistics-from-a-large-sample/description/
 *
 * algorithms
 * Medium (44.40%)
 * Likes:    38
 * Dislikes: 184
 * Total Accepted:    6.1K
 * Total Submissions: 13.3K
 * Testcase Example:  '[0,1,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]'
 *
 * We sampled integers between 0 and 255, and stored the results in an array
 * count:  count[k] is the number of integers we sampled equal to k.
 * 
 * Return the minimum, maximum, mean, median, and mode of the sample
 * respectively, as an array of floating point numbers.  The mode is guaranteed
 * to be unique.
 * 
 * (Recall that the median of a sample is:
 * 
 * 
 * The middle element, if the elements of the sample were sorted and the number
 * of elements is odd;
 * The average of the middle two elements, if the elements of the sample were
 * sorted and the number of elements is even.)
 * 
 * 
 * 
 * Example 1:
 * Input: count =
 * [0,1,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
 * Output: [1.00000,3.00000,2.37500,2.50000,3.00000]
 * Example 2:
 * Input: count =
 * [0,4,3,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
 * Output: [1.00000,4.00000,2.18182,2.00000,1.00000]
 * 
 * 
 * Constraints:
 * 
 * 
 * count.length == 256
 * 1 <= sum(count) <= 10^9
 * The mode of the sample that count represents is unique.
 * Answers within 10^-5 of the true value will be accepted as correct.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        long total = 0, s = 0;
        double minv = 256, maxv = -1;
        double mode = -1;
        int mode_c = -1;
        for(int i = 0; i < count.size(); i++){
            total += count[i];
            s += count[i] * i;
            if(count[i] != 0){
                minv = min(minv, (double)i);
                maxv = max(maxv, (double)i);
            }
            if(mode_c < count[i]){
                mode = i;
                mode_c = count[i];
            }
        }
        double avg = (double)s / total;
        minv = minv == 256 ? 0 : minv;
        maxv = maxv == -1 ? 0 : maxv;
        if(maxv == 0 && minv == 0) return {0.0, 0.0, 0.0, 0.0, 0.0};
        vector<double> res(5, 0);
        res[0] = minv;
        res[1] = maxv;
        res[2] = avg;
        res[4] = mode;
        
        int left = 0, right = 255;
        while (left < right) {
            while (count[left] == 0) left++;
            while (count[right] == 0) right--;
            if (count[left] == count[right]) {
                left++;
                right--;
            } else if (count[left] > count[right]) {
                count[left] -= count[right];
                right--;
            } else {
                count[right] -= count[left];
                left++;
            }
        }
        res[3] = 1.0 * (left + right) / 2;
        return res;
    }
};
// @lc code=end

