//You are given an array of variable pairs equations and an array of real number
//s values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai 
/// Bi = values[i]. Each Ai or Bi is a string that represents a single variable. 
//
// You are also given some queries, where queries[j] = [Cj, Dj] represents the j
//th query where you must find the answer for Cj / Dj = ?. 
//
// Return the answers to all queries. If a single answer cannot be determined, r
//eturn -1.0. 
//
// Note: The input is always valid. You may assume that evaluating the queries w
//ill not result in division by zero and that there is no contradiction. 
//
// 
// Example 1: 
//
// 
//Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a",
//"c"],["b","a"],["a","e"],["a","a"],["x","x"]]
//Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
//Explanation: 
//Given: a / b = 2.0, b / c = 3.0
//queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
//return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
// 
//
// Example 2: 
//
// 
//Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], 
//queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
//Output: [3.75000,0.40000,5.00000,0.20000]
// 
//
// Example 3: 
//
// 
//Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"]
//,["a","c"],["x","y"]]
//Output: [0.50000,2.00000,-1.00000,-1.00000]
// 
//
// 
// Constraints: 
//
// 
// 1 <= equations.length <= 20 
// equations[i].length == 2 
// 1 <= Ai.length, Bi.length <= 5 
// values.length == equations.length 
// 0.0 < values[i] <= 20.0 
// 1 <= queries.length <= 20 
// queries[i].length == 2 
// 1 <= Cj.length, Dj.length <= 5 
// Ai, Bi, Cj, Dj consist of lower case English letters and digits. 
//
// Shortest Path 
// 👍 3704 👎 289


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    vector<string> match;
public:
    void helper(unordered_map<string, unordered_map<string, double>> &mp, unordered_set<string> &visited,
                vector<string> &path, string cur, string &target) {
        visited.insert(cur);
        path.push_back(cur);
        if(cur == target) {
            match = path;
            return;
        }
        for(auto &m: mp[cur]) {
            if(!visited.count(m.first)) {
                helper(mp, visited, path, m.first, target);
                path.pop_back();
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> mp;
        int n = equations.size();
        for(int i=0; i<n; ++i) {
            mp[equations[i].front()][equations[i].front()] = 1.;
            mp[equations[i].back()][equations[i].back()] = 1.;
            mp[equations[i].front()][equations[i].back()] = values[i];
            mp[equations[i].back()][equations[i].front()] = 1. / values[i];
        }
        // a -> b -> c -> d
        unordered_set<string> visited;
        vector<double> ans;
        vector<string> path;
        for(auto &q: queries) {
            if(mp.find(q.front()) != mp.end() && mp.find(q.back()) != mp.end()) {
                if(mp[q.front()].find(q.back()) != mp[q.front()].end()) {
                    ans.push_back(mp[q.front()][q.back()]);
                } else {
                    visited.clear();
                    path.clear();
                    match.clear();
                    helper(mp, visited, path, q.front(), q.back());
                    if(!match.empty()) {
                        double val = 1.;
                        for(int i=0; i<match.size()-1; ++i) {
                            val *= mp[match[i]][match[i+1]];
                        }
                        ans.push_back(val);
                        mp[q.front()][q.back()] = val;
                        mp[q.back()][q.front()] = 1. / val;
                    } else {
                        ans.push_back(-1);
                    }
                }
            }
            else ans.push_back(-1);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<vector<string>> e = {{"x1","x2"},{"x2","x3"},{"x3","x4"},{"x4","x5"}};
    vector<double> v = {3.0,4.0,5.0,6.0};
    vector<vector<string>> q = {{"x1","x5"},{"x5","x2"},{"x2","x4"},{"x2","x2"},{"x2","x9"},{"x9","x9"}};
    solution.calcEquation(e, v, q);
    return 0;
}