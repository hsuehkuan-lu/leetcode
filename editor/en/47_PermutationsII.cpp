//Given a collection of numbers, nums, that might contain duplicates, return all
// possible unique permutations in any order. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,1,2]
//Output:
//[[1,1,2],
// [1,2,1],
// [2,1,1]]
// 
//
// Example 2: 
//
// 
//Input: nums = [1,2,3]
//Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 8 
// -10 <= nums[i] <= 10 
// 
// Related Topics Backtracking 
// 👍 2800 👎 77


#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string encodeNumsToString(vector<int> &nums) {
        string s;
        for(auto &i: nums) s += to_string(i) + "#";
        return s;
    }
    void backtracking(vector<int> &nums, int position, vector<vector<int>> &permutations,
                      unordered_set<string> &visited) {
        string s = encodeNumsToString(nums);
        if(visited.find(s) != visited.end()) return;
        if(position == nums.size() - 1){
            permutations.push_back(nums);
            visited.insert(s);
        }
        else {
            for(int i=position; i<nums.size(); ++i) {
                swap(nums[i], nums[position]);
                backtracking(nums, position+1, permutations, visited);
                swap(nums[i], nums[position]);
            }
        }
    }
    void backtrackingWithSet(vector<int> nums, int position, vector<vector<int>> &permutations) {
        if(position == nums.size() - 1)
            permutations.push_back(nums);
        else {
            unordered_set<int> s;
            for(int i=position; i<nums.size(); ++i) {
                if(s.find(nums[i]) != s.end()) continue;
                swap(nums[i], nums[position]);
                backtrackingWithSet(nums, position+1, permutations);
                swap(nums[i], nums[position]);
                s.insert(nums[i]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> permutations;
//        unordered_set<string> visited;
//        backtracking(nums, 0, permutations, visited);
//        sort(nums.begin(), nums.end());
        backtrackingWithSet(nums, 0, permutations);
        return permutations;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> v = {1,2,2,5,7};
    solution.permuteUnique(v);
    return 0;
}