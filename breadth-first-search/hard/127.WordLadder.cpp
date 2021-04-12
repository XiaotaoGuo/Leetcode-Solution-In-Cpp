/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Hard (31.71%)
 * Likes:    4875
 * Dislikes: 1406
 * Total Accepted:    565.8K
 * Total Submissions: 1.8M
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
 * the number of words in the shortest transformation sequence from beginWord
 * to endWord, or 0 if no such sequence exists.
 *
 *
 * Example 1:
 *
 *
 * Input: beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log","cog"]
 * Output: 5
 * Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot"
 * -> "dog" -> cog", which is 5 words long.
 *
 *
 * Example 2:
 *
 *
 * Input: beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log"]
 * Output: 0
 * Explanation: The endWord "cog" is not in wordList, therefore there is no
 * valid transformation sequence.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= beginWord.length <= 10
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
    int ladderLength(std::string beginWord, std::string endWord,
                     std::vector<std::string>& wordList) {
        // construct graph
        std::unordered_map<int, std::vector<int>> graph;
        std::queue<int> candidates;
        for (int i = 0; i < wordList.size(); ++i) {
            if (wordList[i] == endWord) {
                candidates.push(i);
            }
            graph[i] = {};
            for (int j = 0; j < i; ++j) {
                if (countDiff(wordList[i], wordList[j]) == 1) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        int step = 1;
        std::unordered_set<int> used;
        while (!candidates.empty()) {
            std::queue<int> next;
            while (!candidates.empty()) {
                int idx = candidates.front();
                candidates.pop();
                // cout << wordList[idx] << endl;
                if (countDiff(wordList[idx], beginWord) == 1) {
                    return ++step;
                }
                used.insert(idx);

                for (auto neighbor : graph[idx]) {
                    if (used.count(neighbor) == 0) {
                        next.push(neighbor);
                    }
                }
            }
            step++;
            candidates = next;
        }

        return 0;
    }

private:
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
};
// @lc code=end
