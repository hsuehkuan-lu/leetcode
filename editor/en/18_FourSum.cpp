//Given an array nums of n integers, return an array of all the unique quadruple
//ts [nums[a], nums[b], nums[c], nums[d]] such that: 
//
// 
// 0 <= a, b, c, d < n 
// a, b, c, and d are distinct. 
// nums[a] + nums[b] + nums[c] + nums[d] == target 
// 
//
// You may return the answer in any order. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,0,-1,0,-2,2], target = 0
//Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// 
//
// Example 2: 
//
// 
//Input: nums = [2,2,2,2,2], target = 8
//Output: [[2,2,2,2]]
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 200 
// -109 <= nums[i] <= 109 
// -109 <= target <= 109 
// 
// Related Topics Array Two Pointers Sorting 
// 👍 3826 👎 456


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int n;
public:
    vector<vector<int>> twoSum(vector<int> &nums, int target, int start) {
        vector<vector<int>> ans;
        int l=start, r=n-1;
        while(l < r) {
            if(nums[l] + nums[r] == target) {
                ans.push_back({nums[l], nums[r]});
                while(l < n-1 && nums[l] == nums[l+1])
                    ++l;
                ++l, --r;
            } else if(nums[l] + nums[r] < target) {
                ++l;
            } else {
                --r;
            }
        }
        return ans;
    }
    vector<vector<int>> kSum(vector<int> &nums, int target, int k, int start) {
        n = nums.size();
        vector<vector<int>> ans;
        if(start == nums.size() || nums[start] * k > target || nums.back() * k < target) return ans;
        if(k == 2) return twoSum(nums, target, start);
        else {
            for(int i=start; i<nums.size(); ++i) {
                if(i == start || nums[i] != nums[i-1])
                    for(auto &sub_ans: kSum(nums, target - nums[i], k-1, i+1)) {
                        ans.push_back({nums[i]});
                        ans.back().insert(ans.back().end(), sub_ans.begin(), sub_ans.end());
                    }
            }
        }
        return ans;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 4, 0);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> nums = {1,0,-1,0,-2,2};
    solution.fourSum(nums, 0);
    return 0;
}