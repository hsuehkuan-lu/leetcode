//Given an integer array nums that may contain duplicates, return all possible s
//ubsets (the power set). 
//
// The solution set must not contain duplicate subsets. Return the solution in a
//ny order. 
//
// 
// Example 1: 
// Input: nums = [1,2,2]
//Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2: 
// Input: nums = [0]
//Output: [[],[0]]
// 
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10 
// -10 <= nums[i] <= 10 
// 
// Related Topics Array Backtracking Bit Manipulation 
// 👍 3083 👎 116
	

#include <iostream>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int n;
    vector<vector<int>> ans;
public:
    void dfs(vector<int> &nums, vector<int> &path, int start) {
        if(start > n) return;
        ans.push_back(path);
        for(int i=start; i<n; ++i) {
            if(i!=start && nums[i] == nums[i-1])
                continue;
            path.push_back(nums[i]);
            dfs(nums, path, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        vector<int> path;
        dfs(nums, path, 0);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    return 0;
}