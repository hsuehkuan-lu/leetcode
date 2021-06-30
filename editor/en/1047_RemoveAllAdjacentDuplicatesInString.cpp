//You are given a string s consisting of lowercase English letters. A duplicate 
//removal consists of choosing two adjacent and equal letters and removing them. 
//
// We repeatedly make duplicate removals on s until we no longer can. 
//
// Return the final string after all such duplicate removals have been made. It 
//can be proven that the answer is unique. 
//
// 
// Example 1: 
//
// 
//Input: s = "abbaca"
//Output: "ca"
//Explanation: 
//For example, in "abbaca" we could remove "bb" since the letters are adjacent a
//nd equal, and this is the only possible move.  The result of this move is that t
//he string is "aaca", of which only "aa" is possible, so the final string is "ca"
//.
// 
//
// Example 2: 
//
// 
//Input: s = "azxxzy"
//Output: "ay"
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 105 
// s consists of lowercase English letters. 
// 
// Related Topics String Stack 
// 👍 1845 👎 106


#include <iostream>
#include <stack>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        for(char &i: s) {
            if(!ans.empty() && i == ans.back()) ans.pop_back();
            else ans.push_back(i);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    solution.removeDuplicates("aaaaa");
    return 0;
}