//Given a string s and a dictionary of strings wordDict, return true if s can be
// segmented into a space-separated sequence of one or more dictionary words. 
//
// Note that the same word in the dictionary may be reused multiple times in the
// segmentation. 
//
// 
// Example 1: 
//
// 
//Input: s = "leetcode", wordDict = ["leet","code"]
//Output: true
//Explanation: Return true because "leetcode" can be segmented as "leet code".
// 
//
// Example 2: 
//
// 
//Input: s = "applepenapple", wordDict = ["apple","pen"]
//Output: true
//Explanation: Return true because "applepenapple" can be segmented as "apple pe
//n apple".
//Note that you are allowed to reuse a dictionary word.
// 
//
// Example 3: 
//
// 
//Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
//Output: false
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 300 
// 1 <= wordDict.length <= 1000 
// 1 <= wordDict[i].length <= 20 
// s and wordDict[i] consist of only lowercase English letters. 
// All the strings of wordDict are unique. 
// 
// Related Topics Dynamic Programming 
// 👍 6174 👎 288


#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int topDown(string &s, vector<string> &wordDict, vector<int> &dp, unordered_set<string> &word_set,
                unordered_set<int> &position_set, int position) {
        if(position < 0) return -1;
        if(position == 0) return 1;
        if(position_set.find(position) != position_set.end()) return -1;
        if(dp[position]) return dp[position];
        position_set.insert(position);
        bool solved = false;
        for(auto &word: wordDict) {
            int start = position - int(word.length());
            if(start >= 0 && word_set.find(s.substr(start, word.length())) != word_set.end()) {
                solved = topDown(s, wordDict, dp, word_set, position_set, start) != -1 || solved;
            }
        }
        if(solved) dp[position] = true;
        return solved ? 1 : -1;
    }
    bool bottomUp(string &s, vector<string> &wordDict) {
        if(s.empty()) return true;
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1);
        dp[0] = true;
        int max_length = 0, min_length = INT_MAX;
        for(auto &i: wordDict) {
            min_length = min(min_length, int(i.length()));
            max_length = max(max_length, int(i.length()));
        }
        for(int i=0; i<s.length(); ++i) {
            for(int j=i+min_length; j<=s.length(); ++j) {
                if(dp[i] && word_set.find(s.substr(i, j-i)) != word_set.end())
                    dp[j] = true;
            }
        }
        return dp[s.length()];
    }
    struct compare {
        inline bool operator()(const string &a, const string &b) const {
            return a.size() > b.size();
        }
    };
    bool wordBreak(string s, vector<string>& wordDict) {
//        return bottomUp(s, wordDict);
        compare c;
        sort(wordDict.begin(), wordDict.end(), c);
        vector<int> dp(s.length() + 1);
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        unordered_set<int> position_set;
        topDown(s, wordDict, dp, word_set, position_set, s.length());
        return dp[s.length()];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<string> words = {"cats", "dog", "sand", "and", "cat"};
    solution.wordBreak("catsandog", words);
    return 0;
}