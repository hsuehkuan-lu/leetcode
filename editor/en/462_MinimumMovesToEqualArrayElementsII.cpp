//Given an integer array nums of size n, return the minimum number of moves requ
//ired to make all array elements equal. 
//
// In one move, you can increment or decrement an element of the array by 1. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,2,3]
//Output: 2
//Explanation:
//Only two moves are needed (remember each move increments or decrements one ele
//ment):
//[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
// 
//
// Example 2: 
//
// 
//Input: nums = [1,10,2,9]
//Output: 16
// 
//
// 
// Constraints: 
//
// 
// n == nums.length 
// 1 <= nums.length <= 105 
// -109 <= nums[i] <= 109 
// 
// Related Topics Math 
// 👍 788 👎 56


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
static int x = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return 0;}();
class Solution {
public:
    int nsquareSolution(vector<int> &nums) {
        long min_val = INT_MAX;
        for(auto &i: nums) {
            long sum = 0;
            for(auto &j: nums) {
                sum += abs(j - i);
            }
            min_val = min(min_val, sum);
        }
        return (int)min_val;
    }
    int sortSolution(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long min_val = INT_MAX, total = 0, sum = 0;
        for(auto &i: nums) {
            total += i;
        }
        for(int i=0; i<n; ++i) {
            min_val = min(min_val, (((long)nums[i] * i - sum) + (total - (long)nums[i] * (n - i) - sum)));
            sum += nums[i];
        }
        return (int)min_val;
    }
    int minMoves2(vector<int>& nums) {
        return sortSolution(nums);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> v = {1,10,2,9};
    solution.minMoves2(v);
    return 0;
}