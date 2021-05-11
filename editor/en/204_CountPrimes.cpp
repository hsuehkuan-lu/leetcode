//Count the number of prime numbers less than a non-negative number, n. 
//
// 
// Example 1: 
//
// 
//Input: n = 10
//Output: 4
//Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
// 
//
// Example 2: 
//
// 
//Input: n = 0
//Output: 0
// 
//
// Example 3: 
//
// 
//Input: n = 1
//Output: 0
// 
//
// 
// Constraints: 
//
// 
// 0 <= n <= 5 * 106 
// 
// Related Topics Hash Table Math 
// 👍 3053 👎 777


#include <iostream>
#include <cmath>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        bool arr[n];
        memset(arr, false, sizeof(arr));

        for(int i=2; i<=sqrt(n); ++i) {
            if(!arr[i]) {
                for(int j=i*i; j<n; j+=i) {
                    arr[j] = true;
                }
            }
        }
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (!arr[i]) {
                ++cnt;
            }
        }
        return cnt;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    solution.countPrimes(4);
    return 0;
}