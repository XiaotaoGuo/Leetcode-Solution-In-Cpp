/*
 * @lc app=leetcode id=299 lang=cpp
 *
 * [299] Bulls and Cows
 */

// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> digit_nums_secret(10, 0);
        vector<int> digit_nums_guess(10, 0);
        for (char digit: secret) {
            digit_nums_secret[digit - '0']++;
        }

        for (char digit: guess) {
            digit_nums_guess[digit - '0']++;
        }

        string hint = "";
        int num_bulls = 0, num_cows = 0;

        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i]) {
                num_bulls++;
                int index = secret[i] - '0';
                digit_nums_secret[index]--;
                digit_nums_guess[index]--;
            }
        }

        hint += (to_string(num_bulls) + "A");

        for (int i = 0; i < 10; i++) {
            num_cows += min(digit_nums_secret[i], digit_nums_guess[i]);
        }

        hint += (to_string(num_cows) + "B");

        return hint;
    }
};
// @lc code=end

