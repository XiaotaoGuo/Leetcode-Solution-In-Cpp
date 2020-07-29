/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int num_stations = gas.size();
        int current_gas = 0, index = -1;
        int total_gas = 0, total_cost = 0;
        for (int i = 0; i < num_stations; i++) {
            total_gas += gas[i];
            total_cost += cost[i];
            
            if (gas[i] >= cost[i] && current_gas == 0) {
                index = i;       
            }
            
            current_gas += gas[i] - cost[i];
            if (current_gas < 0) {
                index = -1;
                current_gas = 0;
            }
            
        }
        
        if (total_gas < total_cost) return -1;
        return index;
    }
};
// @lc code=end

