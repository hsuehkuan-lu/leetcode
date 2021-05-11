//You have a graph of n nodes. You are given an integer n and an array edges whe
//re edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the 
//graph. 
//
// Return the number of connected components in the graph. 
//
// 
// Example 1: 
//
// 
//Input: n = 5, edges = [[0,1],[1,2],[3,4]]
//Output: 2
// 
//
// Example 2: 
//
// 
//Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
//Output: 1
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 2000 
// 1 <= edges.length <= 5000 
// edges[i].length == 2 
// 0 <= ai <= bi < n 
// ai != bi 
// There are no repeated edges. 
// 
// Related Topics Depth-first Search Breadth-first Search Union Find Graph 
// 👍 1238 👎 37


#include <iostream>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
static int x = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return 0;}();
class Solution {
    vector<vector<int>> v;
//    unordered_map<int, vector<int>> mp;
    vector<bool> visited;
    vector<int> parents;
public:
    void helper(const int &val) {
        for(auto &e: v[val]) {
            if(!visited[e]) {
                visited[e] = true;
                helper(e);
            }
        }
    }
    int dfsSolution(int n, vector<vector<int>> &edges) {
        v.resize(n, vector<int>());
        visited.resize(n, false);
        for(auto &e: edges) {
            v[e[0]].push_back(e[1]);
            v[e[1]].push_back(e[0]);
        }
        int ans = 0;
        for(int i=0; i<n; ++i) {
            if(!visited[i]) {
                helper(i);
                ++ans;
            }
        }
        return ans;
    }
    int find(int val) {
        while(val != parents[val])
            val = parents[val];
        return val;
    }
    int unionFindSolution(int n, vector<vector<int>> &edges) {
        parents.resize(n);
        iota(parents.begin(), parents.end(), 0);
        for(auto &e: edges) {
            parents[find(e[0])] = find(e[1]);
        }
        int cnt = 0;
        for(int i=0; i<n; ++i)
            if(parents[i] == i) ++cnt;
        return n;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
//        return dfsSolution(n, edges);
        return unionFindSolution(n, edges);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<vector<int>> edges = {{0, 1},{1, 2},{2, 3},{3, 4}};
    solution.countComponents(5, edges);
    return 0;
}