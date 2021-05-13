//We had some 2-dimensional coordinates, like "(1, 3)" or "(2, 0.5)". Then, we r
//emoved all commas, decimal points, and spaces, and ended up with the string s. R
//eturn a list of strings representing all possibilities for what our original coo
//rdinates could have been. 
//
// Our original representation never had extraneous zeroes, so we never started 
//with numbers like "00", "0.0", "0.00", "1.0", "001", "00.01", or any other numbe
//r that can be represented with less digits. Also, a decimal point within a numbe
//r never occurs without at least one digit occuring before it, so we never starte
//d with numbers like ".1". 
//
// The final answer list can be returned in any order. Also note that all coordi
//nates in the final answer have exactly one space between them (occurring after t
//he comma.) 
//
// 
//Example 1:
//Input: s = "(123)"
//Output: ["(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"]
// 
//
// 
//Example 2:
//Input: s = "(00011)"
//Output:  ["(0.001, 1)", "(0, 0.011)"]
//Explanation: 
//0.0, 00, 0001 or 00.01 are not allowed.
// 
//
// 
//Example 3:
//Input: s = "(0123)"
//Output: ["(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.
//12, 3)"]
// 
//
// 
//Example 4:
//Input: s = "(100)"
//Output: [(10, 0)]
//Explanation: 
//1.0 is not allowed.
// 
//
// 
//
// Note: 
//
// 
// 4 <= s.length <= 12. 
// s[0] = "(", s[s.length - 1] = ")", and the other elements in s are digits. 
// 
//
// 
// Related Topics String 
// 👍 160 👎 343


#include <iostream>
#include <vector>
#include <string>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    vector<string> ans;
public:
    bool isValid(string &s) {
        if(s.front() == '0') {
            if(s.size() == 1) return true;
            else if(s.size() >= 3 && s[1] == '.' && s.back() != '0') return true;
            else return false;
        } else if(s.back() == '0') {
            if(s.find('.') != string::npos) return false;
        }
        return true;
    }
    void findComma(string a, string b) {
        string s1 = "." + a, s2;
        int m=a.size(), n=b.size();
        for(int i=1; i<=m; ++i) {
            swap(s1[i-1], s1[i]);
            if(s1.back() == '.') s1.pop_back();
            s2 = "." + b;
            for(int j=1; j<=n; ++j) {
                swap(s2[j-1], s2[j]);
                if(s2.back() == '.') s2.pop_back();
                if(isValid(s1) && isValid(s2)) {
                    ans.push_back("("+s1+", "+s2+")");
                }
            }
        }
    }
    vector<string> ambiguousCoordinates(string s) {
        s = s.substr(1, s.size()-2);
        for(int i=1; i<s.size(); ++i) {
            findComma(s.substr(0, i), s.substr(i));
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    solution.ambiguousCoordinates("(123)");
    return 0;
}