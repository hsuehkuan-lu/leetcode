//A peak element is an element that is strictly greater than its neighbors. 
//
// Given an integer array nums, find a peak element, and return its index. If th
//e array contains multiple peaks, return the index to any of the peaks. 
//
// You may imagine that nums[-1] = nums[n] = -∞. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,2,3,1]
//Output: 2
//Explanation: 3 is a peak element and your function should return the index num
//ber 2. 
//
// Example 2: 
//
// 
//Input: nums = [1,2,1,3,5,6,4]
//Output: 5
//Explanation: Your function can return either index number 1 where the peak ele
//ment is 2, or index number 5 where the peak element is 6. 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 1000 
// -231 <= nums[i] <= 231 - 1 
// nums[i] != nums[i + 1] for all valid i. 
// 
//
// 
//Follow up: Could you implement a solution with logarithmic complexity? Related
// Topics Array Binary Search 
// 👍 2605 👎 2564


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int linearScan(vector<int> &nums) {
        return max_element(nums.begin(), nums.end()) - nums.begin();
    }
    int binarySearch(vector<int> &nums) {
        /*
         * Because nums[i] != nums [i+1] for i in nums.size(),
         * and returned index should be only a valid peak (ignoring the problem of having multiple peaks),
         * so it is viable to apply binary search.
         */
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if((mid == 0 || nums[mid] > nums[mid-1])
                && (mid == nums.size() - 1 || nums[mid] > nums[mid+1]))
                return mid;
            else if(nums[mid] > nums[mid+1])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
    int optimizeBinarySearch(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] > nums[mid+1]) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        return l;
    }
    int findPeakElement(vector<int>& nums) {
        return optimizeBinarySearch(nums);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> v = {1,2,1,3,5,6,4};
    solution.findPeakElement(v);
    return 0;
}