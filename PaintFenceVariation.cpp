//
// Created by 呂學寬 on 2021/8/9.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(vector<int> &path, int m, int target) {
        if(path.size() < m-1) return true;
        int n = path.size();
        for(int i=0; i<m-1; ++i) {
            if(path[n-i-1] != target) return true;
        }
        return false;
    }
    void dfs(vector<int> &path, int n, int m, int k, int &ans) {
        if(path.size() == n) ++ans;
        else {
            for(int i=0; i<k; ++i) {
                if(isValid(path, m, i)) {
                    path.push_back(i);
                    dfs(path, n, m, k, ans);
                    path.pop_back();
                }
            }
        }
    }
    int dfsSolution(int n, int m, int k) {
        vector<int> path;
        int ans = 0;
        dfs(path, n, m, k, ans);
        return ans;
    }
    int numWays(int n, int m, int k) {
        // n = length, m = limit of consecutive numbers, k = colors
        vector<int> dp(max(n, m));
        int ans = 1;
        for(int i=0; i<m-1; ++i) {
            ans *= k;
            dp[i] = ans;
        }
        if(n < m) return dp[n-1];
        for(int i=m-1; i<n; ++i) {
            for(int j=0; j<m-1; ++j) {
                dp[i] += (k-1) * (dp[i-j-1]);
            }
        }
        return dp[n-1];
    }
};

int main() {
    Solution solution;
    for(int n=1; n<5; ++n) {
        for(int m=1; m<10; ++m) {
            for(int k=1; k<10; ++k) {
                cout << n << " " << m << " " << k << endl;
                int x = solution.dfsSolution(n, m, k), y = solution.numWays(n, m, k);
                cout << x << " " << y << endl;
                assert(x == y);
            }
        }
    }
    return 0;
}

