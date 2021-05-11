//Given two sorted arrays nums1 and nums2 of size m and n respectively, return t
//he median of the two sorted arrays. 
//
// The overall run time complexity should be O(log (m+n)). 
//
// 
// Example 1: 
//
// 
//Input: nums1 = [1,3], nums2 = [2]
//Output: 2.00000
//Explanation: merged array = [1,2,3] and median is 2.
// 
//
// Example 2: 
//
// 
//Input: nums1 = [1,2], nums2 = [3,4]
//Output: 2.50000
//Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
// 
//
// Example 3: 
//
// 
//Input: nums1 = [0,0], nums2 = [0,0]
//Output: 0.00000
// 
//
// Example 4: 
//
// 
//Input: nums1 = [], nums2 = [1]
//Output: 1.00000
// 
//
// Example 5: 
//
// 
//Input: nums1 = [2], nums2 = []
//Output: 2.00000
// 
//
// 
// Constraints: 
//
// 
// nums1.length == m 
// nums2.length == n 
// 0 <= m <= 1000 
// 0 <= n <= 1000 
// 1 <= m + n <= 2000 
// -106 <= nums1[i], nums2[i] <= 106 
// 
// Related Topics Array Binary Search Divide and Conquer 
// 👍 9975 👎 1530


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int m, n;
public:
    double getKthElement(vector<int> &nums1, int start1, vector<int> &nums2, int start2, int k) {
        if(start1 >= nums1.size()) return nums2[start2 + k - 1];
        if(start2 >= nums2.size()) return nums1[start1 + k - 1];
        if(k == 1) return min(nums1[start1], nums2[start2]);
        int idx1 = start1 + k/2 - 1, idx2 = start2 + k/2 - 1;
        int elem1 = idx1 < nums1.size() ? nums1[idx1] : INT_MAX;
        int elem2 = idx2 < nums2.size() ? nums2[idx2] : INT_MAX;
        if(elem1 < elem2) {
            return getKthElement(nums1, start1 + k/2, nums2, start2, k - k/2);
        } else {
            return getKthElement(nums1, start1, nums2, start2 + k/2, k - k/2);
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size(), n = nums2.size();
        double ans = (
                getKthElement(nums1, 0, nums2, 0, (m+n+1)/2)
                + getKthElement(nums1, 0, nums2, 0, (m+n+2)/2)
                ) * 0.5;
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> v1 = {1,2,6}, v2 = {4,5,7};
    solution.findMedianSortedArrays(v1, v2);
    return 0;
}