//Given an integer n, return the number of trailing zeroes in n!. 
//
// Follow up: Could you write a solution that works in logarithmic time complexi
//ty? 
//
// 
// Example 1: 
//
// 
//Input: n = 3
//Output: 0
//Explanation: 3! = 6, no trailing zero.
// 
//
// Example 2: 
//
// 
//Input: n = 5
//Output: 1
//Explanation: 5! = 120, one trailing zero.
// 
//
// Example 3: 
//
// 
//Input: n = 0
//Output: 0
// 
//
// 
// Constraints: 
//
// 
// 0 <= n <= 104 
// 
// Related Topics Math 
// 👍 1209 👎 1359


#include <iostream>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int factorialFiveSolution(int n) {
        int fac5 = 0;
        for(int i=5; i<=n; ++i){
            if(i % 5 == 0) {
                int j = i;
                while(j % 5 == 0) {
                    ++fac5;
                    j /= 5;
                }
            }
        }
        return fac5;
    }

    int optimizeFacFive(int n) {
        int fac5 = 0;
        while(n) {
            fac5 += n / 5;
            n /= 5;
        }
        return fac5;
    }

    int trailingZeroes(int n) {
        return optimizeFacFive(n);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    solution.trailingZeroes(10);
    return 0;
}