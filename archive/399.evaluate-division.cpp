/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 *
 * https://leetcode.com/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (48.76%)
 * Likes:    1671
 * Dislikes: 129
 * Total Accepted:    100.9K
 * Total Submissions: 204.8K
 * Testcase Example:  '[["a","b"],["b","c"]]\n[2.0,3.0]\n[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]'
 *
 * Equations are given in the format A / B = k, where A and B are variables
 * represented as strings, and k is a real number (floating point number).
 * Given some queries, return the answers. If the answer does not exist, return
 * -1.0.
 * 
 * Example:
 * Given  a / b = 2.0, b / c = 3.0.
 * queries are:  a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
 * return  [6.0, 0.5, -1.0, 1.0, -1.0 ].
 * 
 * The input is:  vector<pair<string, string>> equations, vector<double>&
 * values, vector<pair<string, string>> queries , where equations.size() ==
 * values.size(), and the values are positive. This represents the equations.
 * Return  vector<double>.
 * 
 * According to the example above:
 * 
 * 
 * equations = [ ["a", "b"], ["b", "c"] ],
 * values = [2.0, 3.0],
 * queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]
 * ]. 
 * 
 * 
 * 
 * The input is always valid. You may assume that evaluating the queries will
 * result in no division by zero and there is no contradiction.
 * 
 */

// @lc code=start
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> g;
        for(int i = 0; i < equations.size(); i++){
            const vector<string>& equation = equations[i];
            const double& value = values[i];
            const string& A = equation[0];
            const string& B = equation[1];
            g[A][B] = value;
            g[B][A] = 1.0 / value;
        }
        
        
        vector<double> result;
        for(int i = 0; i < queries.size(); i++){
            unordered_set<string> visited;
            const vector<string> query = queries[i];
            const string& A = query[0];
            const string& B = query[1];
            if(g.find(A) == g.end() || g.find(B) == g.end()){
                result.push_back(-1.0);
            }
            else{
                result.push_back(dfs(g, A, B, visited));
            }
        }
        
        return result;
    }
    
private:
    double dfs(unordered_map<string, unordered_map<string, double>>& g,
            const string& A, const string& B, unordered_set<string> visited){
        if(A == B){
            return 1.0;
        }
        
        for(auto iter = g[A].begin(); iter != g[A].end(); iter++){
            const string& C = iter->first;
            const double& k = iter->second;
            if(visited.count(C)) continue;
            visited.insert(C);
            double val = dfs(g, C, B, visited);
            if(val > 0){
                return k * val;
            }
        }
        
        return -1.0;
    }
};
// @lc code=end

