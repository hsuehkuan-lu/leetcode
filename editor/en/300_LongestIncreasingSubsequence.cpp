//Given an integer array nums, return the length of the longest strictly increas
//ing subsequence. 
//
// A subsequence is a sequence that can be derived from an array by deleting som
//e or no elements without changing the order of the remaining elements. For examp
//le, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7]. 
//
// 
// Example 1: 
//
// 
//Input: nums = [10,9,2,5,3,7,101,18]
//Output: 4
//Explanation: The longest increasing subsequence is [2,3,7,101], therefore the 
//length is 4.
// 
//
// Example 2: 
//
// 
//Input: nums = [0,1,0,3,2,3]
//Output: 4
// 
//
// Example 3: 
//
// 
//Input: nums = [7,7,7,7,7,7,7]
//Output: 1
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 2500 
// -104 <= nums[i] <= 104 
// 
//
// 
// Follow up: 
//
// 
// Could you come up with the O(n2) solution? 
// Could you improve it to O(n log(n)) time complexity? 
// 
// Related Topics Binary Search Dynamic Programming 
// 👍 6625 👎 152


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findLowerBound(vector<int> &v, int target) {
        int left = 0, right = v.size() - 1;
        while(left <= right) {
            int mid = (left + right) >> 1, l = mid > 0 ? v[mid-1] : INT_MIN;
            if(target == v[mid] || (target > l && target < v[mid]))
                return mid;
            else if(target < v[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
    int binarySearchSolution(vector<int> &nums) {
       vector<int> v;
       for(auto &i: nums) {
           int idx = findLowerBound(v, i);
           if(idx >= 0)
               v[idx] = i;
           else {
               v.push_back(i);
           }
       }
       return v.size();
    }
    int dpSolution(vector<int> &nums) {
        if(nums.empty()) return 0;
        vector<int> dp(nums.size(), 1);
        int max_ans = 1;
        for(int i=1; i<nums.size(); ++i) {
            for(int j=0; j<i; ++j) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            max_ans = max(max_ans, dp[i]);
        }
        return max_ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        return binarySearchSolution(nums);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> v = {0,1,0,3,2,3};
    solution.lengthOfLIS(v);
    return 0;
}