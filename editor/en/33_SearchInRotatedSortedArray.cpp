//There is an integer array nums sorted in ascending order (with distinct values
//). 
//
// Prior to being passed to your function, nums is rotated at an unknown pivot i
//ndex k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+
//1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, 
//[0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2]. 
//
// Given the array nums after the rotation and an integer target, return the ind
//ex of target if it is in nums, or -1 if it is not in nums. 
//
// 
// Example 1: 
// Input: nums = [4,5,6,7,0,1,2], target = 0
//Output: 4
// Example 2: 
// Input: nums = [4,5,6,7,0,1,2], target = 3
//Output: -1
// Example 3: 
// Input: nums = [1], target = 0
//Output: -1
// 
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 5000 
// -104 <= nums[i] <= 104 
// All values of nums are unique. 
// nums is guaranteed to be rotated at some pivot. 
// -104 <= target <= 104 
// 
//
// 
//Follow up: Can you achieve this in O(log n) time complexity? Related Topics Ar
//ray Binary Search 
// 👍 7126 👎 632


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findK(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        if(nums[left] < nums[right])
            return 0;

        while(left <= right) {
            int mid = (left + right) >> 1;
            if(nums[mid] > nums[mid+1])
                return mid+1;
            else if(nums[mid] < nums[left]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return 0;
    }
    int searchWithRotate(vector<int>& nums, int target) {
        int k = findK(nums);
        rotate(nums.begin(), nums.begin() + k, nums.end());
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(nums[mid] == target)
                return (mid + k) % nums.size();
            else if(nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
    int searchWithBinarySearch(vector<int> &nums, int target) {
        /*
         * There are two cases when split the data, so divide the problem into
         * corresponding conditions, and check the target located in which region,
         * then search in that region (right or left)
         */
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] >= nums[right]) {
                if(target < nums[mid] && target >= nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            } else {
                if(target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return searchWithBinarySearch(nums, target);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> v = {6,7,1,2,3,4,5};
    solution.search(v, 6);
    return 0;
}