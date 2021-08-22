//
// Created by 呂學寬 on 2021/8/21.
//

#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <stack>

using namespace std;


class Solution {
    int ans = INT_MAX;
    int m, n;
public:
    void dfs(vector<unordered_set<int>> &v, int row, int sum, int target) {
        if(row == m) ans = min(ans, abs(target - sum));
        else {
            for(int num: v[row]) {
                if(abs(target - sum - num) < ans) {
                    dfs(v, row+1, sum+num, target);
                }
            }
        }
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        m = mat.size(), n = mat[0].size();
        vector<unordered_set<int>> v(m);
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                v[i].insert(mat[i][j]);
            }
        }
        dfs(v, 0, 0, target);
        return ans;
    }
};


int main() {
    Solution solution;
//    vector<vector<int>> roads = {{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
//    cout << solution.countPaths(7, roads);
//    cout << solution.numberOfCombinations("24896");
//    vector<vector<int>> mat = {{4,1,2,2,2,1},{1,1,6,5,3,3},{3,9,1,7,10,1},{4,3,1,1,6,10},{2,5,6,8,1,5},{8,9,10,1,5,7}};
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    solution.minimizeTheDifference(mat, 13);
    return 0;
}