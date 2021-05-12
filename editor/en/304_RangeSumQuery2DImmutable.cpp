//Given a 2D matrix matrix, handle multiple queries of the following type: 
//
// 
// Calculate the sum of the elements of matrix inside the rectangle defined by i
//ts upper left corner (row1, col1) and lower right corner (row2, col2). 
// 
//
// Implement the NumMatrix class: 
//
// 
// NumMatrix(int[][] matrix) Initializes the object with the integer matrix matr
//ix. 
// int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the 
//elements of matrix inside the rectangle defined by its upper left corner (row1, 
//col1) and lower right corner (row2, col2). 
// 
//
// 
// Example 1: 
//
// 
//Input
//["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
//[[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 
//3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
//Output
//[null, 8, 11, 12]
//
//Explanation
//NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 
//0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
//numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
//numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
//
//numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)
// 
//
// 
// Constraints: 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 200 
// -105 <= matrix[i][j] <= 105 
// 0 <= row1 <= row2 < m 
// 0 <= col1 <= col2 < n 
// At most 104 calls will be made to sumRegion. 
// 
// Related Topics Dynamic Programming 
// 👍 1578 👎 211


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class NumMatrix {
    int m, n;
    int **dp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return;
        m = matrix.size(), n = matrix[0].size();
        dp = new int*[m+1];
        for(int i=0; i<=m; ++i) {
            dp[i] = new int[n+1]();
        }
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] - dp[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1] - dp[row1][col2+1] - dp[row2+1][col1] + dp[row1][col1];
    }
};

// using row sum to calculate, it takes O(mn) to build, and O(m) to query.
//class NumMatrix {
//    int **dp;
//public:
//    NumMatrix(vector<vector<int>>& matrix) {
//        if(matrix.empty() || matrix[0].empty()) return;
//        dp = new int*[matrix.size()];
//        for(int i=0; i<matrix.size(); ++i) {
//            dp[i] = new int[matrix[0].size()+1];
//        }
//        for(int i=0; i<matrix.size(); ++i) {
//            for(int j=0; j<matrix[0].size(); ++j) {
//                dp[i][j+1] = dp[i][j] + matrix[i][j];
//            }
//        }
//    }
//
//    int sumRegion(int row1, int col1, int row2, int col2) {
//        int sum = 0;
//        for(int i=row1; i<=row2; ++i) {
//            sum += dp[i][col2 + 1] - dp[i][col1];
//        }
//        return sum;
//    }
//};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    vector<vector<int>> matrix = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
    NumMatrix obj = NumMatrix(matrix);
//    cout << obj.sumRegion(2,1,4,3);
    return 0;
}