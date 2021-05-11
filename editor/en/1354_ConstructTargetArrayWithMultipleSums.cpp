//Given an array of integers target. From a starting array, A consisting of all 
//1's, you may perform the following procedure : 
//
// 
// let x be the sum of all elements currently in your array. 
// choose index i, such that 0 <= i < target.size and set the value of A at inde
//x i to x. 
// You may repeat this procedure as many times as needed. 
// 
//
// Return True if it is possible to construct the target array from A otherwise 
//return False. 
//
// 
// Example 1: 
//
// 
//Input: target = [9,3,5]
//Output: true
//Explanation: Start with [1, 1, 1] 
//[1, 1, 1], sum = 3 choose index 1
//[1, 3, 1], sum = 5 choose index 2
//[1, 3, 5], sum = 9 choose index 0
//[9, 3, 5] Done
// 
//
// Example 2: 
//
// 
//Input: target = [1,1,1,2]
//Output: false
//Explanation: Impossible to create target array from [1,1,1,1].
// 
//
// Example 3: 
//
// 
//Input: target = [8,5]
//Output: true
// 
//
// 
// Constraints: 
//
// 
// N == target.length 
// 1 <= target.length <= 5 * 10^4 
// 1 <= target[i] <= 10^9 
// 
// Related Topics Greedy 
// 👍 341 👎 48


#include <iostream>
#include <numeric>
#include <vector>
#include <queue>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
static int x = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return 0;}();
class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq(target.begin(), target.end());
        unsigned int sum = 0;
        for(auto &i: target) sum += i;
        while(pq.top() > 1) {
            int num = pq.top();
            pq.pop();
            sum -= num;
            if(num <= sum || sum < 1) return false;
            num %= sum;
            sum += num;
            pq.push(num);
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> v = {1,1,1,2};
    solution.isPossible(v);
    return 0;
}