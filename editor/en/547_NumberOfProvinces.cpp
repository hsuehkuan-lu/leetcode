//There are n cities. Some of them are connected, while some are not. If city a 
//is connected directly with city b, and city b is connected directly with city c,
// then city a is connected indirectly with city c. 
//
// A province is a group of directly or indirectly connected cities and no other
// cities outside of the group. 
//
// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the 
//ith city and the jth city are directly connected, and isConnected[i][j] = 0 othe
//rwise. 
//
// Return the total number of provinces. 
//
// 
// Example 1: 
//
// 
//Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
//Output: 2
// 
//
// Example 2: 
//
// 
//Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
//Output: 3
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 200 
// n == isConnected.length 
// n == isConnected[i].length 
// isConnected[i][j] is 1 or 0. 
// isConnected[i][i] == 1 
// isConnected[i][j] == isConnected[j][i] 
// 
// Related Topics Depth-first Search Union Find 
// 👍 2883 👎 177


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int n;
    void dfs(vector<vector<int>> &isConnected, int x, bool visited[]) {
        visited[x] = true;
        for(int i=0; i<n; ++i) {
            if(i == x) continue;
            if(!visited[i] && isConnected[x][i]) {
                dfs(isConnected, i, visited);
            }
        }
    }
    int dfsSolution(vector<vector<int>> &isConnected) {
        bool visited[n];
        memset(visited, false, sizeof(visited));
        int num = 0;
        for(int i=0; i<n; ++i) {
            if(!visited[i]) {
                dfs(isConnected, i, visited);
                ++num;
            }
        }
        return num;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        if(isConnected.empty()) return 0;
        n = isConnected.size();
        return dfsSolution(isConnected);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<vector<int>> matrix = {{1,1,0},{1,1,0},{0,0,1}};
    solution.findCircleNum(matrix);
    return 0;
}