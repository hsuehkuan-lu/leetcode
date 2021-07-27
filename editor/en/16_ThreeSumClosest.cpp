//Given an array nums of n integers and an integer target, find three integers i
//n nums such that the sum is closest to target. Return the sum of the three integ
//ers. You may assume that each input would have exactly one solution. 
//
// 
// Example 1: 
//
// 
//Input: nums = [-1,2,1,-4], target = 1
//Output: 2
//Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
// 
//
// 
// Constraints: 
//
// 
// 3 <= nums.length <= 10^3 
// -10^3 <= nums[i] <= 10^3 
// -10^4 <= target <= 10^4 
// 
// Related Topics Array Two Pointers Sorting 
// 👍 3869 👎 192
	

#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0, diff = INT_MAX;
        for(int i=0; i<n-2; ++i) {
            int start = i+1, end = n-1, val = target - nums[i];
            while(start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                if(diff > abs(target - sum)) {
                    diff = abs(target - sum);
                    ans = sum;
                }
                if(sum < target) {
                    ++start;
                } else {
                    --end;
                }
                if(diff == 0) break;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> v = {1,2,-4,-1};
    solution.threeSumClosest(v, 1);
    return 0;
}