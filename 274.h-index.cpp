/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;
        
        // method 1
//         std::sort(citations.begin(), citations.end());
//         int num_papers = citations.size();
        
//         int pos = num_papers - 1;
//         while (pos > 0) {
//             int cite = citations[pos], last_cite = citations[pos - 1];
//             int index = num_papers - pos;
//             if (last_cite <= index && index <= cite) {
//                 return index;
//             }
//             pos--;
//         }
        
//         return min(num_papers, citations[0]);
        
        // method 2
        int num_papers = citations.size();
        std::vector<int> papers(num_papers + 1, 0);
        for (int i = 0; i < citations.size(); i++) {
            citations[i] = min(num_papers, citations[i]);
            papers[citations[i]]++;
        }
        
        int count_papers = 0, index;
        for (index = num_papers; index >= 0; index--) {
            count_papers += papers[index];
            if (index <= count_papers) {
                break;
            }
        }
        
        return index;
    }
};
// @lc code=end

