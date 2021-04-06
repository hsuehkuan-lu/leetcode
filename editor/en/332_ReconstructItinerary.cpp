//You are given a list of airline tickets where tickets[i] = [fromi, toi] repres
//ent the departure and the arrival airports of one flight. Reconstruct the itiner
//ary in order and return it. 
//
// All of the tickets belong to a man who departs from "JFK", thus, the itinerar
//y must begin with "JFK". If there are multiple valid itineraries, you should ret
//urn the itinerary that has the smallest lexical order when read as a single stri
//ng. 
//
// 
// For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["
//JFK", "LGB"]. 
// 
//
// You may assume all tickets form at least one valid itinerary. You must use al
//l the tickets once and only once. 
//
// 
// Example 1: 
//
// 
//Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
//Output: ["JFK","MUC","LHR","SFO","SJC"]
// 
//
// Example 2: 
//
// 
//Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["AT
//L","SFO"]]
//Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
//Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL"
//,"SFO"] but it is larger in lexical order.
// 
//
// 
// Constraints: 
//
// 
// 1 <= tickets.length <= 300 
// tickets[i].length == 2 
// fromi.length == 3 
// toi.length == 3 
// fromi and toi consist of uppercase English letters. 
// fromi != toi 
// 
// Related Topics Depth-first Search Graph 
// 👍 2618 👎 1238


#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void dfs(map<string, multiset<string>> &mp, string &s, vector<string> &path) {
        while(!mp[s].empty()) {
            string next = *mp[s].begin();
            mp[s].erase(mp[s].begin());
            dfs(mp, next, path);
        }
        path.push_back(s);
    }
    vector<string> mapSolution(vector<vector<string>> &tickets) {
        map<string, multiset<string>> mp;
        for(auto &t: tickets) {
            mp[t.front()].insert(t.back());
        }
        string s = "JFK";
        vector<string> path;
        dfs(mp, s, path);
        reverse(path.begin(), path.end());
        return path;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        return mapSolution(tickets);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<vector<string>> tickets = {{"JFK", "SFO"},{"JFK", "ATL"},{"SFO", "ATL"},{"ATL", "JFK"},{"ATL", "SFO"}};
    solution.findItinerary(tickets);
    return 0;
}