//Given a string s and an integer k, return the length of the longest substring 
//of s that contains at most k distinct characters. 
//
// 
// Example 1: 
//
// 
//Input: s = "eceba", k = 2
//Output: 3
//Explanation: The substring is "ece" with length 3. 
//
// Example 2: 
//
// 
//Input: s = "aa", k = 1
//Output: 2
//Explanation: The substring is "aa" with length 2.
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 5 * 104 
// 0 <= k <= 50 
// 
// Related Topics Hash Table Two Pointers String Sliding Window 
// 👍 1540 👎 56


#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <string>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    struct Data {
        char ch;
        int idx;
        Data(char c, int i): ch(c), idx(i) {}
    };
    int orderedMapSolution(string &s, int &k) {
        if(k == 0) return 0;
        if(k > s.size()) return s.size();
        int max_len = 0, n = s.size();
        int left = 0, right = 0;
        unordered_map<char, list<Data>::iterator> mp;
        list<Data> lru;
        while(right < n) {
            char tok = s[right];
            if(mp.count(tok)) {
                auto it = mp[tok];
                lru.erase(it);
            }
            lru.push_front(Data(tok, right));
            mp[tok] = lru.begin();
            if(mp.size() == k + 1) {
                auto back = lru.back();
                mp.erase(back.ch);
                lru.pop_back();
                left = back.idx + 1;
            }
            max_len = max(max_len, right - left + 1);
            ++right;
        }
        return max_len;
    }
    int hashMapSolution(string &s, int &k) {
        if(k == 0) return 0;
        if(k > s.size()) return s.size();
        int max_len = 0, n = s.size();
        int left = 0, right = 0;
        unordered_map<char, int> mp;
        while(right < n) {
            char tok = s[right];
            mp[tok] = right++;
            if(mp.size() == k + 1) {
                int min_left = INT_MAX;
                for(auto &m: mp)
                    min_left = min(min_left, m.second);
                mp.erase(s[min_left]);
                left = min_left + 1;
            }
            max_len = max(max_len, right - left);
        }
        return max_len;
    }
    int hashSetSolution(string &s, int &k) {
        if(k == 0) return 0;
        if(k > s.size()) return s.size();
        int max_len = 0, n = s.size();
        int left = 0, right = 0;
        unordered_set<char> ch_s;
        while(right < n) {
            if(ch_s.count(s[right])) {
                max_len = max(max_len, right - left + 1);
                ++right;
            } else {
                if(ch_s.size() < k) {
                    max_len = max(max_len, right - left + 1);
                    ch_s.insert(s[right++]);
                } else {
                    auto tmp_s(ch_s);
                    int idx;
                    char ch;
                    for(int i=right-1; i>=left; --i) {
                        ch = s[i];
                        tmp_s.erase(s[i]);
                        idx = i+1;
                        if(tmp_s.empty()) break;
                    }
                    left = idx;
                    ch_s.erase(ch);
                }
            }
        }
        return max_len;
    }
    int lengthOfLongestSubstringKDistinct(string s, int k) {
//        return hashMapSolution(s, k);
        return orderedMapSolution(s, k);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    solution.lengthOfLongestSubstringKDistinct("abaccc", 2);
    return 0;
}