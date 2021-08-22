//You are given a network of n nodes, labeled from 1 to n. You are also given ti
//mes, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui 
//is the source node, vi is the target node, and wi is the time it takes for a sig
//nal to travel from source to target. 
//
// We will send a signal from a given node k. Return the time it takes for all t
//he n nodes to receive the signal. If it is impossible for all the n nodes to rec
//eive the signal, return -1. 
//
// 
// Example 1: 
//
// 
//Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
//Output: 2
// 
//
// Example 2: 
//
// 
//Input: times = [[1,2,1]], n = 2, k = 1
//Output: 1
// 
//
// Example 3: 
//
// 
//Input: times = [[1,2,1]], n = 2, k = 2
//Output: -1
// 
//
// 
// Constraints: 
//
// 
// 1 <= k <= n <= 100 
// 1 <= times.length <= 6000 
// times[i].length == 3 
// 1 <= ui, vi <= n 
// ui != vi 
// 0 <= wi <= 100 
// All the pairs (ui, vi) are unique. (i.e., no multiple edges.) 
// 
// Related Topics Depth-First Search Breadth-First Search Graph Heap (Priority Q
//ueue) Shortest Path 
// 👍 3004 👎 256
	

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
#define pii pair<int, int>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto v: times) {
            graph[v[0]-1].push_back({v[1]-1, v[2]});
        }
        priority_queue<pii, vector<pii>, greater<>> min_heap;
        vector<int> dists(n, INT_MAX);
        dists[k-1] = 0;
        min_heap.push({0, k-1});
        vector<bool> visited(n);
        int ans = INT_MIN, cnt = 0;
        while(!min_heap.empty()) {
            auto top = min_heap.top(); min_heap.pop();
            int dist = top.first, u = top.second;
            if(visited[u]) continue;
            visited[u] = true;
            ++cnt;
            for(auto node: graph[u]) {
                int v = node.first, weight = node.second;
                if(dists[v] > dist + weight) {
                    dists[v] = dist + weight;
                    min_heap.push({dists[v], v});
                    ans = max(ans, dists[v]);
                }
            }
        }
        return cnt == n ? ans : -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    solution.networkDelayTime(times, 4, 2);
    return 0;
}