/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Add and Search Word - Data structure design
 *
 * https://leetcode.com/problems/add-and-search-word-data-structure-design/description/
 *
 * algorithms
 * Medium (31.91%)
 * Likes:    1127
 * Dislikes: 64
 * Total Accepted:    138.6K
 * Total Submissions: 422.7K
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
class WordDictionary {
private:
    class Node{
    public:
        bool is_word;
        unordered_map<char, Node*> edges;
        Node():is_word(false){}
    };
    
    Node* head;
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        head = new Node();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node* curr = head;
        for(int i = 0; i < word.length(); i++){
            if(curr->edges.find(word[i]) == curr->edges.end()){
                curr->edges[word[i]] = new Node();
            }
            curr = curr->edges[word[i]];
        }
        if(!curr->is_word) curr->is_word = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(word, 0, head);
    }
    
    bool dfs(string& word, int idx, Node* curr){
        if(idx == word.length() && curr){
            return curr->is_word;
        }
        if(!curr) return false;
        if(word[idx] != '.'){
            if(curr->edges.find(word[idx]) == curr->edges.end()) return false;
            return dfs(word, idx + 1, curr->edges[word[idx]]);
        }
        for(auto iter = curr->edges.begin(); iter != curr->edges.end(); iter++){
            if(dfs(word, idx + 1, iter->second)) return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

