//Given an array nums of size n, return the majority element. 
//
// The majority element is the element that appears more than ⌊n / 2⌋ times. You
// may assume that the majority element always exists in the array. 
//
// 
// Example 1: 
// Input: nums = [3,2,3]
//Output: 3
// Example 2: 
// Input: nums = [2,2,1,1,1,2,2]
//Output: 2
// 
// 
// Constraints: 
//
// 
// n == nums.length 
// 1 <= n <= 5 * 104 
// -231 <= nums[i] <= 231 - 1 
// 
//
// 
//Follow-up: Could you solve the problem in linear time and in O(1) space? Relat
//ed Topics Array Divide and Conquer Bit Manipulation 
// 👍 4690 👎 254


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countInRange(vector<int> &nums, int num, int left, int right) {
        int cnt = 0;
        for(int i=left; i<=right; ++i)
            if(nums[i] == num) ++cnt;
        return cnt;
    }
    int divideAndConquerSolution(vector<int> & nums, int left, int right) {
        /*
         * NOTE: Same as the idea of merge-sort!
         * Borrow the idea of divide and conquer, split tasks into left and right parts.
         * If task(left) == task(right) -> return left;
         * Else count task(left) with left_val and task(right) with right_val,
         * return the most count value.
         */
        if(left == right) return nums[left];
        int mid = (left + right) >> 1;
        int l = divideAndConquerSolution(nums, left, mid);
        int r = divideAndConquerSolution(nums, mid+1, right);
        if(l == r)
            return l;
        int left_cnt = countInRange(nums, l, left, mid);
        int right_cnt = countInRange(nums, r, mid+1, right);
        return left_cnt > right_cnt ? l : r;
    }
    int constantSpaceSolution(vector<int> &nums) {
        /*
         * The idea of constant space solution is to track the most visited value,
         * and iterate through the vector, if the visited value is different from tracked value,
         * then simply deduct the count.
         * Because the primary element is always the most frequent element in every block!
         * Boyer-Moore Voting algorithm
         */
        int cnt = 0, candidate = 0;
        for(auto &i: nums) {
            if(cnt == 0) candidate = i;
            cnt += (candidate == i) ? 1 : -1;
        }
        return candidate;
    }
    int hashMapSolution(vector<int> &nums) {
        unordered_map<int, int> mp;
        int max_cnt = 0, major_element;
        for(auto &i: nums) {
            ++mp[i];
            if(mp[i] > max_cnt) {
                max_cnt = mp[i];
                major_element = i;
            }
        }
        return major_element;
    }
    int majorityElement(vector<int>& nums) {
//        return hashMapSolution(nums);
//        return divideAndConquerSolution(nums, 0, nums.size()-1);
        return constantSpaceSolution(nums);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    return 0;
}