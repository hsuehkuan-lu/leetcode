//Given a string s, a k duplicate removal consists of choosing k adjacent and eq
//ual letters from s and removing them causing the left and the right side of the 
//deleted substring to concatenate together. 
//
// We repeatedly make k duplicate removals on s until we no longer can. 
//
// Return the final string after all such duplicate removals have been made. 
//
// It is guaranteed that the answer is unique. 
//
// 
// Example 1: 
//
// 
//Input: s = "abcd", k = 2
//Output: "abcd"
//Explanation: There's nothing to delete. 
//
// Example 2: 
//
// 
//Input: s = "deeedbbcccbdaa", k = 3
//Output: "aa"
//Explanation: 
//First delete "eee" and "ccc", get "ddbbbdaa"
//Then delete "bbb", get "dddaa"
//Finally delete "ddd", get "aa" 
//
// Example 3: 
//
// 
//Input: s = "pbbcggttciiippooaais", k = 2
//Output: "ps"
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 10^5 
// 2 <= k <= 10^4 
// s only contains lower case English letters. 
// 
// Related Topics Stack 
// 👍 1193 👎 29


#include <iostream>
#include <string>
#include <stack>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string stackSolution(string &s, int &k) {
        stack<char> ch_s;
        stack<int> ch_cnt;
        for(auto &ch: s) {
            if(!ch_s.empty() && ch == ch_s.top()) {
                if(++ch_cnt.top() == k) {
                    ch_s.pop();
                    ch_cnt.pop();
                }
            } else {
                ch_s.push(ch);
                ch_cnt.push(1);
            }
        }
        string ans;
        while(!ch_s.empty()) {
            ans = string(ch_cnt.top(), ch_s.top()) + ans;
            ch_cnt.pop();
            ch_s.pop();
        }
        return ans;
    }
    string removeDuplicates(string s, int k) {
        return stackSolution(s, k);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    solution.removeDuplicates("deeedbbcccbdaa", 3);
    return 0;
}