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
// Given two words, beginWord and endWord, and a dictionary wordList, return all
// the shortest transformation sequences from beginWord to endWord, or an empty li
//st if no such sequence exists. Each sequence should be returned as a list of the
// words [beginWord, s1, s2, ..., sk]. 
//
// 
// Example 1: 
//
// 
//Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot"
//,"log","cog"]
//Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
//Explanation: There are 2 shortest transformation sequences:
//"hit" -> "hot" -> "dot" -> "dog" -> "cog"
//"hit" -> "hot" -> "lot" -> "log" -> "cog"
// 
//
// Example 2: 
//
// 
//Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot"
//,"log"]
//Output: []
//Explanation: The endWord "cog" is not in wordList, therefore there is no valid
// transformation sequence.
// 
//
// 
// Constraints: 
//
// 
// 1 <= beginWord.length <= 5 
// endWord.length == beginWord.length 
// 1 <= wordList.length <= 1000 
// wordList[i].length == beginWord.length 
// beginWord, endWord, and wordList[i] consist of lowercase English letters. 
// beginWord != endWord 
// All the words in wordList are unique. 
// 
// Related Topics Hash Table String Backtracking Breadth-First Search 
// 👍 2777 👎 305
	

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int max_depth;
    vector<vector<string>> ans;
public:
    vector<string> findNeighbors(unordered_set<string> &set, string cur) {
        vector<string> neighbors;
        string s = cur;
        for(int i=0; i<cur.size(); ++i) {
            for(int j=0; j<26; ++j) {
                s[i] = 'a' + j;
                if(s == cur) continue;
                if(set.count(s)) neighbors.push_back(s);
            }
            s[i] = cur[i];
        }
        return neighbors;
    }
    // function is to add next connected nodes
    void addEdge(string &word1, string &word2, int dir, unordered_map<string, vector<string>> &graph) {
        if(dir) {
            graph[word1].push_back(word2);
        } else {
            graph[word2].push_back(word1);
        }
    }
    void dfs(unordered_map<string, vector<string>> &graph, string cur, string endWord, vector<string> &path, int depth) {
        // truncate solutions to depth lower than max_depth (obtained from BFS)
        if(depth >= max_depth) return;
        path.push_back(cur);
        if(path.size() == max_depth) {
            if(cur == endWord) {
                ans.push_back(path);
            }
        } else {
            for(auto &edge: graph[cur]) {
                dfs(graph, edge, endWord, path, depth+1);
            }
        }
        path.pop_back();
    }
    bool bfs(string &beginWord, string &endWord, unordered_set<string> &set, unordered_map<string, vector<string>> &graph) {
        bool found = false;
        unordered_set<string> start, next, end;
        start.insert(beginWord);
        set.erase(beginWord);
        end.insert(endWord);
        max_depth = 2;
        int dir = 1;
        while(!start.empty()) {
            // record visited nodes in the same layer
            unordered_set<string> visited;
            for(string e: start) {
                visited.insert(e);
                vector<string> neighbors = findNeighbors(set, e);
                for(auto &neighbor: neighbors) {
                    // if solution is found in the next layer, save the results and graph
                    if(end.count(neighbor)) {
                        addEdge(e, neighbor, dir, graph);
                        found = true;
                    }
                    // exclude nodes in the following conditions:
                    // 1. Previously visited nodes (shortest path first)
                    // 2. Nodes in the same layers (avoid recursively traverse)
                    else if(set.count(neighbor) && !visited.count(neighbor) && !start.count(neighbor)) {
                        addEdge(e, neighbor, dir, graph);
                        next.insert(neighbor);
                    }
                }
            }
            // if solution is found in the layer, then return true
            if(found) return found;
            for(auto &s: start) {
                if(set.count(s)) set.erase(s);
            }
            swap(start, next);
            next.clear();
            if(start.size() > end.size()) {
                dir ^= 1;
                swap(start, end);
            }
            ++max_depth;
        }
        return found;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // stage 1: init word set
        unordered_set<string> set(wordList.begin(), wordList.end());
        if(!set.count(endWord)) return {};
        // stage 2: bidirectional bfs to build graph
        unordered_map<string, vector<string>> graph;
        bool found = bfs(beginWord, endWord, set, graph);
        if(!found) return {};
        // stage 3: dfs backtracking to find all matched paths
        vector<string> path;
        dfs(graph, beginWord, endWord, path, 0);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<string> wl = {"dose","ends","dine","jars","prow","soap","guns","hops","cray","hove","ella","hour","lens","jive","wiry","earl","mara","part","flue","putt","rory","bull","york","ruts","lily","vamp","bask","peer","boat","dens","lyre","jets","wide","rile","boos","down","path","onyx","mows","toke","soto","dork","nape","mans","loin","jots","male","sits","minn","sale","pets","hugo","woke","suds","rugs","vole","warp","mite","pews","lips","pals","nigh","sulk","vice","clod","iowa","gibe","shad","carl","huns","coot","sera","mils","rose","orly","ford","void","time","eloy","risk","veep","reps","dolt","hens","tray","melt","rung","rich","saga","lust","yews","rode","many","cods","rape","last","tile","nosy","take","nope","toni","bank","jock","jody","diss","nips","bake","lima","wore","kins","cult","hart","wuss","tale","sing","lake","bogy","wigs","kari","magi","bass","pent","tost","fops","bags","duns","will","tart","drug","gale","mold","disk","spay","hows","naps","puss","gina","kara","zorn","boll","cams","boas","rave","sets","lego","hays","judy","chap","live","bahs","ohio","nibs","cuts","pups","data","kate","rump","hews","mary","stow","fang","bolt","rues","mesh","mice","rise","rant","dune","jell","laws","jove","bode","sung","nils","vila","mode","hued","cell","fies","swat","wags","nate","wist","honk","goth","told","oise","wail","tels","sore","hunk","mate","luke","tore","bond","bast","vows","ripe","fond","benz","firs","zeds","wary","baas","wins","pair","tags","cost","woes","buns","lend","bops","code","eddy","siva","oops","toed","bale","hutu","jolt","rife","darn","tape","bold","cope","cake","wisp","vats","wave","hems","bill","cord","pert","type","kroc","ucla","albs","yoko","silt","pock","drub","puny","fads","mull","pray","mole","talc","east","slay","jamb","mill","dung","jack","lynx","nome","leos","lade","sana","tike","cali","toge","pled","mile","mass","leon","sloe","lube","kans","cory","burs","race","toss","mild","tops","maze","city","sadr","bays","poet","volt","laze","gold","zuni","shea","gags","fist","ping","pope","cora","yaks","cosy","foci","plan","colo","hume","yowl","craw","pied","toga","lobs","love","lode","duds","bled","juts","gabs","fink","rock","pant","wipe","pele","suez","nina","ring","okra","warm","lyle","gape","bead","lead","jane","oink","ware","zibo","inns","mope","hang","made","fobs","gamy","fort","peak","gill","dino","dina","tier"};
    solution.findLadders("nape", "mild", wl);
    return 0;
}