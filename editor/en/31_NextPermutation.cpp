//Implement next permutation, which rearranges numbers into the lexicographicall
//y next greater permutation of numbers. 
//
// If such an arrangement is not possible, it must rearrange it as the lowest po
//ssible order (i.e., sorted in ascending order). 
//
// The replacement must be in place and use only constant extra memory. 
//
// 
// Example 1: 
// Input: nums = [1,2,3]
//Output: [1,3,2]
// Example 2: 
// Input: nums = [3,2,1]
//Output: [1,2,3]
// Example 3: 
// Input: nums = [1,1,5]
//Output: [1,5,1]
// Example 4: 
// Input: nums = [1]
//Output: [1]
// 
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 100 
// 0 <= nums[i] <= 100 
// 
// Related Topics Array 
// 👍 5960 👎 1993


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
static int x = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return 0;}();
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1;
        for(int i=nums.size()-1; i>0; --i) {
            if(nums[i] > nums[i-1]) {
                idx = i-1;
                break;
            }
        }
        if(idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int swap_idx = idx+1, lowest_val = nums[swap_idx];
        for(int i=swap_idx+1; i<nums.size(); ++i) {
            if(nums[idx] < nums[i] && lowest_val <= nums[swap_idx]) {
                lowest_val = nums[i];
                swap_idx = i;
            }
        }

        swap(nums[idx], nums[swap_idx]);
        reverse(nums.begin() + idx + 1, nums.end());
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> v = {2,3,1,3,3};
    solution.nextPermutation(v);
    return 0;
}