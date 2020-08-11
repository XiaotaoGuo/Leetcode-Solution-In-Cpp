/*
 * @lc app=leetcode id=720 lang=cpp
 *
 * [720] Longest Word in Dictionary
 */

// @lc code=start

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    struct Node{
        bool is_word;
        string word;
        vector<Node*> children;
        Node(string word_) : is_word(false), word(word_){
            children = vector<Node*>(26, nullptr);
        }
    };
    
    string longestWord(vector<string>& words) {
        /*
        unordered_set<string> htable;
        for(const string& word: words){
            htable.insert(word);
        }
        
        string result;
        for(const string& word: words){
            int len = word.length();
            len--;
            while(len != 0){
                if(!htable.count(word.substr(0, len))) break;
                len--;
            }
            if(len == 0){
                if(result.length() < word.length() || (result.length() == word.length() && result > word)) result = word;
            }
        }
        
        return result;
        */
        Node* root = new Node("");
        for(const string& word: words){
            Node* curr = root;
            for(const char& c: word){
                if(curr->children[c - 'a'] == nullptr){
                    curr->children[c - 'a'] = new Node("");
                }
                curr = curr->children[c - 'a'];
            }
            curr->is_word = true;
            curr->word = word;
        }
        
        string result;
        dfs(root, result);
        
        return result;
        
        
    }
    
private:
    void dfs(Node* root, string& result){
        if(!root) return;
        if(root->word.length() > result.length()){
            result = root->word;
        }
        else if(root->word.length() == result.length() && root->word < result){
            result = root->word;
        }
        
        for(const auto& child: root->children){
            if(child && child->is_word) dfs(child, result);
        }
    }
};
// @lc code=end

