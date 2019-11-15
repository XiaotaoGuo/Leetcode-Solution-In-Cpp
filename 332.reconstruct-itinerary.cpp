/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 *
 * https://leetcode.com/problems/reconstruct-itinerary/description/
 *
 * algorithms
 * Medium (32.60%)
 * Likes:    1048
 * Dislikes: 673
 * Total Accepted:    104.4K
 * Total Submissions: 314.3K
 * Testcase Example:  '[["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]'
 *
 * Given a list of airline tickets represented by pairs of departure and
 * arrival airports [from, to], reconstruct the itinerary in order. All of the
 * tickets belong to a man who departs from JFK. Thus, the itinerary must begin
 * with JFK.
 * 
 * Note:
 * 
 * 
 * If there are multiple valid itineraries, you should return the itinerary
 * that has the smallest lexical order when read as a single string. For
 * example, the itinerary ["JFK", "LGA"] has a smaller lexical order than
 * ["JFK", "LGB"].
 * All airports are represented by three capital letters (IATA code).
 * You may assume all tickets form at least one valid itinerary.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
 * Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
 * Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
 * Explanation: Another possible reconstruction is
 * ["JFK","SFO","ATL","JFK","ATL","SFO"].
 * But it is larger in lexical order.
 * 
 * 
 */

// @lc code=start
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        graph.clear();
        result.clear();
        
        for(vector<string>& ticket: tickets){
            string curr = ticket[0];
            string next = ticket[1];
            graph[curr].push_back(next);
        }
        
        for(auto& route: graph){
            sort(route.second.begin(), route.second.end());
        }
        string curr = "JFK";
        visit(curr);
        reverse(result.begin(), result.end());
        return result;
    }
private:
    unordered_map<string, deque<string>> graph;
    vector<string> result;
    
    void visit(string& curr){
        while(!graph[curr].empty()){
            string next = graph[curr].front();
            graph[curr].pop_front();
            visit(next);
        }
        result.push_back(curr); 
    }
};
// @lc code=end

