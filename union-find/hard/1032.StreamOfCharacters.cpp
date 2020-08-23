/*
 * @lc app=leetcode id=1032 lang=cpp
 *
 * [1032] Stream of Characters
 *
 * https://leetcode.com/problems/stream-of-characters/description/
 *
 * algorithms
 * Hard (48.10%)
 * Likes:    534
 * Dislikes: 82
 * Total Accepted:    31.6K
 * Total Submissions: 65.7K
 * Testcase Example:  '["StreamChecker","query","query","query","query","query","query","query","query","query","query","query","query"]\n[[["cd","f","kl"]],["a"],["b"],["c"],["d"],["e"],["f"],["g"],["h"],["i"],["j"],["k"],["l"]]'
 *
 * Implement the StreamChecker class as follows:
 * 
 * 
 * StreamChecker(words): Constructor, init the data structure with the given
 * words.
 * query(letter): returns true if and only if for some k >= 1, the last k
 * characters queried (in order from oldest to newest, including this letter
 * just queried) spell one of the words in the given list.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init
 * the dictionary.
 * streamChecker.query('a');          // return false
 * streamChecker.query('b');          // return false
 * streamChecker.query('c');          // return false
 * streamChecker.query('d');          // return true, because 'cd' is in the
 * wordlist
 * streamChecker.query('e');          // return false
 * streamChecker.query('f');          // return true, because 'f' is in the
 * wordlist
 * streamChecker.query('g');          // return false
 * streamChecker.query('h');          // return false
 * streamChecker.query('i');          // return false
 * streamChecker.query('j');          // return false
 * streamChecker.query('k');          // return false
 * streamChecker.query('l');          // return true, because 'kl' is in the
 * wordlist
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= words.length <= 2000
 * 1 <= words[i].length <= 2000
 * Words will only consist of lowercase English letters.
 * Queries will only consist of lowercase English letters.
 * The number of queries is at most 40000.
 * 
 * 
 */

// @lc code=start
class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        m_head = new TrieNode();
        for (const std::string& word: words) {
            insertWord(word);
        }
        current_string = "";
    }
    
    bool query(char letter) {
        current_string += letter;
        TrieNode* curr = m_head;
        for (int i = current_string.length() - 1; i >= 0; i--) {
            if (!curr->next_level[current_string[i] - 'a']) return false;
            curr = curr->next_level[current_string[i] - 'a'];
            if (curr->is_word) return true;
        }
        return false;
    }
    
private:
    struct TrieNode {
        std::vector<TrieNode*> next_level;
        bool is_word;
        TrieNode(): next_level(26), is_word(false) {}
    };
    
    TrieNode* m_head;
    std::string current_string;
    
    
    void insertWord(const std::string& word) {
        TrieNode* current = m_head;
        for (int i = word.length() - 1; i >= 0; i--) {
            int index = word[i] - 'a';
            if (!current->next_level[index]) {
                current->next_level[index] = new TrieNode();
            }
            current = current->next_level[index];
        }
        current->is_word = true;
    }
    
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
// @lc code=end

