//You are given an array of positive integers nums and want to erase a subarray 
//containing unique elements. The score you get by erasing the subarray is equal t
//o the sum of its elements. 
//
// Return the maximum score you can get by erasing exactly one subarray. 
//
// An array b is called to be a subarray of a if it forms a contiguous subsequen
//ce of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r). 
//
// 
// Example 1: 
//
// 
//Input: nums = [4,2,4,5,6]
//Output: 17
//Explanation: The optimal subarray here is [2,4,5,6].
// 
//
// Example 2: 
//
// 
//Input: nums = [5,2,1,2,5,2,1,2,5]
//Output: 8
//Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 105 
// 1 <= nums[i] <= 104 
// 
// Related Topics Two Pointers 
// 👍 365 👎 8


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
static int x = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return 0;}();
class Solution {
public:
//    int nsquareSolution(vector<int> &nums) {
//        int n = nums.size(), max_val = INT_MIN;
//        for(int i=0; i<n; ++i) {
//            unordered_set<int> s;
//            int sum = 0;
//            for(int j=i; j<n; ++j) {
//                if(s.count(nums[j])) break;
//                sum += nums[j];
//                s.insert(nums[j]);
//            }
//            max_val = max(max_val, sum);
//        }
//        return max_val;
//    }
    int twoPointerSolution(vector<int> &nums) {
        unordered_map<int, int> mp;
        int n = nums.size(), left = 0, right = 0, sum = 0, max_val = INT_MIN;
        while(right < n) {
            if(mp.count(nums[right])) {
                for(; left<=mp[nums[right]]; ++left) {
                    sum -= nums[left];
                }
            }
            mp[nums[right]] = right;
            sum += nums[right];
            max_val = max(max_val, sum);
            ++right;
        }
        return max_val;
    }
    int maximumUniqueSubarray(vector<int>& nums) {
        return twoPointerSolution(nums);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> v = {5,2,1,2,5,2,1};
    solution.maximumUniqueSubarray(v);
    return 0;
}