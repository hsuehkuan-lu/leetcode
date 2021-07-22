//The Hamming distance between two integers is the number of positions at which 
//the corresponding bits are different. 
//
// Given two integers x and y, return the Hamming distance between them. 
//
// 
// Example 1: 
//
// 
//Input: x = 1, y = 4
//Output: 2
//Explanation:
//1   (0 0 0 1)
//4   (0 1 0 0)
//       ↑   ↑
//The above arrows point to positions where the corresponding bits are different
//.
// 
//
// Example 2: 
//
// 
//Input: x = 3, y = 1
//Output: 1
// 
//
// 
// Constraints: 
//
// 
// 0 <= x, y <= 231 - 1 
// 
// Related Topics Bit Manipulation 
// 👍 2324 👎 179


#include <iostream>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int hammingDistance(int x, int y) {
        int total = 0;
        if(x > y) swap(x, y);
        while(y > 0) {
            if(x == 0) {
                total += (y % 2);
            } else {
                total += (x % 2) != (y % 2);
            }
            x /= 2;
            y /= 2;
        }
        return total;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    solution.hammingDistance(1, 4);
    return 0;
}