//Given a positive integer num, write a function which returns True if num is a 
//perfect square else False. 
//
// Follow up: Do not use any built-in library function such as sqrt. 
//
// 
// Example 1: 
// Input: num = 16
//Output: true
// Example 2: 
// Input: num = 14
//Output: false
// 
// 
// Constraints: 
//
// 
// 1 <= num <= 2^31 - 1 
// 
// Related Topics Math Binary Search 
// 👍 1226 👎 194


#include <iostream>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1, high = num;
        while(low < high) {
            int mid = low + (high - low) / 2;
            int root = num / mid;
            if(root <= mid) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return num / low == low && num % low == 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    solution.isPerfectSquare(4);
    return 0;
}