//There are n houses in a village. We want to supply water for all the houses by
// building wells and laying pipes. 
//
// For each house i, we can either build a well inside it directly with cost wel
//ls[i - 1] (note the -1 due to 0-indexing), or pipe in water from another well to
// it. The costs to lay pipes between houses are given by the array pipes, where e
//ach pipes[j] = [house1j, house2j, costj] represents the cost to connect house1j 
//and house2j together using a pipe. Connections are bidirectional. 
//
// Return the minimum total cost to supply water to all houses. 
//
// 
// Example 1: 
//
// 
//
// 
//Input: n = 3, wells = [1,2,2], pipes = [[1,2,1],[2,3,1]]
//Output: 3
//Explanation: 
//The image shows the costs of connecting houses using pipes.
//The best strategy is to build a well in the first house with cost 1 and connec
//t the other houses to it with cost 2 so the total cost is 3.
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 104 
// wells.length == n 
// 0 <= wells[i] <= 105 
// 1 <= pipes.length <= 104 
// pipes[j].length == 3 
// 1 <= house1j, house2j <= n 
// 0 <= costj <= 105 
// house1j != house2j 
// 
// Related Topics Union Find Graph Minimum Spanning Tree 
// 👍 542 👎 22
	

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)


class UnionFind {
    vector<int> parents;
    vector<int> ranks;
public:
    UnionFind(int size) {
        parents.resize(size+1, -1);
        ranks.resize(size+1, 0);
    }
    int find(int node) {
        if(parents[node] == -1) return node;
        // path compression
        return parents[node] = find(parents[node]);
    }
    bool make_union(int node_a, int node_b) {
        int root_a = find(node_a);
        int root_b = find(node_b);
        if(root_a == root_b) return false;
        if(ranks[root_a] > ranks[root_b])
            parents[root_b] = root_a;
        else if(ranks[root_b] > ranks[root_a])
            parents[root_a] = root_b;
        else {
            parents[root_b] = root_a;
            ++ranks[root_a];
        }
        return true;
    }
};

class Solution {
    bool sortbylast(vector<int> &a, vector<int> &b) {
        return a.back() < b.back();
    }
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        for(int i=0; i<wells.size(); ++i) {
            pipes.push_back({0, i+1, wells[i]});
        }
        sort(pipes.begin(), pipes.end(), [](vector<int> &a, vector<int> &b) {return a.back() < b.back();});
        UnionFind uf(n);
        int cost = 0;
        for(auto &pipe: pipes) {
            if(uf.make_union(pipe[0], pipe[1])) {
                cost += pipe[2];
            }
        }
        return cost;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    return 0;
}