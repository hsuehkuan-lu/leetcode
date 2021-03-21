//Given a list of non-negative integers nums, arrange them such that they form t
//he largest number. 
//
// Note: The result may be very large, so you need to return a string instead of
// an integer. 
//
// 
// Example 1: 
//
// 
//Input: nums = [10,2]
//Output: "210"
// 
//
// Example 2: 
//
// 
//Input: nums = [3,30,34,5,9]
//Output: "9534330"
// 
//
// Example 3: 
//
// 
//Input: nums = [1]
//Output: "1"
// 
//
// Example 4: 
//
// 
//Input: nums = [10]
//Output: "10"
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 100 
// 0 <= nums[i] <= 109 
// 
// Related Topics Sort 
// 👍 2873 👎 306


#include <iostream>
#include <vector>
#include <string>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)



class Solution {
public:
    vector<string> merge(const vector<string> &a, const vector<string> &b) {
        vector<string> m;
        for(int i=0, j=0; i<a.size() || j<b.size();) {
            if(i>=a.size()) {
                m.push_back(b[j++]);
                continue;
            }
            if(j>=b.size()) {
                m.push_back(a[i++]);
                continue;
            }
            string sa = a[i] + b[j], sb = b[j] + a[i];
            if(sa > sb) {
                m.push_back(a[i++]);
            } else {
                m.push_back(b[j++]);
            }
        }
        return m;
    }
    vector<string> mergeSort(vector<string> &v, int left, int right) {
        if(left == right) return {v[left]};
        int mid = left + (right - left) >> 1;
        return merge(mergeSort(v, left, mid), mergeSort(v, mid+1, right));
    }
    string sortSolution(vector<int> &nums) {
        vector<string> v;
        for(auto &i: nums) v.push_back(to_string(i));
        v = mergeSort(v, 0, v.size()-1);
        string s;
        bool leading_zero = true;
        for(auto &i: v) {
            if(i == "0" && leading_zero) {
                continue;
            } else {
                s += i;
                leading_zero = false;
            }
        }
        if(s.empty()) s = "0";
        return s;
    }
    string builtInSortSolution(vector<int> &nums) {
        vector<string> v;
        for(auto &i: nums) v.push_back(to_string(i));
        sort(v.begin(), v.end(), [](const string &a, const string &b){
            return a + b > b + a;
        });
        string s;
        bool leading_zero = true;
        for(auto &i: v) {
            if(i == "0" && leading_zero) {
                continue;
            } else {
                s += i;
                leading_zero = false;
            }
        }
        if(s.empty()) s = "0";
        return s;
    }
    string largestNumber(vector<int>& nums) {
        return builtInSortSolution(nums);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> nums = {10, 2, 13, 9, 80};
    solution.largestNumber(nums);
    return 0;
}