//Given a string S, check if the letters can be rearranged so that two character
//s that are adjacent to each other are not the same. 
//
// If possible, output any possible result. If not possible, return the empty st
//ring. 
//
// Example 1: 
//
// 
//Input: S = "aab"
//Output: "aba"
// 
//
// Example 2: 
//
// 
//Input: S = "aaab"
//Output: ""
// 
//
// Note: 
//
// 
// S will consist of lowercase letters and have length in range [1, 500]. 
// 
//
// 
// Related Topics String Heap Greedy Sort 
// 👍 2736 👎 131


#include <iostream>
#include <queue>
#include <string>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    struct qCompare {
        bool operator() (const pair<char, int> &a, const pair<char, int> &b) const {
            return a.second < b.second;
        }
    };
    string maxFirstSolution(string S) {
        int arr[26], max_len = 0;
        memset(arr, 0, sizeof(arr));
        for(auto &ch: S) {
            max_len = max(max_len, ++arr[ch - 'a']);
        }
        int n = S.size();
        if(max_len > ((n + (n&1)) >> 1)) return "";
        priority_queue<pair<char, int>, vector<pair<char, int>>, qCompare> q;
        for(int i=0; i<26; ++i)
            if(arr[i] > 0) {
                q.push(make_pair('a' + i, arr[i]));
            }
        string ans;
        while(q.size() >= 2) {
            auto p1 = q.top();
            q.pop();
            auto p2 = q.top();
            q.pop();
            ans += p1.first;
            ans += p2.first;
            if(--p1.second > 0) q.push(p1);
            if(--p2.second > 0) q.push(p2);
        }
        if(!q.empty()) ans += q.top().first;
        return ans;
    }
    string reorganizeString(string S) {
        return maxFirstSolution(S);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    solution.reorganizeString("aab");
    return 0;
}