//Given an integer array nums, handle multiple queries of the following type: 
//
// 
// Calculate the sum of the elements of nums between indices left and right incl
//usive where left <= right. 
// 
//
// Implement the NumArray class: 
//
// 
// NumArray(int[] nums) Initializes the object with the integer array nums. 
// int sumRange(int left, int right) Returns the sum of the elements of nums bet
//ween indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + 
//nums[right]). 
// 
//
// 
// Example 1: 
//
// 
//Input
//["NumArray", "sumRange", "sumRange", "sumRange"]
//[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
//Output
//[null, 1, -1, -3]
//
//Explanation
//NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
//numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
//numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
//numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 104 
// -105 <= nums[i] <= 105 
// 0 <= left <= right < nums.length 
// At most 104 calls will be made to sumRange. 
// 
// Related Topics Dynamic Programming 
// 👍 1283 👎 1360


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
static int x = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return 0;}();
class NumArray {
    int *v;
public:
    NumArray(vector<int>& nums) {
        v = new int[nums.size()+1];
        for(int i=0; i<nums.size(); ++i) {
            v[i+1] = v[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return v[right+1] - v[left];
    }
};

//class NumArray {
//    vector<int> v;
//    vector<int> dp;
//    int m;
//public:
//    NumArray(vector<int>& nums) {
//        v = nums;
//        m = nums.size();
//        dp.resize(m, vector<int>(m, 0));
//    }
//
//    int sumRange(int left, int right) {
//        if(dp[left][right]) return dp[left][right];
//        if(left == right) {
//            dp[left][right] = v[left];
//            return dp[left][right];
//        }
//        dp[left][right] = v[right] + sumRange(left, right-1);
//        return dp[left][right];
//    }
//};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    return 0;
}