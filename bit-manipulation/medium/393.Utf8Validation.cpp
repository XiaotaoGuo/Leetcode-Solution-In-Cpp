/*
 * @lc app=leetcode id=393 lang=cpp
 *
 * [393] UTF-8 Validation
 *
 * https://leetcode.com/problems/utf-8-validation/description/
 *
 * algorithms
 * Medium (38.23%)
 * Likes:    302
 * Dislikes: 1271
 * Total Accepted:    58.5K
 * Total Submissions: 152.7K
 * Testcase Example:  '[197,130,1]'
 *
 * Given an integer array data representing the data, return whether it is a
 * valid UTF-8 encoding.
 *
 * A character in UTF8 can be from 1 to 4 bytes long, subjected to the
 * following rules:
 *
 *
 * For a 1-byte character, the first bit is a 0, followed by its Unicode
 * code.
 * For an n-bytes character, the first n bits are all one's, the n + 1 bit is
 * 0, followed by n - 1 bytes with the most significant 2 bits being 10.
 *
 *
 * This is how the UTF-8 encoding would work:
 *
 *
 * ⁠  Char. number range  |        UTF-8 octet sequence
 * ⁠     (hexadecimal)    |              (binary)
 * ⁠  --------------------+---------------------------------------------
 * ⁠  0000 0000-0000 007F | 0xxxxxxx
 * ⁠  0000 0080-0000 07FF | 110xxxxx 10xxxxxx
 * ⁠  0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
 * ⁠  0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
 *
 *
 * Note: The input is an array of integers. Only the least significant 8 bits
 * of each integer is used to store the data. This means each integer
 * represents only 1 byte of data.
 *
 *
 * Example 1:
 *
 *
 * Input: data = [197,130,1]
 * Output: true
 * Explanation: data represents the octet sequence: 11000101 10000010 00000001.
 * It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte
 * character.
 *
 *
 * Example 2:
 *
 *
 * Input: data = [235,140,4]
 * Output: false
 * Explanation: data represented the octet sequence: 11101011 10001100
 * 00000100.
 * The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes
 * character.
 * The next byte is a continuation byte which starts with 10 and that's
 * correct.
 * But the second continuation byte does not start with 10, so it is
 * invalid.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= data.length <= 2 * 10^4
 * 0 <= data[i] <= 255
 *
 *
 */

// @lc code=start
#include <vector>

class Solution {
public:
    bool validUtf8(std::vector<int>& data) {
        int idx = 0;
        int count = 1;
        while (idx < data.size()) {
            int first_byte = data[idx];
            if ((first_byte & 0x80) == 0x00) {
                // use 1000 0000 as mask to see if start with 0
                count = 1;
            } else if ((first_byte & 0xe0) == 0xc0) {
                // use 1110 0000 as mask to see if start with 110
                count = 2;
            } else if ((first_byte & 0xf0) == 0xe0) {
                // use 1111 0000 as mask to see if start with 1110
                count = 3;
            } else if ((first_byte & 0xf8) == 0xf0) {
                // use 1111 1000 as mask to see if start with 11110
                count = 4;
            } else {
                return false;
            }

            while (count > 1) {
                idx++;
                count--;
                // thr following count - 1 byte should all start with 10
                if (idx == data.size() || (data[idx] & 0xc0) != 0x80)
                    return false;
            }
            idx++;
        }

        return count == 1;
    }
};
// @lc code=end
