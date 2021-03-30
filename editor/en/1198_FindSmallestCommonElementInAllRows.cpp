//Given an m x n matrix mat where every row is sorted in strictly increasing ord
//er, return the smallest common element in all rows. 
//
// If there is no common element, return -1. 
//
// 
// Example 1: 
//
// 
//Input: mat = [[1,2,3,4,5],[2,4,5,8,10],[3,5,7,9,11],[1,3,5,7,9]]
//Output: 5
// 
//
// Example 2: 
//
// 
//Input: mat = [[1,2,3],[2,3,4],[2,3,5]]
//Output: 2
// 
//
// 
// Constraints: 
//
// 
// m == mat.length 
// n == mat[i].length 
// 1 <= m, n <= 500 
// 1 <= mat[i][j] <= 104 
// mat[i] is sorted in strictly increasing order. 
// 
// Related Topics Hash Table Binary Search 
// 👍 237 👎 14


#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int mapSolution(vector<vector<int>> &mat) {
        map<int, int> mp;
        int n = mat.size();
        for(auto &row: mat) {
            for(auto &elem: row) ++mp[elem];
        }

        for(auto &m: mp) {
            if(m.second == n) return m.first;
        }
        return -1;
    }
    int optimizeMapSolution(vector<vector<int>> &mat) {
        if(mat.empty()) return -1;
        int mp[10001];
        memset(mp, 0, sizeof(mp));
//        unordered_map<int, int> mp;
        int m = mat.size();
        for(auto &row: mat) {
            for(auto &elem: row)
                if(++mp[elem] == m) return elem;
        }
        return -1;
    }
    int slidingWindowSolution(vector<vector<int>> &mat) {
        if(mat.empty()) return -1;
        int m = mat.size(), n = mat[0].size();
        int indexes[m], min_val = INT_MIN;
        memset(indexes, 0, sizeof(indexes));
        for(int j=0; j<n; ++j) {
            if(mat[0][j] < min_val) continue;
            for(int i=1; i<m; ++i) {
                while(indexes[i] < n && mat[0][indexes[i]] < mat[0][j]) {
                    ++indexes[i];
                }
                if(indexes[i] == n) return -1;
                min_val = max(min_val, mat[i][indexes[i]]);
            }
            if(min_val == mat[0][j]) return min_val;
        }
        return -1;
    }
    int smallestCommonElement(vector<vector<int>>& mat) {
        return optimizeMapSolution(mat);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    return 0;
}