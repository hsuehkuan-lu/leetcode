//Given an array nums of distinct integers, return all the possible permutations
//. You can return the answer in any order. 
//
// 
// Example 1: 
// Input: nums = [1,2,3]
//Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2: 
// Input: nums = [0,1]
//Output: [[0,1],[1,0]]
// Example 3: 
// Input: nums = [1]
//Output: [[1]]
// 
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 6 
// -10 <= nums[i] <= 10 
// All the integers of nums are unique. 
// 
// Related Topics Backtracking 
// 👍 5563 👎 128


#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // failed -> do not contain all the conditions
    vector<vector<int>> dictionarySorting(vector<int> &nums) {
        // make sure the order of nums is ascending
        sort(nums.begin(), nums.end());
        vector<vector<int>> permutations;
        permutations.push_back(nums);
        for(int i=0; i<nums.size(); ++i) {
            for(int j = nums.size()-1; j>i; --j) {
                swap(nums[j], nums[j-1]);
                permutations.push_back(nums);
            }
        }
        return permutations;
    }

    vector<vector<int>> permutations;
    void backtracking(vector<int> &nums, int position) {
        /*
         * Backtracking algorithm is the idea of recursion, and reset status
         * back to original state, so as to avoid error propagation.
         */
        if(position == nums.size()-1)
            permutations.push_back(nums);
        else {
            for(int i=position; i<nums.size(); ++i) {
                swap(nums[i], nums[position]);
                backtracking(nums, position+1);
                swap(nums[i], nums[position]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtracking(nums, 0);
        return permutations;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> nums = {1,2,3};
    solution.permute(nums);
    return 0;
}