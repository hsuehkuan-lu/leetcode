//Given a string s of '(' , ')' and lowercase English characters. 
//
// Your task is to remove the minimum number of parentheses ( '(' or ')', in any
// positions ) so that the resulting parentheses string is valid and return any va
//lid string. 
//
// Formally, a parentheses string is valid if and only if: 
//
// 
// It is the empty string, contains only lowercase characters, or 
// It can be written as AB (A concatenated with B), where A and B are valid stri
//ngs, or 
// It can be written as (A), where A is a valid string. 
// 
//
// 
// Example 1: 
//
// 
//Input: s = "lee(t(c)o)de)"
//Output: "lee(t(c)o)de"
//Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
// 
//
// Example 2: 
//
// 
//Input: s = "a)b(c)d"
//Output: "ab(c)d"
// 
//
// Example 3: 
//
// 
//Input: s = "))(("
//Output: ""
//Explanation: An empty string is also valid.
// 
//
// Example 4: 
//
// 
//Input: s = "(a(b(c)d)"
//Output: "a(b(c)d)"
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 10^5 
// s[i] is one of '(' , ')' and lowercase English letters. 
// Related Topics String Stack 
// 👍 2005 👎 47


#include <iostream>
#include <stack>
#include <string>
#include <unordered_set>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string stackSolution(string &s) {
        unordered_set<int> st;
        stack<int> S;
        string ans;
        for(int i=0; i<s.size(); ++i) {
            if (s[i] == '(') {
                S.push(i);
            } else if (s[i] == ')') {
                if (S.empty()) {
                    st.insert(i);
                } else {
                    S.pop();
                }
            }
        }
        while(!S.empty()) {
            st.insert(S.top());
            S.pop();
        }
        for(int i=0; i<s.size(); ++i) {
            if(!st.count(i)) {
                ans += s[i];
            }
        }
        return ans;
    }
    string threePassSolution(string &s) {
        int open = 0;
        for(char &ch: s) {
            if(ch == '(') ++open;
            else if(ch == ')') {
                if(open == 0) ch = '#';
                else --open;
            }
        }
        for(int i=s.size()-1; i>=0 && open > 0; i--) {
            auto &ch = s[i];
            if(ch == '(') {
                ch = '#';
                --open;
            }
        }
        s.erase(remove(s.begin(), s.end(), '#'), s.end());
        return s;
    }
    string minRemoveToMakeValid(string s) {
        return threePassSolution(s);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    solution.minRemoveToMakeValid("lee(t(c)o)de)");
    return 0;
}