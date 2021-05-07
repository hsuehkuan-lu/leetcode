//You are given an m x n grid where each cell can have one of three values: 
//
// 
// 0 representing an empty cell, 
// 1 representing a fresh orange, or 
// 2 representing a rotten orange. 
// 
//
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten o
//range becomes rotten. 
//
// Return the minimum number of minutes that must elapse until no cell has a fre
//sh orange. If this is impossible, return -1. 
//
// 
// Example 1: 
//
// 
//Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
//Output: 4
// 
//
// Example 2: 
//
// 
//Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
//Output: -1
//Explanation: The orange in the bottom left corner (row 2, column 0) is never r
//otten, because rotting only happens 4-directionally.
// 
//
// Example 3: 
//
// 
//Input: grid = [[0,2]]
//Output: 0
//Explanation: Since there are already no fresh oranges at minute 0, the answer 
//is just 0.
// 
//
// 
// Constraints: 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 10 
// grid[i][j] is 0, 1, or 2. 
// 
// Related Topics Breadth-first Search 
// 👍 3323 👎 217


#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int m, n;
    int bfs(vector<vector<int>> &grid) {
        int depth = -1;
        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
        stack<pair<int, int>> S;
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid[i][j] == 2) {
                    S.push({i, j});
                    grid[i][j] = -1;
                }
            }
        }
        while(!S.empty()) {
            stack<pair<int, int>> T;
            while(!S.empty()) {
                auto pos = S.top();
                S.pop();
                for(int i=0; i<4; ++i) {
                    int px = pos.first + dx[i], py = pos.second + dy[i];
                    if(px >= 0 && px < m && py >= 0 && py < n && grid[px][py] == 1) {
                        grid[px][py] = -1;
                        T.push({px, py});
                    }
                }
            }
            S = T;
            ++depth;
        }
        return depth == -1 ? 0 : depth;
    }
    void rotten(vector<vector<int>> &grid, int &depth, stack<pair<int, int>> &S) {
        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
        stack<pair<int, int>> T;
        while(!S.empty()) {
            auto pos = S.top();
            S.pop();
            for(int i=0; i<4; ++i) {
                int px = pos.first + dx[i], py = pos.second + dy[i];
                if(px >= 0 && px < m && py >= 0 && py < n && grid[px][py] == 1) {
                    grid[px][py] = 2;
                    T.push({px, py});
                }
            }
        }
        S = T;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
//        bool is_done = true;
//        for(int i=0; i<m; ++i)
//            for(int j=0; j<n; ++j)
//                if(grid[i][j] == 1) is_done = false;
//        if(is_done) return 0;
        int max_depth = bfs(grid);
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                if(grid[i][j] == 1) return -1;
        return max_depth;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<vector<int>> grid = {{0}};
    solution.orangesRotting(grid);
    return 0;
}