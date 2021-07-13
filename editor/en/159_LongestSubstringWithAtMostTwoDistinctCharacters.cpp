//Given a string s, return the length of the longest substring that contains at 
//most two distinct characters. 
//
// 
// Example 1: 
//
// 
//Input: s = "eceba"
//Output: 3
//Explanation: The substring is "ece" which its length is 3.
// 
//
// Example 2: 
//
// 
//Input: s = "ccaabbb"
//Output: 5
//Explanation: The substring is "aabbb" which its length is 5.
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 104 
// s consists of English letters. 
// 
// Related Topics Hash Table String Sliding Window 
// 👍 1377 👎 21


#include <iostream>
#include <unordered_map>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> mp;
        int max_len = 0;
        int l = 0, r = 0, n = s.size();
        while(r < n) {
            while(r < n && (mp.size() < 2 || mp.count(s[r]))) {
                ++mp[s[r]];
                ++r;
            }
            max_len = max(max_len, r - l);
            while(mp.size() == 2 && l < r) {
                if(--mp[s[l]] == 0) mp.erase(s[l]);
                ++l;
            }
        }
        return max_len;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    string s = "ccaabbb";
    cout << solution.lengthOfLongestSubstringTwoDistinct(s);
    return 0;
}