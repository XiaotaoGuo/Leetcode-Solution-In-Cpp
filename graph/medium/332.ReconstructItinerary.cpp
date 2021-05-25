/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 *
 * https://leetcode.com/problems/reconstruct-itinerary/description/
 *
 * algorithms
 * Medium (38.33%)
 * Likes:    2762
 * Dislikes: 1284
 * Total Accepted:    214.7K
 * Total Submissions: 558.8K
 * Testcase Example: '[["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]'
 *
 * You are given a list of airline tickets where tickets[i] = [fromi, toi]
 * represent the departure and the arrival airports of one flight. Reconstruct
 * the itinerary in order and return it.
 *
 * All of the tickets belong to a man who departs from "JFK", thus, the
 * itinerary must begin with "JFK". If there are multiple valid itineraries,
 * you should return the itinerary that has the smallest lexical order when
 * read as a single string.
 *
 *
 * For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than
 * ["JFK", "LGB"].
 *
 *
 * You may assume all tickets form at least one valid itinerary. You must use
 * all the tickets once and only once.
 *
 *
 * Example 1:
 *
 *
 * Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
 * Output: ["JFK","MUC","LHR","SFO","SJC"]
 *
 *
 * Example 2:
 *
 *
 * Input: tickets =
 * [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
 * Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
 * Explanation: Another possible reconstruction is
 * ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= tickets.length <= 300
 * tickets[i].length == 2
 * fromi.length == 3
 * toi.length == 3
 * fromi and toi consist of uppercase English letters.
 * fromi != toi
 *
 *
 */

// @lc code=start
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<std::string> findItinerary(
        std::vector<std::vector<std::string>>& tickets) {
        total_count = tickets.size() + 1;
        graph g;
        for (auto ticket : tickets) {
            g[ticket[0]][ticket[1]]++;
            // g[ticket[0]].insert({ticket[1], false});
        }
        std::string curr = "JFK";
        std::vector<std::string> ans{curr};
        int count = 1;
        dfs(g, curr, ans, count);
        // cout << endl;
        return ans;
    }

private:
    int total_count;
    using graph = std::unordered_map<std::string, map<std::string, int>>;
    void dfs(graph& g, std::string& curr, std::vector<std::string>& ans,
             int& count) {
        std::string next = "";
        // cout << "\ncurr: " << curr << " ";
        for (auto city : g[curr]) {
            if (city.second == 0) continue;
            next = city.first;
            g[curr][next]--;
            ans.push_back(next);
            count++;
            // cout << next << ", ";
            dfs(g, next, ans, count);
            // cout << "rechoosing.. \n";
            if (count == total_count) return;
            count--;
            ans.pop_back();
            g[curr][next]++;
        }
    }
};
// @lc code=end
