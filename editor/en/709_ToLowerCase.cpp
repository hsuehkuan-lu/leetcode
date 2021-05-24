//Given a string s, return the string after replacing every uppercase letter wit
//h the same lowercase letter. 
//
// 
// Example 1: 
//
// 
//Input: s = "Hello"
//Output: "hello"
// 
//
// Example 2: 
//
// 
//Input: s = "here"
//Output: "here"
// 
//
// Example 3: 
//
// 
//Input: s = "LOVELY"
//Output: "lovely"
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 100 
// s consists of printable ASCII characters. 
// 
// Related Topics String 
// 👍 723 👎 1956


#include <iostream>
#include <string>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string toLowerCase(string s) {
        for(auto &ch: s) {
            if('A' <= ch && ch <= 'Z') {
                ch += 32;
            }
        }
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    cout << 'A' - 'a';
    return 0;
}