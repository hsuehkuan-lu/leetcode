//You are given an integer length and an array updates where updates[i] = [start
//Idxi, endIdxi, inci]. 
//
// You have an array arr of length length with all zeros, and you have some oper
//ation to apply on arr. In the ith operation, you should increment all the elemen
//ts arr[startIdxi], arr[startIdxi + 1], ..., arr[endIdxi] by inci. 
//
// Return arr after applying all the updates. 
//
// 
// Example 1: 
//
// 
//Input: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
//Output: [-2,0,3,5,3]
// 
//
// Example 2: 
//
// 
//Input: length = 10, updates = [[2,4,6],[5,6,8],[1,9,-4]]
//Output: [0,-4,2,2,2,4,4,-4,-4,-4]
// 
//
// 
// Constraints: 
//
// 
// 1 <= length <= 105 
// 0 <= updates.length <= 104 
// 0 <= startIdxi <= endIdxi < length 
// -1000 <= inci <= 1000 
// 
// Related Topics Array Prefix Sum 
// 👍 697 👎 27


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
static int x = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return 0;}();
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ans(length+1);
        for(auto &v: updates) {
            ans[v[0]] += v[2];
            ans[v[1]+1] -= v[2];
        }
        for(int i=1; i<length; ++i) {
            ans[i] += ans[i-1];
        }
        ans.pop_back();
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    return 0;
}