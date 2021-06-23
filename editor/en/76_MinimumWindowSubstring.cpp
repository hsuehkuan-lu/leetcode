//Given two strings s and t of lengths m and n respectively, return the minimum 
//window substring of s such that every character in t (including duplicates) is i
//ncluded in the window. If there is no such substring, return the empty string ""
//. 
//
// The testcases will be generated such that the answer is unique. 
//
// A substring is a contiguous sequence of characters within the string. 
//
// 
// Example 1: 
//
// 
//Input: s = "ADOBECODEBANC", t = "ABC"
//Output: "BANC"
//Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' fr
//om string t.
// 
//
// Example 2: 
//
// 
//Input: s = "a", t = "a"
//Output: "a"
//Explanation: The entire string s is the minimum window.
// 
//
// Example 3: 
//
// 
//Input: s = "a", t = "aa"
//Output: ""
//Explanation: Both 'a's from t must be included in the window.
//Since the largest window of s only has one 'a', return empty string.
// 
//
// 
// Constraints: 
//
// 
// m == s.length 
// n == t.length 
// 1 <= m, n <= 105 
// s and t consist of uppercase and lowercase English letters. 
// 
//
// 
//Follow up: Could you find an algorithm that runs in O(m + n) time? Related Top
//ics Hash Table String Sliding Window 
// 👍 7002 👎 463


#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string minWindow(string s, string t) {
        int ans[] = {INT_MAX, 0, 0};
        unordered_map<char, int> mp, window;
        for(auto &ch: t) {
            ++mp[ch];
        }
        int lo = 0, hi = 0, n = s.size(), matched = 0, expected = mp.size();
        while(hi < n) {
            ++window[s[hi]];
            if(window[s[hi]] == mp[s[hi]]) {
                ++matched;
            }
            while(lo <= hi && matched == expected) {
                if(ans[0] > hi - lo + 1) {
                    ans[0] = hi - lo + 1;
                    ans[1] = lo;
                    ans[2] = hi;
                }
                --window[s[lo]];
                if(mp.count(s[lo]) && mp[s[lo]] > window[s[lo]]) {
                    --matched;
                }
                ++lo;
            }
            ++hi;
        }
        return ans[0] == INT_MAX ? "" : s.substr(ans[1], ans[2] - ans[1] + 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    cout << solution.minWindow("aa", "aa");
    return 0;
}