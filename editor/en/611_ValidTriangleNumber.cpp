//Given an integer array nums, return the number of triplets chosen from the arr
//ay that can make triangles if we take them as side lengths of a triangle. 
//
// 
// Example 1: 
//
// 
//Input: nums = [2,2,3,4]
//Output: 3
//Explanation: Valid combinations are: 
//2,3,4 (using the first 2)
//2,3,4 (using the second 2)
//2,2,3
// 
//
// Example 2: 
//
// 
//Input: nums = [4,2,3,4]
//Output: 4
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 1000 
// 0 <= nums[i] <= 1000 
// 
// Related Topics Array Two Pointers Binary Search Greedy Sorting 
// 👍 1647 👎 114


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
static int x = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return 0;}();
class Solution {
public:
    int binarySearchSolution(vector<int> &nums) {
        if(nums.size() < 3) return 0;
        int total = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; ++i) {
            for(int j=i+2; j<nums.size(); ++j) {
                int idx = upper_bound(nums.begin()+i+1, nums.begin()+j, nums[j] - nums[i]) - nums.begin();
                total += j - idx;
            }
        }
        return total;
    }
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        int total = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; ++i) {
            int k = i+2;
            for(int j=i+1; j<n-1 && nums[i]!=0; ++j) {
                while(k < n && nums[i] + nums[j] > nums[k])
                    ++k;
                total += k - j - 1;
            }
        }
        return total;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> v = {2,2,3,4};
    solution.triangleNumber(v);
    return 0;
}