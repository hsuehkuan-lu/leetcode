//Write an efficient algorithm that searches for a value in an m x n matrix. Thi
//s matrix has the following properties: 
//
// 
// Integers in each row are sorted from left to right. 
// The first integer of each row is greater than the last integer of the previou
//s row. 
// 
//
// 
// Example 1: 
//
// 
//Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
//Output: true
// 
//
// Example 2: 
//
// 
//Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
//Output: false
// 
//
// 
// Constraints: 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 100 
// -104 <= matrix[i][j], target <= 104 
// 
// Related Topics Array Binary Search 
// 👍 3008 👎 194


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool reduceSearchSpace(vector<vector<int>> &matrix, int target) {
        /*
         * It is obvious to observe that the matrix is increasing in two directions
         * right and down, while decreasing happens in left and up directions.
         * So an intuition comes from the idea of iteration from right-top or left-bottom.
         */
        int length = matrix.size();
        int m = 0, n = matrix[0].size() - 1;
        while(m < length && n >= 0) {
            if(matrix[m][n] > target)
                --n;
            else if(matrix[m][n] < target)
                ++m;
            else
                return true;
        }
        return false;
    }

    bool recursion(vector<vector<int>> &matrix, vector<vector<bool>> visited, int &target, int ml, int mr, int nl, int nr) {
        if(mr < ml || nr < nl) return false;
        int mid_m = (ml + mr) >> 1, mid_n = (nl + nr) >> 1;
        if(visited[mid_m][mid_n]) return false;
        visited[mid_m][mid_n] = true;
        if(matrix[mid_m][mid_n] == target) return true;
        else if(matrix[mid_m][mid_n] > target) {
            return recursion(matrix, visited, target, ml, mid_m-1, nl, nr) ||
                recursion(matrix, visited, target, ml, mr, nl, mid_n-1);
        } else {
            return recursion(matrix, visited, target, mid_m+1, mr, nl, nr) ||
                   recursion(matrix, visited, target, ml, mr, mid_n+1, nr);
        }
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return reduceSearchSpace(matrix, target);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<vector<int>> v = {{ 1, 3, 5, 7 },{ 10, 11, 16, 20 },{ 23, 30, 34, 60 }};
    solution.searchMatrix(v, 10);
    return 0;
}