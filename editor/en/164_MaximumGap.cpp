//Given an integer array nums, return the maximum difference between two success
//ive elements in its sorted form. If the array contains less than two elements, r
//eturn 0. 
//
// You must write an algorithm that runs in linear time and uses linear extra sp
//ace. 
//
// 
// Example 1: 
//
// 
//Input: nums = [3,6,9,1]
//Output: 3
//Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) 
//has the maximum difference 3.
// 
//
// Example 2: 
//
// 
//Input: nums = [10]
//Output: 0
//Explanation: The array contains less than 2 elements, therefore return 0.
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 104 
// 0 <= nums[i] <= 109 
// 
// Related Topics Sort 
// 👍 1309 👎 229


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
static int x = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return 0;}();
class Solution {
private:
    struct Bucket{
        Bucket(): min_val(INT_MAX), max_val(INT_MIN) {}
        int min_val;
        int max_val;
    };
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int min_val = *min_element(nums.begin(), nums.end());
        int max_val = *max_element(nums.begin(), nums.end());
        int bucket_size = max(1, (max_val - min_val) / ((int)nums.size() - 1));
        int bucket_num = (max_val - min_val) / bucket_size + 1;
        vector<Bucket> buckets(bucket_num);
        int max_gap = INT_MIN, idx;
        for(auto &i: nums) {
            idx = (i - min_val) / bucket_size;
            buckets[idx].min_val = min(i, buckets[idx].min_val);
            buckets[idx].max_val = max(i, buckets[idx].max_val);
        }
        int cur = min_val;
        for(auto &b: buckets) {
            if(b.min_val == INT_MAX || b.max_val == INT_MIN) continue;
            max_gap = max(max_gap, b.min_val - cur);
            cur = b.max_val;
        }
        return max_gap;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> v = {1,1,1,1,1,5,5,5,5,6,6,6,6};
    solution.maximumGap(v);
    return 0;
}