//Given an integer array nums of size n, return the minimum number of moves requ
//ired to make all array elements equal. 
//
// In one move, you can increment n - 1 elements of the array by 1. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,2,3]
//Output: 3
//Explanation: Only three moves are needed (remember each move increments two el
//ements):
//[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
// 
//
// Example 2: 
//
// 
//Input: nums = [1,1,1]
//Output: 0
// 
//
// 
// Constraints: 
//
// 
// n == nums.length 
// 1 <= nums.length <= 105 
// -109 <= nums[i] <= 109 
// The answer is guaranteed to fit in a 32-bit integer. 
// 
// Related Topics Math 
// 👍 850 👎 1208


#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
static int x = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return 0;}();
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_val = INT_MAX, sum = 0;
        for(auto &i: nums) {
            sum += i;
            min_val = min(min_val, i);
        }
        return sum - min_val * nums.size();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    return 0;
}