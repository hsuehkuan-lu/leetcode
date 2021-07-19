//A transformation sequence from word beginWord to word endWord using a dictiona
//ry wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
// 
//
// 
// Every adjacent pair of words differs by a single letter. 
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to
// be in wordList. 
// sk == endWord 
// 
//
// Given two words, beginWord and endWord, and a dictionary wordList, return the
// number of words in the shortest transformation sequence from beginWord to endWo
//rd, or 0 if no such sequence exists. 
//
// 
// Example 1: 
//
// 
//Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot"
//,"log","cog"]
//Output: 5
//Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -
//> "dog" -> cog", which is 5 words long.
// 
//
// Example 2: 
//
// 
//Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot"
//,"log"]
//Output: 0
//Explanation: The endWord "cog" is not in wordList, therefore there is no valid
// transformation sequence.
// 
//
// 
// Constraints: 
//
// 
// 1 <= beginWord.length <= 10 
// endWord.length == beginWord.length 
// 1 <= wordList.length <= 5000 
// wordList[i].length == beginWord.length 
// beginWord, endWord, and wordList[i] consist of lowercase English letters. 
// beginWord != endWord 
// All the words in wordList are unique. 
// 
// Related Topics Hash Table String Breadth-First Search 
// 👍 5468 👎 1457
	

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int n;
public:
    unordered_set<string> findNextString(const unordered_set<string> &set, string &s) {
        unordered_set<string> next_string;
        string tmp = s;
        for(int i=0; i<s.size(); ++i) {
            for(int j=0; j<26; ++j) {
                tmp[i] = 'a' + j;
                if(tmp == s) continue;
                if(set.count(tmp)) {
                    next_string.insert(tmp);
                }
            }
            tmp[i] = s[i];
        }
        return next_string;
    }
//    int bfs(string &bw, string &ew, vector<string> &wl) {
//        // generate graph first
//        unordered_set<string> set(wl.begin(), wl.end());
//        if(!set.count(ew)) return 0;
//        unordered_map<string, unordered_set<string>> mp;
//        mp[bw] = findNextString(set, bw);
//        for(auto &s: wl) {
//            mp[s] = findNextString(set, s);
//        }
//        // bfs to find path
//        unordered_set<string> visited;
//        int ans = 1;
//        queue<string> q;
//        q.push(bw);
//        while(!q.empty()) {
//            queue<string> tmp;
//            while(!q.empty()) {
//                auto front = q.front();
//                q.pop();
//                visited.insert(front);
//                if(mp[front].count(ew)) return ans+1;
//                for(auto &s: mp[front]) {
//                    if(!visited.count(s)) {
//                        tmp.push(s);
//                    }
//                }
//            }
//            q = tmp;
//            ++ans;
//        }
//        return 0;
//    }
    int bfs(string &beginWord, string &endWord, vector<string> &wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());
        if(!set.count(endWord)) return 0;
        int ans = 2;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()) {
            queue<string> tmp;
            while(!q.empty()) {
                auto front = q.front();
                q.pop();
                string s = front;
                for(int i=0; i<s.size(); ++i) {
                    for(int j=0; j<26; ++j) {
                        s[i] = 'a' + j;
                        if(s == front) continue;
                        if(s == endWord) return ans;
                        if(set.count(s)) {
                            tmp.push(s);
                            set.erase(s);
                        }
                    }
                    s[i] = front[i];
                }
            }
            q = tmp;
            ++ans;
        }
        return 0;
    }
    int bidirectionalBFS(string &beginWord, string &endWord, vector<string> &wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());
        if(!set.count(endWord)) return 0;
        int ans = 2;
        // init three sets for start (beginWord), next (middle), end (endWord)
        unordered_set<string> start, next, end;
        start.insert(beginWord);
        end.insert(endWord);
        while(!start.empty()) {
            for(auto &word: start) {
                string tmp = word;
                for(int i=0; i<word.size(); ++i) {
                    for(int j=0; j<26; ++j) {
                        tmp[i] = 'a' + j;
                        if(tmp == word) continue;
                        if(end.count(tmp)) return ans;
                        if(set.count(tmp)) {
                            next.insert(tmp);
                            set.erase(tmp);
                        }
                    }
                    tmp[i] = word[i];
                }
            }
            start = next;
            next.clear();
            if(start.size() > end.size())
                start.swap(end);
            ++ans;
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        return bidirectionalBFS(beginWord, endWord, wordList);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<string> wl = {"hot","dot","dog","lot","log","cog"};
    solution.ladderLength("hit", "cog", wl);
    return 0;
}