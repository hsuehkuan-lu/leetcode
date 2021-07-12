//Given two strings s and t, determine if they are isomorphic. 
//
// Two strings s and t are isomorphic if the characters in s can be replaced to 
//get t. 
//
// All occurrences of a character must be replaced with another character while 
//preserving the order of characters. No two characters may map to the same charac
//ter, but a character may map to itself. 
//
// 
// Example 1: 
// Input: s = "egg", t = "add"
//Output: true
// Example 2: 
// Input: s = "foo", t = "bar"
//Output: false
// Example 3: 
// Input: s = "paper", t = "title"
//Output: true
// 
// 
// Constraints: 
//
// 
// 1 <= s.length <= 5 * 104 
// t.length == s.length 
// s and t consist of any valid ascii character. 
// 
// Related Topics Hash Table String 
// 👍 2306 👎 497


#include <iostream>
#include <unordered_map>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> mp1, mp2;
        for(int i=0; i<s.size(); ++i) {
            if(mp1[s[i]] != mp2[t[i]]) return false;
            mp1[s[i]] = mp2[t[i]] = i+1;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    cout << solution.isIsomorphic("bbbaaaba", "aaabbbba");
    return 0;
}