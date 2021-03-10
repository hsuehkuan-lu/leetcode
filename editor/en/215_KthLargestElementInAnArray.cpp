//Given an integer array nums and an integer k, return the kth largest element i
//n the array. 
//
// Note that it is the kth largest element in the sorted order, not the kth dist
//inct element. 
//
// 
// Example 1: 
// Input: nums = [3,2,1,5,6,4], k = 2
//Output: 5
// Example 2: 
// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
//Output: 4
// 
// 
// Constraints: 
//
// 
// 1 <= k <= nums.length <= 104 
// -104 <= nums[i] <= 104 
// 
// Related Topics Divide and Conquer Heap 
// 👍 5257 👎 337


#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> q;
        for(auto &i: nums) {
            q.push(i);
            if(q.size() > k)
                q.pop();
        }
        return q.top();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> v = {3,2,1,5,6,4};
    solution.findKthLargest(v, 2);
    return 0;
}