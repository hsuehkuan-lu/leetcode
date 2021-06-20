//For an integer array nums, an inverse pair is a pair of integers [i, j] where 
//0 <= i < j < nums.length and nums[i] > nums[j]. 
//
// Given two integers n and k, return the number of different arrays consist of 
//numbers from 1 to n such that there are exactly k inverse pairs. Since the answe
//r can be huge, return it modulo 109 + 7. 
//
// 
// Example 1: 
//
// 
//Input: n = 3, k = 0
//Output: 1
//Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3 has 
//exactly 0 inverse pairs.
// 
//
// Example 2: 
//
// 
//Input: n = 3, k = 1
//Output: 2
//Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 1000 
// 0 <= k <= 1000 
// 
// Related Topics Dynamic Programming 
// 👍 507 👎 86


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
#define MODULO 1000000007
class Solution {
public:
    int OneDDP(int n, int k) {
        if(k == 0) return 1;
//        vector<int> dp(max(n, k) + 1);
//        vector<int> residuals(max(n, k) + 1);
        long dp[max(n, k)+1];
        long residuals[max(n, k)+1];
        memset(dp, 0, sizeof dp);
        memset(residuals, 0, sizeof residuals);
        for(int i=1; i<=n; ++i) {
            dp[0] = residuals[0] = 1;
            for(int j=1; j<=min(k, i * (i-1) / 2); ++j) {
                residuals[j] = dp[j];
                dp[j] = dp[j] + dp[j-1];
                if(j >= i) dp[j] -= residuals[j-i];
                dp[j] = (dp[j] + MODULO) % MODULO;
            }
        }
        return (int) dp[k];
    }
    int optimizedDP(int n, int k) {
        if(k == 0) return 1;
        long dp[n+1][k+1];
        memset(dp, 0, sizeof dp);
        for(int i=1; i<=n; ++i) {
            dp[i][0] = 1;
            for(int j=1; j<=min(k, i * (i-1) / 2); ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                if(j >= i) dp[i][j] -= dp[i-1][j - i];
                dp[i][j] = (dp[i][j] + MODULO) % MODULO;
            }
        }
        return (int) dp[n][k];
    }
    int kInversePairs(int n, int k) {
        return OneDDP(n, k);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    cout << solution.kInversePairs(4, 5);
    return 0;
}