//You are given coins of different denominations and a total amount of money amo
//unt. Write a function to compute the fewest number of coins that you need to mak
//e up that amount. If that amount of money cannot be made up by any combination o
//f the coins, return -1. 
//
// You may assume that you have an infinite number of each kind of coin. 
//
// 
// Example 1: 
//
// 
//Input: coins = [1,2,5], amount = 11
//Output: 3
//Explanation: 11 = 5 + 5 + 1
// 
//
// Example 2: 
//
// 
//Input: coins = [2], amount = 3
//Output: -1
// 
//
// Example 3: 
//
// 
//Input: coins = [1], amount = 0
//Output: 0
// 
//
// Example 4: 
//
// 
//Input: coins = [1], amount = 1
//Output: 1
// 
//
// Example 5: 
//
// 
//Input: coins = [1], amount = 2
//Output: 2
// 
//
// 
// Constraints: 
//
// 
// 1 <= coins.length <= 12 
// 1 <= coins[i] <= 231 - 1 
// 0 <= amount <= 104 
// 
// Related Topics Dynamic Programming 
// 👍 6188 👎 188


#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int dpTopDown(vector<int> &coins, vector<int> &dp, int amount) {
        if(amount < 0) return -1;
        if(amount == 0) return 0;
        if(dp[amount]) return dp[amount];
        int change = INT_MAX;
        for(auto &coin: coins) {
            int result = dpTopDown(coins, dp, amount - coin);
            if(result >= 0) {
                change = min(change, result + 1);
            }
        }
        return dp[amount] = (change > amount) ? -1: change;
    }
    int dpBottomUp(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1);
        fill(dp.begin(), dp.end(), amount + 1);
        dp[0] = 0;
        for(int i=1; i<=amount; ++i) {
            for(auto &coin: coins) {
                if(coin <= i)
                    dp[i] = min(dp[i], dp[i-coin] + 1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
    int topDown(vector<int> &coins, vector<int> &dp, int amount) {
        if(amount < 0) return -1;
        if(amount == 0) return 0;
        if(dp[amount]) return dp[amount];
        int res = INT_MAX;
        for(auto &coin: coins) {
            int local = topDown(coins, dp, amount - coin);
            if(local >= 0)
                res = min(res, local + 1);
        }
        if(res > amount) {
            dp[amount] = -1;
        } else {
            dp[amount] = res;
        }
        return dp[amount];
    }
    int optimizeTopDown(vector<int> &coins, unordered_map<int, int> &dp, int amount) {
        if(amount < 0) return -1;
        if(amount == 0) return 0;
        if(dp[amount]) return dp[amount];
        int change = INT_MAX;
        for(auto &coin: coins) {
            int local = optimizeTopDown(coins, dp, amount - coin);
            if(local >= 0)
                change = min(change, local + 1);
        }
        dp[amount] = (change > amount) ? -1 : change;
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
//        return dpBottomUp(coins, amount);
        sort(coins.begin(), coins.end(), [](const int &a, const int &b){
            return a > b;
        });
        vector<int> dp(amount + 1, 0);
//        unordered_map<int, int> mp;
        return dpTopDown(coins, dp, amount);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> v = {186,419,83,408};
    solution.coinChange(v, 502);
    return 0;
}