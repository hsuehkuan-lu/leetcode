//Given a non-negative integer x, compute and return the square root of x. 
//
// Since the return type is an integer, the decimal digits are truncated, and on
//ly the integer part of the result is returned. 
//
// 
// Example 1: 
//
// 
//Input: x = 4
//Output: 2
// 
//
// Example 2: 
//
// 
//Input: x = 8
//Output: 2
//Explanation: The square root of 8 is 2.82842..., and since the decimal part is
// truncated, 2 is returned. 
//
// 
// Constraints: 
//
// 
// 0 <= x <= 231 - 1 
// 
// Related Topics Math Binary Search 
// 👍 1863 👎 2261


#include <iostream>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int binarySearchSolution(int target, int left, int right) {
        long num;
        while(left <= right) {
            int mid = (left + right) >> 1;
            num = long(mid) * mid;
            if(num == target) return mid;
            else if(num > target) right = mid - 1;
            else left = mid + 1;
        }
        return right;
    }
    int mySqrt(int x) {
        if(x < 2) return x;
        return binarySearchSolution(x, 1, x >> 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    return 0;
}