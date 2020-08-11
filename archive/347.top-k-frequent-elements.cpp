/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (56.67%)
 * Likes:    1948
 * Dislikes: 125
 * Total Accepted:    261K
 * Total Submissions: 456.7K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * Note: 
 * 
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * 
 * 
 */

// @lc code=start
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.empty()) return nums;
        unordered_map<int, int> m;
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> q;
        vector<int> ans;
        for(auto num: nums){
            if(m.find(num) == m.end()){
                m[num] = 1;
            }
            else{
                m[num] += 1;
            }
        }
        
        for(auto iter = m.begin(); iter != m.end(); iter++){
            q.push(pair<int, int>(iter->first, iter->second));
            if(q.size() > k) q.pop();
        }
        
        for(int i = 1; i <= k; i++){
            ans.push_back(q.top().first);
            q.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
private:
    struct comp{
        bool operator() (const pair<int, int>& p1, const pair<int, int>& p2){
            return p1.second > p2.second;
        }
    };
};
// @lc code=end

