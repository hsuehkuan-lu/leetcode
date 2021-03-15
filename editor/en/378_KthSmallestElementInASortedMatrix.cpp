//Given an n x n matrix where each of the rows and columns are sorted in ascendi
//ng order, return the kth smallest element in the matrix. 
//
// Note that it is the kth smallest element in the sorted order, not the kth dis
//tinct element. 
//
// 
// Example 1: 
//
// 
//Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
//Output: 13
//Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the
// 8th smallest number is 13
// 
//
// Example 2: 
//
// 
//Input: matrix = [[-5]], k = 1
//Output: -5
// 
//
// 
// Constraints: 
//
// 
// n == matrix.length 
// n == matrix[i].length 
// 1 <= n <= 300 
// -109 <= matrix[i][j] <= -109 
// All the rows and columns of matrix are guaranteed to be sorted in non-degreas
//ing order. 
// 1 <= k <= n2 
// 
// Related Topics Binary Search Heap 
// 👍 3409 👎 179


#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int n;
    int minHeapSolution(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<>> pq;
        for(auto &row: matrix)
            for(auto &col: row)
                pq.push(col);
        for(int i=0; i<k-1; ++i) pq.pop();
        return pq.top();
    }
    int getPosition(vector<vector<int>> &matrix, int target, int boundary[]) {
        int row = 0, col = n-1, cnt = 0;
        while(row < n && col >= 0) {
            if(matrix[row][col] <= target) {
                boundary[0] = max(boundary[0], matrix[row][col]);
                cnt += col + 1;
                ++row;
            } else {
                boundary[1] = min(boundary[1], matrix[row][col]);
                --col;
            }
        }
        return cnt;
    }
    int binarySearchSolution(vector<vector<int>> &matrix, int k) {
        int position = 0;
        int left = matrix[0][0], right = matrix[n-1][n-1];
        while(left < right) {
            int mid = (left + right) >> 1;
            int boundary[] = {matrix[0][0], matrix[n-1][n-1]};
            position = getPosition(matrix, mid, boundary);
            if(position == k)
                return boundary[0];
            else if(position > k)
                right = boundary[0];
            else
                left = boundary[1];
        }
        return left;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        n = matrix.size();
        return binarySearchSolution(matrix, k);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    solution.kthSmallest(matrix, 3);
    return 0;
}