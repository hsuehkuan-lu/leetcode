//Given an integer array nums, reorder it such that nums[0] <= nums[1] >= nums[2
//] <= nums[3].... 
//
// You may assume the input array always has a valid answer. 
//
// 
// Example 1: 
//
// 
//Input: nums = [3,5,2,1,6,4]
//Output: [3,5,1,6,2,4]
//Explanation: [1,6,2,5,3,4] is also accepted.
// 
//
// Example 2: 
//
// 
//Input: nums = [6,6,5,6,3,8]
//Output: [6,6,5,6,3,8]
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 5 * 104 
// 0 <= nums[i] <= 104 
// It is guaranteed that there will be an answer for the given input nums. 
// 
//
// 
//Follow up: Could you do it without sorting the array? Related Topics Array Sor
//t 
// 👍 729 👎 69


 <iostream>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void sortSolution(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), mid = n >> 1;
        for(int i=1; i<nums.size(); i+=2) {
            swap(nums[i], nums[i-1]);
        }
    }
    void linearSolution(vector<int> &nums) {
        for(int i=1; i<nums.size(); ++i) {
            if((i & 1 && nums[i] < nums[i-1]) || (!(i & 1) && nums[i] > nums[i-1]) )
                swap(nums[i], nums[i-1]);
        }
    }
    void wiggleSort(vector<int>& nums) {
        linearSolution(nums);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    return 0;
}