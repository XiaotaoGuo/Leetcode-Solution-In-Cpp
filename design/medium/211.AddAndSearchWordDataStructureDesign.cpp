/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Add and Search Word - Data structure design
 *
 * https://leetcode.com/problems/add-and-search-word-data-structure-design/description/
 *
 * algorithms
 * Medium (36.83%)
 * Likes:    1991
 * Dislikes: 95
 * Total Accepted:    200.9K
 * Total Submissions: 538.6K
 * Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * Design a data structure that supports the following two operations:
 * 
 * 
 * void addWord(word)
 * bool search(word)
 * 
 * 
 * search(word) can search a literal word or a regular expression string
 * containing only letters a-z or .. A . means it can represent any one
 * letter.
 * 
 * Example:
 * 
 * 
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 * 
 * 
 * Note:
 * You may assume that all words are consist of lowercase letters a-z.
 * 
 */

// @lc code=start
#include <vector>
#include <memory>
#include <string>

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        head = std::make_shared<TreeNode>();
    }
    
    /** Adds a word into the data structure. */
    void addWord(std::string word) {
        std::shared_ptr<TreeNode> current_node = head;
        for (char c: word) {
            int index = c - 'a';
            if (current_node->next_levels[index] == nullptr) {
                current_node->next_levels[index] = std::make_shared<TreeNode>();
            }
            current_node = current_node->next_levels[index];
        }
        current_node->is_word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(std::string word) {
        
        return searchAletter(head, word, 0);
        
    }

private:
    struct TreeNode {
        bool is_word;
        std::vector<std::shared_ptr<TreeNode>> next_levels;
        
        TreeNode() {
            is_word = false;
            next_levels = std::vector<std::shared_ptr<TreeNode>>(26, nullptr);
        }
        
    };
    
    bool searchAletter(const std::shared_ptr<TreeNode> node, const std::string& word, int index) {
        if (node == nullptr) return false;
        
        if (index == word.length()) return node->is_word;
      
        
        char character = word[index];
        if (character == '.') {
            for (int i = 0; i < 26; i++) {
                if (searchAletter(node->next_levels[i], word, index + 1)) return true;
            }
            
            return false;
        }
        
        return searchAletter(node->next_levels[character - 'a'], word, index + 1);
    }
    
    std::shared_ptr<TreeNode> head;
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

