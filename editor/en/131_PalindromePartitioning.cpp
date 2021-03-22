//Given a string s, partition s such that every substring of the partition is a 
//palindrome. Return all possible palindrome partitioning of s. 
//
// A palindrome string is a string that reads the same backward as forward. 
//
// 
// Example 1: 
// Input: s = "aab"
//Output: [["a","a","b"],["aa","b"]]
// Example 2: 
// Input: s = "a"
//Output: [["a"]]
// 
// 
// Constraints: 
//
// 
// 1 <= s.length <= 16 
// s contains only lowercase English letters. 
// 
// Related Topics Dynamic Programming Backtracking Depth-first Search 
// 👍 3162 👎 101


#include <iostream>
#include <string>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int n;
    bool isPalindrome(string &s) {
        for(int left=0, right=s.size()-1; left<=right; ++left, --right) {
            if(s[left] != s[right]) return false;
        }
        return true;
    }
    void backtrackingSolution(string &s, int position, vector<vector<string>> &ans,
                                                vector<string> &v) {
        if(position == n)
            ans.push_back(v);
        else {
            for(int i=position; i<n; ++i) {
                string sub_s = s.substr(position, i - position + 1);
                if(isPalindrome(sub_s)) {
                    v.push_back(sub_s);
                    backtrackingSolution(s, i+1, ans, v);
                    v.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.size();
        vector<vector<string>> ans;
        vector<string> v;
        backtrackingSolution(s, 0, ans, v);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    solution.partition("efe");
    return 0;
}