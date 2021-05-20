//In an infinite chess board with coordinates from -infinity to +infinity, you h
//ave a knight at square [0, 0]. 
//
// A knight has 8 possible moves it can make, as illustrated below. Each move is
// two squares in a cardinal direction, then one square in an orthogonal direction
//. 
//
// 
//
// Return the minimum number of steps needed to move the knight to the square [x
//, y]. It is guaranteed the answer exists. 
//
// 
// Example 1: 
//
// 
//Input: x = 2, y = 1
//Output: 1
//Explanation: [0, 0] → [2, 1]
// 
//
// Example 2: 
//
// 
//Input: x = 5, y = 5
//Output: 4
//Explanation: [0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]
// 
//
// 
// Constraints: 
//
// 
// |x| + |y| <= 300 
// 
// Related Topics Breadth-first Search 
// 👍 590 👎 230


#include <iostream>
#include <stack>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
//class Solution {
//public:
//    int dpSolution(int x, int y, vector<vector<int>> &dp) {
//        if(x + y == 0) return 0;
//        else if(x + y == 2) return 2;
//        if(dp[x][y]) return dp[x][y];
//        dp[x][y] = min(dpSolution(abs(x-1), abs(y-2), dp) + 1, dpSolution(abs(x-2), abs(y-1), dp) + 1);
//        return dp[x][y];
//    }
//    int minKnightMoves(int x, int y) {
//        int sz = max(abs(x), abs(y));
//        vector<vector<int>> dp(sz+1, vector<int>(sz+1, 0));
//        return dpSolution(abs(x), abs(y), dp);
//    }
//};
class Solution {
    vector<vector<int>> dp;
public:
    int dpSolution(int x, int y) {
        if(x + y == 0) return 0;
        else if(x + y == 2) return 2;
        if(dp[x][y]) return dp[x][y];
        dp[x][y] = 1 + min(dpSolution(abs(x-2), abs(y-1)), dpSolution(abs(x-1), abs(y-2)));
        return dp[x][y];
    }
    int minKnightMoves(int x, int y) {
        x = abs(x), y = abs(y);
        dp.resize(max(x, y)+1, vector<int>(max(x, y)+1, 0));
        return dpSolution(x, y);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    cout << solution.minKnightMoves(0, 1);
    return 0;
}