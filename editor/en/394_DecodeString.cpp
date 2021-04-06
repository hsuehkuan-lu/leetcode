//Given an encoded string, return its decoded string. 
//
// The encoding rule is: k[encoded_string], where the encoded_string inside the 
//square brackets is being repeated exactly k times. Note that k is guaranteed to 
//be a positive integer. 
//
// You may assume that the input string is always valid; No extra white spaces, 
//square brackets are well-formed, etc. 
//
// Furthermore, you may assume that the original data does not contain any digit
//s and that digits are only for those repeat numbers, k. For example, there won't
// be input like 3a or 2[4]. 
//
// 
// Example 1: 
// Input: s = "3[a]2[bc]"
//Output: "aaabcbc"
// Example 2: 
// Input: s = "3[a2[c]]"
//Output: "accaccacc"
// Example 3: 
// Input: s = "2[abc]3[cd]ef"
//Output: "abcabccdcdcdef"
// Example 4: 
// Input: s = "abc3[cd]xyz"
//Output: "abccdcdcdxyz"
// 
// 
// Constraints: 
//
// 
// 1 <= s.length <= 30 
// s consists of lowercase English letters, digits, and square brackets '[]'. 
// s is guaranteed to be a valid input. 
// All the integers in s are in the range [1, 300]. 
// 
// Related Topics Stack Depth-first Search 
// 👍 4824 👎 229


#include <iostream>
#include <string>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string recursionSolution(string s, int &idx) {
        string result;
        while(idx < s.size() && s[idx] != ']') {
            if (!isdigit(s[idx])) {
                result += s[idx++];
            } else {
                int k = 0;
                string tok;
                while (isdigit(s[idx])) {
                    tok += s[idx];
                    ++idx;
                }
                k = stoi(tok);
                ++idx;
                string next_s = recursionSolution(s, idx);
                ++idx;
                while (k-- > 0)
                    result += next_s;
            }
        }
        return result;
    }
    string decodeString(string s) {
        int idx = 0;
        return recursionSolution(s, idx);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    solution.decodeString("5[a2[bc]]");
    return 0;
}