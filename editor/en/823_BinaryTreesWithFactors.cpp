//Given an array of unique integers, arr, where each integer arr[i] is strictly 
//greater than 1. 
//
// We make a binary tree using these integers, and each number may be used for a
//ny number of times. Each non-leaf node's value should be equal to the product of
// the values of its children. 
//
// Return the number of binary trees we can make. The answer may be too large so
// return the answer modulo 109 + 7. 
//
// 
// Example 1: 
//
// 
//Input: arr = [2,4]
//Output: 3
//Explanation: We can make these trees: [2], [4], [4, 2, 2] 
//
// Example 2: 
//
// 
//Input: arr = [2,4,5,10]
//Output: 7
//Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 
//5], [10, 5, 2]. 
//
// 
// Constraints: 
//
// 
// 1 <= arr.length <= 1000 
// 2 <= arr[i] <= 109 
// 
// 👍 439 👎 49


#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        if(arr.empty()) return 0;
        int mod = pow(10, 9) + 7;
        sort(arr.begin(), arr.end());
        unordered_map<int, long> mp;
        for(auto &i: arr) mp[i] = 1;
        long total = 0;
        for(int i=0; i<arr.size(); ++i) {
            for(int j=0; j<i; ++j) {
                // arr[i] is factor of arr[j]
                if(arr[i] % arr[j] == 0) {
                    int fac = arr[i] / arr[j];
                    mp[arr[i]] = (mp[arr[i]] + mp[arr[j]] * mp[fac]) % mod;
                }
            }
            total = (total + mp[arr[i]]) % mod;
        }
        return total;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> arr = {2,4,5,10};
    solution.numFactoredBinaryTrees(arr);
    return 0;
}