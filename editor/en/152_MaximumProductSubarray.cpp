//Given an integer array nums, find a contiguous non-empty subarray within the a
//rray that has the largest product, and return the product. 
//
// It is guaranteed that the answer will fit in a 32-bit integer. 
//
// A subarray is a contiguous subsequence of the array. 
//
// 
// Example 1: 
//
// 
//Input: nums = [2,3,-2,4]
//Output: 6
//Explanation: [2,3] has the largest product 6.
// 
//
// Example 2: 
//
// 
//Input: nums = [-2,0,-1]
//Output: 0
//Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 2 * 104 
// -10 <= nums[i] <= 10 
// 
// Related Topics Array Dynamic Programming 
// 👍 6366 👎 207


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int constantSpaceDpSolution(vector<int> &nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        int prev_min = nums[0], prev_max = nums[0], max_total = nums[0];
        for(int i=1; i<nums.size(); ++i) {
            int min_val = nums[i] * prev_min;
            int max_val = nums[i] * prev_max;
            prev_min = min(min(min_val, max_val), nums[i]);
            prev_max = max(max(min_val, max_val), nums[i]);
            max_total = max(max_total, prev_max);
        }
        return max_total;
    }

    int dpSolution(vector<int> &nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        vector<int> min_dp(nums.size()), max_dp(nums.size());
        min_dp[0] = max_dp[0] = nums[0];
        int max_total = nums[0];
        for(int i=1; i<nums.size(); ++i) {
            int min_val = nums[i] * min_dp[i-1];
            int max_val = nums[i] * max_dp[i-1];
            min_dp[i] = min(min(min_val, max_val), nums[i]);
            max_dp[i] = max(max(min_val, max_val), nums[i]);
            max_total = max(max_total, max_dp[i]);
        }
        return max_total;
    }

    int bruteForceSolution(vector<int> &nums) {
        if(nums.empty()) return 0;
        int max_val = INT_MIN;
        for(int i=0; i<nums.size(); ++i) {
            int local = nums[i];
            max_val = max(max_val, local);
            for(int j=i+1; j<nums.size(); ++j) {
                local *= nums[j];
                max_val = max(max_val, local);
            }
        }
        return max_val;
    }

    int maxProduct(vector<int>& nums) {
        return constantSpaceDpSolution(nums);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> nums = {2, -1, 1, 1};
    solution.maxProduct(nums);
    return 0;
}