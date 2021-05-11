//Given a sorted array of distinct integers and a target value, return the index
// if the target is found. If not, return the index where it would be if it were i
//nserted in order. 
//
// You must write an algorithm with O(log n) runtime complexity. 
//
// 
// Example 1: 
// Input: nums = [1,3,5,6], target = 5
//Output: 2
// Example 2: 
// Input: nums = [1,3,5,6], target = 2
//Output: 1
// Example 3: 
// Input: nums = [1,3,5,6], target = 7
//Output: 4
// Example 4: 
// Input: nums = [1,3,5,6], target = 0
//Output: 0
// Example 5: 
// Input: nums = [1], target = 0
//Output: 0
// 
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 104 
// -104 <= nums[i] <= 104 
// nums contains distinct values sorted in ascending order. 
// -104 <= target <= 104 
// 
// Related Topics Array Binary Search 
// 👍 3509 👎 294


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
static int x = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return 0;}();
class Solution {
public:
    int iterationSolution(vector<int> &nums, int target) {
        int left = 0, right = nums.size();
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    int recursionSolution(vector<int> &nums, int left, int right, const int &target) {
        if(left >= right) return left;
        int mid = left + (right - left) / 2;
        if(nums[mid] < target) return recursionSolution(nums, mid+1, right, target);
        else return recursionSolution(nums, left, mid, target);
    }
    int searchInsert(vector<int>& nums, int target) {
        return recursionSolution(nums, 0, nums.size(), target);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> nums = {1,3,5,7};
    cout << solution.searchInsert(nums, 8);
    return 0;
}