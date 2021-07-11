//Given a character array s, reverse the order of the words. 
//
// A word is defined as a sequence of non-space characters. The words in s will 
//be separated by a single space. 
//
// Your code must solve the problem in-place, i.e. without allocating extra spac
//e. 
//
// 
// Example 1: 
// Input: s = ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
//Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
// Example 2: 
// Input: s = ["a"]
//Output: ["a"]
// 
// 
// Constraints: 
//
// 
// 1 <= s.length <= 105 
// s[i] is an English letter (uppercase or lowercase), digit, or space ' '. 
// There is at least one word in s. 
// s does not contain leading or trailing spaces. 
// All the words in s are guaranteed to be separated by a single space. 
// 
// Related Topics Two Pointers String 
// 👍 663 👎 122


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int left = 0, right = 0;
        while(left < s.size()) {
            right = left;
            while(right < s.size() - 1 && s[right+1] != ' ') ++right;
            for(int i=0; i<(right - left + 1) / 2; ++i) {
                swap(s[left+i], s[right-i]);
            }
            left = right + 2;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<char> s = {'a'};
    solution.reverseWords(s);
    return 0;
}