//Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (r
//epresenting land) connected 4-directionally (horizontal or vertical.) You may as
//sume all four edges of the grid are surrounded by water. 
//
// Find the maximum area of an island in the given 2D array. (If there is no isl
//and, the maximum area is 0.) 
//
// Example 1: 
//
// 
//[[0,0,1,0,0,0,0,1,0,0,0,0,0],
// [0,0,0,0,0,0,0,1,1,1,0,0,0],
// [0,1,1,0,1,0,0,0,0,0,0,0,0],
// [0,1,0,0,1,1,0,0,1,0,1,0,0],
// [0,1,0,0,1,1,0,0,1,1,1,0,0],
// [0,0,0,0,0,0,0,0,0,0,1,0,0],
// [0,0,0,0,0,0,0,1,1,1,0,0,0],
// [0,0,0,0,0,0,0,1,1,0,0,0,0]]
// 
//Given the above grid, return 6. Note the answer is not 11, because the island 
//must be connected 4-directionally.
//
// Example 2: 
//
// 
//[[0,0,0,0,0,0,0,0]] 
//Given the above grid, return 0.
//
// Note: The length of each dimension in the given grid does not exceed 50. 
// Related Topics Array Depth-first Search 
// 👍 2898 👎 100


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int m, n, area;
    void dfs(vector<vector<int>> &grid, int x, int y) {
        int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
        grid[x][y] = 0;
        for(int i=0; i<4; ++i) {
            int px = x + dx[i], py = y + dy[i];
            if(px >= 0 && px < m && py >= 0 && py < n && grid[px][py] == 1) {
                dfs(grid, px, py);
            }
        }
        ++area;
    }
    int dfsSolution(vector<vector<int>> &grid) {
        if(grid.empty()) return 0;
        m = grid.size(), n = grid[0].size();
        int max_area = 0;
        for(int i=0; i<grid.size(); ++i) {
            for(int j=0; j<grid[0].size(); ++j) {
                if(grid[i][j] == 1) {
                    area = 0;
                    dfs(grid, i, j);
                    max_area = max(max_area, area);
                }
            }
        }
        return max_area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        return dfsSolution(grid);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<vector<int>> grid = {{1,1,0,0},{1,1,0,0},{0,0,1,0},{0,0,0,1}};
    solution.maxAreaOfIsland(grid);
    return 0;
}