//Given an m x n binary matrix filled with 0's and 1's, find the largest square 
//containing only 1's and return its area. 
//
// 
// Example 1: 
//
// 
//Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1",
//"1"],["1","0","0","1","0"]]
//Output: 4
// 
//
// Example 2: 
//
// 
//Input: matrix = [["0","1"],["1","0"]]
//Output: 1
// 
//
// Example 3: 
//
// 
//Input: matrix = [["0"]]
//Output: 0
// 
//
// 
// Constraints: 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 300 
// matrix[i][j] is '0' or '1'. 
// 
// Related Topics Dynamic Programming 
// 👍 4466 👎 105


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int optimizeDPSolution(vector<vector<char>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int dp[n+1];
        memset(dp, 0, sizeof dp);
        int max_square = 0, top_left = 0;
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                int tmp = dp[j+1];
                if(matrix[i][j] == '0') {
                    dp[j+1] = 0;
                }
                else {
                    // left = dp[j-1], top = dp[j]
                    dp[j+1] = min(min(dp[j+1], dp[j]), top_left) + 1;
                    max_square = max(max_square, dp[j+1]);
                }
                top_left = tmp;
            }
        }
        return max_square * max_square;
    }
    int dpSolution(vector<vector<char>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int dp[m+1][n+1];
        memset(dp, 0, sizeof dp);
        int max_square = 0;
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(matrix[i][j] == '1') {
                    dp[i+1][j+1] = min(min(dp[i][j+1], dp[i+1][j]), dp[i][j]) + 1;
                    max_square = max(max_square, dp[i+1][j+1]);
                }
            }
        }
        return max_square * max_square;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        return optimizeDPSolution(matrix);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    return 0;
}