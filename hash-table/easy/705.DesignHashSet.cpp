/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 *
 * https://leetcode.com/problems/design-hashset/description/
 *
 * algorithms
 * Easy (60.72%)
 * Likes:    434
 * Dislikes: 81
 * Total Accepted:    77.4K
 * Total Submissions: 121.6K
 * Testcase Example:  '["MyHashSet","add","add","contains","contains","add","contains","remove","contains"]\n[[],[1],[2],[1],[3],[2],[2],[2],[2]]'
 *
 * Design a HashSet without using any built-in hash table libraries.
 * 
 * To be specific, your design should include these functions:
 * 
 * 
 * add(value): Insert a value into the HashSet. 
 * contains(value) : Return whether the value exists in the HashSet or not.
 * remove(value): Remove a value in the HashSet. If the value does not exist in
 * the HashSet, do nothing.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * MyHashSet hashSet = new MyHashSet();
 * hashSet.add(1);         
 * hashSet.add(2);         
 * hashSet.contains(1);    // returns true
 * hashSet.contains(3);    // returns false (not found)
 * hashSet.add(2);          
 * hashSet.contains(2);    // returns true
 * hashSet.remove(2);          
 * hashSet.contains(2);    // returns false (already removed)
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All values will be in the range of [0, 1000000].
 * The number of operations will be in the range of [1, 10000].
 * Please do not use the built-in HashSet library.
 * 
 * 
 */

// @lc code=start
#include <vector>

using namespace std;

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        is_valid = vector<vector<bool>>(1001, vector<bool>(1000, false));
    }
    
    void add(int key) {
        int row = key / 1000;
        int col = key % 1000;
        is_valid[row][col] = true;
    }
    
    void remove(int key) {
        int row = key / 1000;
        int col = key % 1000;
        is_valid[row][col] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int row = key / 1000;
        int col = key % 1000;
        return is_valid[row][col];
    }
    
private:
    vector<vector<bool>> is_valid;

};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

