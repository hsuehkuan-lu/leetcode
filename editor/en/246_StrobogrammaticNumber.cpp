//Given a string num which represents an integer, return true if num is a strobo
//grammatic number. 
//
// A strobogrammatic number is a number that looks the same when rotated 180 deg
//rees (looked at upside down). 
//
// 
// Example 1: 
// Input: num = "69"
//Output: true
// Example 2: 
// Input: num = "88"
//Output: true
// Example 3: 
// Input: num = "962"
//Output: false
// Example 4: 
// Input: num = "1"
//Output: true
// 
// 
// Constraints: 
//
// 
// 1 <= num.length <= 50 
// num consists of only digits. 
// num does not contain any leading zeros except for zero itself. 
// 
// Related Topics Hash Table Math 
// 👍 297 👎 566


#include <iostream>
#include <string>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isStrobogrammatic(string num) {
        int start = 0, end = num.length() - 1;
        while(start <= end) {
            switch(num[start]) {
                case '0':
                    if(num[end] != '0') return false;
                    break;
                case '1':
                    if(num[end] != '1') return false;
                    break;
                case '6':
                    if(num[end] != '9') return false;
                    break;
                case '8':
                    if(num[end] != '8') return false;
                    break;
                case '9':
                    if(num[end] != '6') return false;
                    break;
                default:
                    return false;
            }
            ++start;
            --end;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    cout << solution.isStrobogrammatic("1");
    return 0;
}