//Given two non-negative integers num1 and num2 represented as strings, return t
//he product of num1 and num2, also represented as a string. 
//
// Note: You must not use any built-in BigInteger library or convert the inputs 
//to integer directly. 
//
// 
// Example 1: 
// Input: num1 = "2", num2 = "3"
//Output: "6"
// Example 2: 
// Input: num1 = "123", num2 = "456"
//Output: "56088"
// 
// 
// Constraints: 
//
// 
// 1 <= num1.length, num2.length <= 200 
// num1 and num2 consist of digits only. 
// Both num1 and num2 do not contain any leading zero, except the number 0 itsel
//f. 
// 
// Related Topics Math String 
// 👍 2652 👎 1060


#include <iostream>
#include <string>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" | num2 == "0") return "0";
        int n = num1.size(), m = num2.size(), carry = 0;
        string ans(n+m, '0');
        for(int i=n-1; i>=0; --i) {
            for(int j=m-1; j>=0; --j) {
                carry = (num1[i] - '0') * (num2[j] - '0') + (ans[i+j+1] - '0');
                ans[i+j] += carry / 10;
                ans[i+j+1] = carry % 10 + '0';
            }
        }
        ans.erase(0, ans.find_first_not_of('0'));
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    solution.multiply("123", "456");
    return 0;
}