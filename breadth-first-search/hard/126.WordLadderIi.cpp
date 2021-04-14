/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 *
 * https://leetcode.com/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (23.63%)
 * Likes:    2415
 * Dislikes: 296
 * Total Accepted:    223.7K
 * Total Submissions: 940.2K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * A transformation sequence from word beginWord to word endWord using a
 * dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... ->
 * sk such that:
 *
 *
 * Every adjacent pair of words differs by a single letter.
 * Every si for 1 <= i <= k is in wordList. Note that beginWord does not need
 * to be in wordList.
 * sk == endWord
 *
 *
 * Given two words, beginWord and endWord, and a dictionary wordList, return
 * all the shortest transformation sequences from beginWord to endWord, or an
 * empty list if no such sequence exists. Each sequence should be returned as a
 * list of the words [beginWord, s1, s2, ..., sk].
 *
 *
 * Example 1:
 *
 *
 * Input: beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log","cog"]
 * Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
 * Explanation: There are 2 shortest transformation sequences:
 * "hit" -> "hot" -> "dot" -> "dog" -> "cog"
 * "hit" -> "hot" -> "lot" -> "log" -> "cog"
 *
 *
 * Example 2:
 *
 *
 * Input: beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log"]
 * Output: []
 * Explanation: The endWord "cog" is not in wordList, therefore there is no
 * valid transformation sequence.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= beginWord.length <= 7
 * endWord.length == beginWord.length
 * 1 <= wordList.length <= 5000
 * wordList[i].length == beginWord.length
 * beginWord, endWord, and wordList[i] consist of lowercase English
 * letters.
 * beginWord != endWord
 * All the words in wordList are unique.
 *
 *
 */

// @lc code=start
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    std::vector<std::vector<std::string>> findLadders(
        std::string beginWord, std::string endWord,
        std::vector<std::string>& wordList) {
        std::vector<std::vector<std::string>> result;
        // construct graph
        std::queue<int> candidates;
        for (int i = 0; i < wordList.size(); ++i) {
            if (wordList[i] == endWord) {
                candidates.push(i);
            }
            graph_[i] = {};
            for (int j = 0; j < i; ++j) {
                if (countDiff(wordList[i], wordList[j]) == 1) {
                    graph_[i].push_back(j);
                    graph_[j].push_back(i);
                }
            }
        }

        if (candidates.empty()) {
            return result;
        }

        std::unordered_set<int> end_nodes;
        std::unordered_map<int, int> used{{candidates.front(), 0}};
        bool find_target = false;
        int step = 1;
        std::unordered_map<int, int> used_step;
        while (!candidates.empty() && !find_target) {
            std::queue<int> next;
            while (!candidates.empty()) {
                int curr_idx = candidates.front();  // parent & current idx
                candidates.pop();

                // cout << wordList[curr_idx] << endl;
                if (countDiff(wordList[curr_idx], beginWord) == 1) {
                    find_target = true;
                    end_nodes.insert(curr_idx);
                }

                for (auto neighbor : graph_[curr_idx]) {
                    if (used.find(neighbor) == used.end() ||
                        used[neighbor] == step) {
                        // cout << "nei: " << neighbor << ", idx: " << curr_idx
                        // << std::endl;
                        next.push(neighbor);
                        parent_idx_[neighbor].push_back(curr_idx);
                        used[neighbor] = step;
                    }
                }
            }
            candidates = next;
            step++;
        }

        std::vector<std::string> curr{beginWord};

        for (auto end : end_nodes) {
            dfs(end, curr, result, wordList);
        }

        return result;
    }

private:
    std::unordered_map<int, std::vector<int>> parent_idx_;
    std::unordered_map<int, std::vector<int>> graph_;

    int countDiff(const std::string& first, const std::string& second) {
        if (first.size() != second.size()) {
            return -1;
        }

        int count = 0;
        for (int i = 0; i < first.size(); ++i) {
            count += (first[i] != second[i]);
        }

        return count;
    }

    void dfs(int idx, std::vector<std::string>& curr,
             std::vector<std::vector<std::string>>& result,
             const std::vector<std::string>& wordList) {
        curr.push_back(wordList[idx]);
        if (parent_idx_.find(idx) == parent_idx_.end()) {
            result.push_back(curr);
        } else {
            for (auto parent : parent_idx_[idx]) {
                dfs(parent, curr, result, wordList);
            }
        }
        curr.pop_back();
    }
};
// @lc code=end
