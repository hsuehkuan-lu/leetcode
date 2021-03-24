//Given a string s and an integer k, return the length of the longest substring 
//of s such that the frequency of each character in this substring is greater than
// or equal to k. 
//
// 
// Example 1: 
//
// 
//Input: s = "aaabb", k = 3
//Output: 3
//Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
// 
//
// Example 2: 
//
// 
//Input: s = "ababbc", k = 2
//Output: 5
//Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 
//'b' is repeated 3 times.
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 104 
// s consists of only lowercase English letters. 
// 1 <= k <= 105 
// 
// Related Topics Divide and Conquer Recursion Sliding Window 
// 👍 2404 👎 261


#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int slidingWindowSolution(string &s, int &k) {
        unordered_map<char, int> mp, ch_cnt;
        for(auto &ch: s) ++ch_cnt[ch];
        int left, right, n, max_len;
        n = s.size();
        left = right = 0;
        max_len = 0;
        while(right < n) {
            char ch = s[right];
            ++mp[ch];
            ++right;
            if(ch_cnt[ch] < k) {
                left = right;
                mp.clear();
            } else {
                if(mp[ch] >= k) {
                    bool update = true;
                    for(auto &m: mp) {
                        if(m.second < k) {
                            update = false;
                            break;
                        }
                    }
                    if(update) max_len = max(max_len, right - left);
                }
            }
        }
        return max_len;
    }
    int findInvalid(const string &s, const int &left, const int &right, const int &k) {
        unordered_map<char, int> mp;
        for(int i=left; i<=right; ++i) ++mp[s[i]];
        for(int i=left; i<=right; ++i) {
            if(mp[s[i]] < k) return i;
        }
        return -1;
    }
    int divideAndConquerSolution(string &s, int left, int right, int &k) {
        int mid = findInvalid(s, left, right, k);
        if(mid == -1) return right - left + 1;
        return max(
                divideAndConquerSolution(s, left, mid-1, k),
                divideAndConquerSolution(s, mid+1, right, k)
            );
    }
    int optimizeFindInvalid(const string &s, const int &k) {
        unordered_map<char, int> mp;
        for(auto &c: s) ++mp[c];
        for(int i=0; i<s.size(); ++i) {
            if(mp[s[i]] < k) return i;
        }
        return -1;
    }
    int optimizeSubstringSolution(string s, int &k) {
        if(s.empty() || k > s.size()) return 0;
        if(k == 0) return s.size();
        int mid = optimizeFindInvalid(s, k);
        if(mid == -1) return s.size();
        return max(
                optimizeSubstringSolution(s.substr(0, mid), k),
                optimizeSubstringSolution(s.substr(mid+1), k)
                );
    }
    int longestSubstring(string s, int k) {
        return optimizeSubstringSolution(s, k);
//        if(s.empty() || k > s.size()) return 0;
//        if(k == 0) return s.size();
//        return divideAndConquerSolution(s, 0, s.size()-1, k);
//        return slidingWindowSolution(s, k);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    solution.longestSubstring("aaabccccb", 3);
    return 0;
}