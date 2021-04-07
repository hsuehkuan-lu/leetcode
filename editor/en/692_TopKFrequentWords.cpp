//Given a non-empty list of words, return the k most frequent elements. 
// Your answer should be sorted by frequency from highest to lowest. If two word
//s have the same frequency, then the word with the lower alphabetical order comes
// first. 
//
// Example 1: 
// 
//Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
//Output: ["i", "love"]
//Explanation: "i" and "love" are the two most frequent words.
//    Note that "i" comes before "love" due to a lower alphabetical order.
// 
// 
//
// Example 2: 
// 
//Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"]
//, k = 4
//Output: ["the", "is", "sunny", "day"]
//Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
//    with the number of occurrence being 4, 3, 2 and 1 respectively.
// 
// 
//
// Note: 
// 
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements. 
// Input words contain only lowercase letters. 
// 
// 
//
// Follow up: 
// 
// Try to solve it in O(n log k) time and O(n) extra space. 
// 
// Related Topics Hash Table Heap Trie 
// 👍 2873 👎 189


#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_set>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    struct minHeap{
        bool operator() (const pair<string, int> &a, const pair<string, int> &b) const {
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        priority_queue<pair<string, int>, vector<pair<string, int>>, minHeap> q;
        for(auto &w: words) ++mp[w];
        for(auto &m: mp) {
            if(q.size() == k) {
                if(m.second > q.top().second) {
                    q.pop();
                    q.push(make_pair(m.first, m.second));
                }
            } else {
                q.push(make_pair(m.first, m.second));
            }
        }
        vector<string> ans;
        while(!q.empty()) {
            ans.push_back(q.top().first);
            q.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    solution.topKFrequent(words, 2);
    return 0;
}