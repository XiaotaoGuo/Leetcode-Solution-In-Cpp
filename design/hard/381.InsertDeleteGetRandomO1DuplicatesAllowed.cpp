/*
 * @lc app=leetcode id=381 lang=cpp
 *
 * [381] Insert Delete GetRandom O(1) - Duplicates allowed
 *
 * https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/
 *
 * algorithms
 * Hard (35.14%)
 * Likes:    1192
 * Dislikes: 94
 * Total Accepted:    88.3K
 * Total Submissions: 251K
 * Testcase Example:
 '["RandomizedCollection","insert","insert","insert","getRandom","remove","getRandom"]\n'
 +
  '[[],[1],[1],[2],[],[1],[]]'
 *
 * Implement the RandomizedCollection class:
 *
 *
 * RandomizedCollection() Initializes the RandomizedCollection object.
 * bool insert(int val) Inserts an item val into the multiset if not present.
 * Returns true if the item was not present, false otherwise.
 * bool remove(int val) Removes an item val from the multiset if present.
 * Returns true if the item was present, false otherwise. Note that if val has
 * multiple occurrences in the multiset, we only remove one of them.
 * int getRandom() Returns a random element from the current multiset of
 * elements (it's guaranteed that at least one element exists when this method
 * is called). The probability of each element being returned is linearly
 * related to the number of same values the multiset contains.
 *
 *
 * You must implement the functions of the class such that each function works
 * in average O(1) time complexity.
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["RandomizedCollection", "insert", "insert", "insert", "getRandom",
 * "remove", "getRandom"]
 * [[], [1], [1], [2], [], [1], []]
 * Output
 * [null, true, false, true, 2, true, 1]
 *
 * Explanation
 * RandomizedCollection randomizedCollection = new RandomizedCollection();
 * randomizedCollection.insert(1);   // return True. Inserts 1 to the
 * collection. Returns true as the collection did not contain 1.
 * randomizedCollection.insert(1);   // return False. Inserts another 1 to the
 * collection. Returns false as the collection contained 1. Collection now
 * contains [1,1].
 * randomizedCollection.insert(2);   // return True. Inserts 2 to the
 * collection, returns true. Collection now contains [1,1,2].
 * randomizedCollection.getRandom(); // getRandom should return 1 with the
 * probability 2/3, and returns 2 with the probability 1/3.
 * randomizedCollection.remove(1);   // return True. Removes 1 from the
 * collection, returns true. Collection now contains [1,2].
 * randomizedCollection.getRandom(); // getRandom should return 1 and 2 both
 * equally likely.
 *
 *
 *
 * Constraints:
 *
 *
 * -2^31 <= val <= 2^31 - 1
 * At most 2 * 10^5  calls will be made to insert, remove, and getRandom.
 * There will be at least one element in the data structure when getRandom is
 * called.
 *
 *
 */

// @lc code=start
#include <unordered_map>
#include <unordered_set>
#include <vector>

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {}

    /** Inserts a value to the collection. Returns true if the collection did
     * not already contain the specified element. */
    bool insert(int val) {
        bool has_val = (val_indices[val].empty());
        val_indices[val].insert(nums.size());
        nums.push_back(val);
        return has_val;
    }

    /** Removes a value from the collection. Returns true if the collection
     * contained the specified element. */
    bool remove(int val) {
        if (val_indices[val].size()) {
            int index = *val_indices[val].begin();
            val_indices[val].erase(index);
            int end_num = nums.back();
            val_indices[end_num].insert(index);
            val_indices[end_num].erase(nums.size() - 1);

            std::swap(nums[index], nums.back());
            nums.pop_back();
            return true;
        }
        return false;
    }

    /** Get a random element from the collection. */
    int getRandom() { return nums[rand() % nums.size()]; }

private:
    std::vector<int> nums;
    std::unordered_map<int, std::unordered_set<int>> val_indices;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
