//Given an array of integers nums containing n + 1 integers where each integer i
//s in the range [1, n] inclusive. 
//
// There is only one repeated number in nums, return this repeated number. 
//
// 
// Example 1: 
// Input: nums = [1,3,4,2,2]
//Output: 2
// Example 2: 
// Input: nums = [3,1,3,4,2]
//Output: 3
// Example 3: 
// Input: nums = [1,1]
//Output: 1
// Example 4: 
// Input: nums = [1,1,2]
//Output: 1
// 
// 
// Constraints: 
//
// 
// 2 <= n <= 3 * 104 
// nums.length == n + 1 
// 1 <= nums[i] <= n 
// All the integers in nums appear only once except for precisely one integer wh
//ich appears two or more times. 
// 
//
// 
// Follow up: 
//
// 
// How can we prove that at least one duplicate number must exist in nums? 
// Can you solve the problem without modifying the array nums? 
// Can you solve the problem using only constant, O(1) extra space? 
// Can you solve the problem with runtime complexity less than O(n2)? 
// 
// Related Topics Array Two Pointers Binary Search 
// 👍 6984 👎 753


#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int hashSetSolution(vector<int> &nums) {
        unordered_set<int> s;
        for(auto &i: nums) {
            if(s.count(i)) return i;
            s.insert(i);
        }
        return -1;
    }
    int constantSpaceSolution(vector<int> &nums) {
        for(int i=0; i<nums.size(); ++i)
            for(int j=i+1; j<nums.size(); ++j)
                if(nums[i] == nums[j])
                    return nums[i];
        return -1;
    }
    int floydSolution(vector<int> &nums) {
        int slow = nums[0], fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);
        slow = nums[0];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
    int findDuplicate(vector<int>& nums) {
//        return constantSpaceSolution(nums);
//        return hashSetSolution(nums);
        return floydSolution(nums);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> nums = {1,2,3,4,2};
    solution.findDuplicate(nums);
    return 0;
}