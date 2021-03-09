//Given a non-empty array of integers, return the k most frequent elements. 
//
// Example 1: 
//
// 
//Input: nums = [1,1,1,2,2,3], k = 2
//Output: [1,2]
// 
//
// 
// Example 2: 
//
// 
//Input: nums = [1], k = 1
//Output: [1] 
// 
//
// Note: 
//
// 
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements. 
// Your algorithm's time complexity must be better than O(n log n), where n is t
//he array's size. 
// It's guaranteed that the answer is unique, in other words the set of the top 
//k frequent elements is unique. 
// You can return the answer in any order. 
// 
// Related Topics Hash Table Heap 
// 👍 4595 👎 260


#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> solve(vector<int> &nums, int k) {
        vector<int> V;
        unordered_map<int, int> mp, freq;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for(auto &i: nums) {
            ++mp[i];
        }
        for(auto &i: mp) {
            min_heap.push(i.second);
            while(min_heap.size() > k)
                min_heap.pop();
        }
        for(auto &i: mp) {
            if(i.second >= min_heap.top())
                V.push_back(i.first);
        }
        return V;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        return solve(nums, k);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    return 0;
}