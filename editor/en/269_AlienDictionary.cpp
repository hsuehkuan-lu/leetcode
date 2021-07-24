//There is a new alien language that uses the English alphabet. However, the ord
//er among the letters is unknown to you. 
//
// You are given a list of strings words from the alien language's dictionary, w
//here the strings in words are sorted lexicographically by the rules of this new 
//language. 
//
// Return a string of the unique letters in the new alien language sorted in lex
//icographically increasing order by the new language's rules. If there is no solu
//tion, return "". If there are multiple solutions, return any of them. 
//
// A string s is lexicographically smaller than a string t if at the first lette
//r where they differ, the letter in s comes before the letter in t in the alien l
//anguage. If the first min(s.length, t.length) letters are the same, then s is sm
//aller if and only if s.length < t.length. 
//
// 
// Example 1: 
//
// 
//Input: words = ["wrt","wrf","er","ett","rftt"]
//Output: "wertf"
// 
//
// Example 2: 
//
// 
//Input: words = ["z","x"]
//Output: "zx"
// 
//
// Example 3: 
//
// 
//Input: words = ["z","x","z"]
//Output: ""
//Explanation: The order is invalid, so return "".
// 
//
// 
// Constraints: 
//
// 
// 1 <= words.length <= 100 
// 1 <= words[i].length <= 100 
// words[i] consists of only lowercase English letters. 
//
//ological Sort 
// 👍 2702 👎 529
	

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
#define WHITE 0
#define GRAY 1
#define BLACK 2
class Solution {
public:
    bool dfs(unordered_map<char, unordered_set<char>> &graph, unordered_map<char, int> &visited, char cur, string &path) {
        visited[cur] = GRAY;
        for(auto &e: graph[cur]) {
            if(visited[e] == GRAY) return false;
            if(visited[e] == WHITE && !dfs(graph, visited, e, path)) return false;
        }
        path += cur;
        visited[cur] = BLACK;
        return true;
    }
    string dfsSolution(vector<string> &words) {
        // stage 0: init graph
        unordered_map<char, unordered_set<char>> graph;
        for(auto &w: words) {
            for(auto &c: w) {
                if(!graph.count(c)) graph[c] = {};
            }
        }
        // stage 1: build adjacent graph
        for(int i=0; i<words.size()-1; ++i) {
            string words1 = words[i], words2 = words[i+1];
            if(words1.size() > words2.size() && words1.rfind(words2, 0) != string::npos) return "";
            for(int j=0; j<min(words1.size(), words2.size()); ++j) {
                if(words1[j] != words2[j]) {
                    graph[words2[j]].insert(words1[j]);
                    break;
                }
            }
        }
        // stage 2: dfs to find path
        unordered_map<char, int> visited;
        string ans;
        for(auto &e: graph) {
            if(visited[e.first] == WHITE && !dfs(graph, visited, e.first, ans))
                return "";
        }
        return ans;
    }
    string bfsSolution(vector<string> &words) {
        // stage 0: init graph and in_degree
        unordered_map<char, unordered_set<char>> in_degree;
        unordered_map<char, unordered_set<char>> graph;
        for(auto &w: words) {
            for(auto &c: w) {
                if(!in_degree.count(c)) in_degree[c] = {};
                if(!graph.count(c)) graph[c] = {};
            }
        }
        // stage 1: build adjacent graph (bfs puts item ascending)
        for(int i=0; i<words.size()-1; ++i) {
            string word1 = words[i];
            string word2 = words[i+1];
            if(word1.size() > word2.size() && word1.rfind(word2, 0) != string::npos) return "";
            for(int j=0; j<min(word1.size(), word2.size()); ++j) {
                if(word1[j] != word2[j]) {
                    graph[word1[j]].insert(word2[j]);
                    in_degree[word2[j]].insert(word1[j]);
                    break;
                }
            }
        }
        // stage 2: bfs from in_degree = 0 nodes (topological sort)
        queue<char> q;
        for(auto &e: in_degree) {
            if(e.second.empty()) {
                q.push(e.first);
            }
        }
        string ans;
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            ans += front;
            for(auto &c: graph[front]) {
                if(in_degree[c].count(front)) in_degree[c].erase(front);
                if(in_degree[c].empty()) {
                    q.push(c);
                }
            }
        }
        if(ans.size() != in_degree.size()) return "";
        return ans;
    }
    string alienOrder(vector<string>& words) {
        return bfsSolution(words);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<string> w = {"a","b","ca","cc"};
    solution.alienOrder(w);
    return 0;
}