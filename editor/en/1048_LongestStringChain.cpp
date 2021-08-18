//You are given an array of words where each word consists of lowercase English 
//letters. 
//
// wordA is a predecessor of wordB if and only if we can insert exactly one lett
//er anywhere in wordA without changing the order of the other characters to make 
//it equal to wordB. 
//
// 
// For example, "abc" is a predecessor of "abac", while "cba" is not a predecess
//or of "bcad". 
// 
//
// A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, w
//here word1 is a predecessor of word2, word2 is a predecessor of word3, and so on
//. A single word is trivially a word chain with k == 1. 
//
// Return the length of the longest possible word chain with words chosen from t
//he given list of words. 
//
// 
// Example 1: 
//
// 
//Input: words = ["a","b","ba","bca","bda","bdca"]
//Output: 4
//Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
// 
//
// Example 2: 
//
// 
//Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
//Output: 5
//Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "p
//cxbc", "pcxbcf"].
// 
//
// Example 3: 
//
// 
//Input: words = ["abcd","dbqca"]
//Output: 1
//Explanation: The trivial word chain ["abcd"] is one of the longest word chains
//.
//["abcd","dbqca"] is not a valid word chain because the ordering of the letters
// is changed.
// 
//
// 
// Constraints: 
//
// 
// 1 <= words.length <= 1000 
// 1 <= words[i].length <= 16 
// words[i] only consists of lowercase English letters. 
// 
// Related Topics Array Hash Table Two Pointers String Dynamic Programming 
// 👍 2322 👎 120
	

#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int ans = 0;
public:
    void dfs(unordered_set<string> &st, int start, const string& cur) {
//        if(visited.count(cur)) return;
        ans = max(ans, start);
        string next = '0' + cur;
        for(int i=0; i<next.size(); ++i) {
            for(int j=0; j<26; ++j) {
                next[i] = 'a' + j;
                if(st.count(next)) {
                    dfs(st,start+1, next);
                }
            }
            if(i<next.size()-1)
                swap(next[i], next[i+1]);
        }
    }
    int longestStrChain(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
//        unordered_set<string> visited;
        for(auto &s: st) {
            dfs(st, 1, s);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<string> v = {"abcd","dbqca"};
    solution.longestStrChain(v);
    return 0;
}