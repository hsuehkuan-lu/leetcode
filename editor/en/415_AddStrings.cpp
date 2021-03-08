//Given two non-negative integers num1 and num2 represented as string, return th
//e sum of num1 and num2. 
//
// Note:
// 
// The length of both num1 and num2 is < 5100. 
// Both num1 and num2 contains only digits 0-9. 
// Both num1 and num2 does not contain any leading zero. 
// You must not use any built-in BigInteger library or convert the inputs to int
//eger directly. 
// 
// Related Topics String 
// 👍 1592 👎 363


#include <iostream>
#include <string>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string addStrings(string num1, string num2) {
        bool carry = false;
        int right1 = num1.size() - 1, right2 = num2.size() - 1;
        string s = "";
        while(right1>=0 || right2>=0 || carry) {
            int add = 0;
            add += carry;
            carry = false;
            if(right1 >= 0) add += num1[right1--] - '0';
            if(right2 >= 0) add += num2[right2--] - '0';
            if(add >= 10) {
                carry = true;
                add -= 10;
            }
            char ch = add + '0';
            s = ch + s;
        }
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    solution.addStrings("9", "99");
    return 0;
}