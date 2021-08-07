//You have a graph of n nodes labeled from 0 to n - 1. You are given an integer 
//n and a list of edges where edges[i] = [ai, bi] indicates that there is an undir
//ected edge between nodes ai and bi in the graph. 
//
// Return true if the edges of the given graph make up a valid tree, and false o
//therwise. 
//
// 
// Example 1: 
//
// 
//Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
//Output: true
// 
//
// Example 2: 
//
// 
//Input: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
//Output: false
// 
//
// 
// Constraints: 
//
// 
// 1 <= 2000 <= n 
// 0 <= edges.length <= 5000 
// edges[i].length == 2 
// 0 <= ai, bi < n 
// ai != bi 
// There are no self-loops or repeated edges. 
// 
// Related Topics Depth-First Search Breadth-First Search Union Find Graph 
// 👍 1586 👎 46
	

#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    struct Union {
        int rank;
        int parent;
        Union(): rank(0), parent(-1) {};
    };
public:
    bool make_union(int x, int y, vector<Union> &parents) {
        int idx_x = find(x, parents);
        int idx_y = find(y, parents);
        if(idx_x == idx_y) return false;
        auto root_x = parents[idx_x];
        auto root_y = parents[idx_y];
        if(root_x.rank < root_y.rank)
            swap(root_x, root_y);
        parents[idx_y].parent = idx_x;
        ++parents[idx_x].rank;
        return true;
    }
    int find(int x, vector<Union> &parents) {
        if(parents[x].parent == -1) return x;
        return parents[x].parent = find(parents[x].parent, parents);
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        vector<Union> parents(n);
        for(auto &e: edges) {
            if(!make_union(e.front(), e.back(), parents))
                return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<vector<int>> edges = {{0,1},{0,2},{0,3},{1,4}};
    solution.validTree(5, edges);
    return 0;
}