/*
 * @lc app=leetcode id=1286 lang=cpp
 *
 * [1286] Iterator for Combination
 *
 * https://leetcode.com/problems/iterator-for-combination/description/
 *
 * algorithms
 * Medium (67.99%)
 * Likes:    313
 * Dislikes: 33
 * Total Accepted:    18K
 * Total Submissions: 25.7K
 * Testcase Example:  '["CombinationIterator","next","hasNext","next","hasNext","next","hasNext"]\r\n[["abc",2],[],[],[],[],[],[]]\r'
 *
 * Design an Iterator class, which has:
 * 
 * 
 * A constructor that takes a string characters of sorted distinct lowercase
 * English letters and a number combinationLength as arguments.
 * A function next() that returns the next combination of length
 * combinationLength in lexicographical order.
 * A function hasNext() that returns True if and only if there exists a next
 * combination.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * CombinationIterator iterator = new CombinationIterator("abc", 2); // creates
 * the iterator.
 * 
 * iterator.next(); // returns "ab"
 * iterator.hasNext(); // returns true
 * iterator.next(); // returns "ac"
 * iterator.hasNext(); // returns true
 * iterator.next(); // returns "bc"
 * iterator.hasNext(); // returns false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= combinationLength <= characters.length <= 15
 * There will be at most 10^4 function calls per test.
 * It's guaranteed that all calls of the function next are valid.
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <string>

class CombinationIterator {
public:
    CombinationIterator(std::string characters, int combinationLength) {
        m_characters = characters;
        std::string current = "";
        
        findCombination(0, combinationLength, current);
        current_pos = 0;
    }
    
    std::string next() {
        return combinations[current_pos++];
    }
    
    bool hasNext() {
        return current_pos < combinations.size();
    }
    
private:
    
    std::string m_characters;
    std::vector<std::string> combinations;
    int current_pos;
    
    void findCombination(int index, int combinationLength, std::string& current) {

        if (current.length() == combinationLength) {
            combinations.push_back(current);
            return;
        }
        
        if (index == m_characters.length()) {
            return;
        }
        
        for (int i = index; i < m_characters.length(); i++) {
            current.push_back(m_characters[i]);
            findCombination(i + 1, combinationLength, current);
            current.pop_back();
        }
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

