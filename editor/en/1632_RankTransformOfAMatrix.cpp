//Given an m x n matrix, return a new matrix answer where answer[row][col] is th
//e rank of matrix[row][col]. 
//
// The rank is an integer that represents how large an element is compared to ot
//her elements. It is calculated using the following rules: 
//
// 
// The rank is an integer starting from 1. 
// If two elements p and q are in the same row or column, then:
// 
// If p < q then rank(p) < rank(q) 
// If p == q then rank(p) == rank(q) 
// If p > q then rank(p) > rank(q) 
// 
// 
// The rank should be as small as possible. 
// 
//
// It is guaranteed that answer is unique under the given rules. 
//
// 
// Example 1: 
//
// 
//Input: matrix = [[1,2],[3,4]]
//Output: [[1,2],[2,3]]
//Explanation:
//The rank of matrix[0][0] is 1 because it is the smallest integer in its row an
//d column.
//The rank of matrix[0][1] is 2 because matrix[0][1] > matrix[0][0] and matrix[0
//][0] is rank 1.
//The rank of matrix[1][0] is 2 because matrix[1][0] > matrix[0][0] and matrix[0
//][0] is rank 1.
//The rank of matrix[1][1] is 3 because matrix[1][1] > matrix[0][1], matrix[1][1
//] > matrix[1][0], and both matrix[0][1] and matrix[1][0] are rank 2.
// 
//
// Example 2: 
//
// 
//Input: matrix = [[7,7],[7,7]]
//Output: [[1,1],[1,1]]
// 
//
// Example 3: 
//
// 
//Input: matrix = [[20,-21,14],[-19,4,19],[22,-47,24],[-19,4,19]]
//Output: [[4,2,3],[1,3,4],[5,1,6],[1,3,4]]
// 
//
// Example 4: 
//
// 
//Input: matrix = [[7,3,6],[1,4,5],[9,8,2]]
//Output: [[5,1,4],[1,2,3],[6,3,1]]
// 
//
// 
// Constraints: 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 500 
// -109 <= matrix[row][col] <= 109 
// 
// Related Topics Array Greedy Union Find Graph Topological Sort Matrix 
// 👍 468 👎 28
	

#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)

class UnionFind {
    vector<int> parents;
    vector<int> ranks;
public:
    UnionFind(int size) {
        parents.resize(size, -1);
        ranks.resize(size, 0);
    }

    int find(int x) {
        if(parents[x] == -1) return x;
        return parents[x] = find(parents[x]);
    }

    bool make_union(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        if(root_a == root_b) return false;
        if(ranks[root_a] > ranks[root_b])
            parents[root_b] = parents[root_a];
        else if(ranks[root_b] > ranks[root_a])
            parents[root_a] = parents[root_b];
        else {
            parents[root_b] = parents[root_a];
            ++ranks[root_a];
        }
        return true;
    }
};

class Solution {
    int m, n;
    vector<int> row_max, col_max;
public:
    void dfs(unordered_set<int> &rowcols, int rowcol, unordered_map<int, vector<int>> &neighbors) {
        if(rowcols.count(rowcol)) return;
        rowcols.insert(rowcol);
        for(auto &neighbor: neighbors[rowcol]) {
            dfs(rowcols, neighbor, neighbors);
        }
    }
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        row_max.resize(m);
        col_max.resize(n);
        // step 1: build graph for row column
        // use complement number to flatten 2-d array
        // row is positive, col is complement
        // ~0 = -1, so as avoid duplicate key by simply use negative
        unordered_map<int, unordered_map<int, vector<int>>> mp;
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                int val = matrix[i][j];
                mp[val][i].push_back(~j);
                mp[val][~j].push_back(i);
            }
        }
        // step 2: build adjacent index sort by value
        vector<vector<int>> ans(m, vector<int>(n));
        map<int, vector<vector<pair<int, int>>>> graph;
        vector<vector<bool>> visited(m, vector<bool>(n));
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(!visited[i][j]) {
                    visited[i][j] = true;
                    unordered_set<int> rowcols;
                    int val = matrix[i][j];
                    auto &neighbors = mp[val];
                    dfs(rowcols, i, neighbors);
                    dfs(rowcols, ~j, neighbors);
                    vector<pair<int, int>> path;
                    for(int rowcol: rowcols) {
                        for(int pos: neighbors[rowcol]) {
                            if(rowcol >= 0) {
                                path.emplace_back(rowcol, ~pos);
                                visited[rowcol][~pos] = true;
                            } else {
                                path.emplace_back(pos, ~rowcol);
                                visited[pos][~rowcol] = true;
                            }
                        }
                    }
                    graph[val].push_back(path);
                }
            }
        }
        // step 3: iteratively update rank with value
        for(auto &ele: graph) {
            for(vector<pair<int, int>> &group: ele.second) {
                int rank = 1;
                for(auto pos: group) {
                    rank = max(rank, max(row_max[pos.first], col_max[pos.second]) + 1);
                }
                for(auto pos: group) {
                    ans[pos.first][pos.second] = rank;
                    row_max[pos.first] = col_max[pos.second] = rank;
                }
            }
        }
        return ans;
    }
};




//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    cout << ~0;
    return 0;
}