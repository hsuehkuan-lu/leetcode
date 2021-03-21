//Given an integer array nums of unique elements, return all possible subsets (t
//he power set). 
//
// The solution set must not contain duplicate subsets. Return the solution in a
//ny order. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,2,3]
//Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// 
//
// Example 2: 
//
// 
//Input: nums = [0]
//Output: [[],[0]]
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10 
// -10 <= nums[i] <= 10 
// All the numbers of nums are unique. 
// 
// Related Topics Array Backtracking Bit Manipulation 
// 👍 5416 👎 109


#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    private:
    int n;
public:
    string vector2String(vector<int> &nums) {
        string s;
        for(auto &i: nums)
            s += to_string(i) + "#";
        return s;
    }
    void permutation(vector<int> &nums, int position, vector<vector<int>> &ans, unordered_set<string> &s) {
        if(position == n-1) {
            for(int i=1; i<n; ++i) {
                vector<int> v(nums.begin(), nums.begin() + i);
                sort(v.begin(), v.end());
                string str = vector2String(v);
                if(!s.count(str)) {
                    ans.push_back(v);
                    s.insert(str);
                }
            }
        }
        else {
            for(int i=position; i<n; ++i) {
                swap(nums[i], nums[position]);
                permutation(nums, position + 1, ans, s);
                swap(nums[i], nums[position]);
            }
        }
    }
    void backtrackingSolution(vector<int> &nums, int position, vector<vector<int>> &ans, vector<int> &sub) {
        ans.push_back(sub);
        for(int i=position; i<n; ++i) {
            sub.push_back(nums[i]);
            backtrackingSolution(nums, i + 1, ans, sub);
            sub.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty()) return {};
        n = nums.size();
        vector<vector<int>> ans;
        vector<int> sub;
        backtrackingSolution(nums, 0, ans, sub);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> nums = {1,2,3,4};
    solution.subsets(nums);
    return 0;
}