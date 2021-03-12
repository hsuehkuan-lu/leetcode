//Given a string s which represents an expression, evaluate this expression and 
//return its value. 
//
// The integer division should truncate toward zero. 
//
// 
// Example 1: 
// Input: s = "3+2*2"
//Output: 7
// Example 2: 
// Input: s = " 3/2 "
//Output: 1
// Example 3: 
// Input: s = " 3+5 / 2 "
//Output: 5
// 
// 
// Constraints: 
//
// 
// 1 <= s.length <= 3 * 105 
// s consists of integers and operators ('+', '-', '*', '/') separated by some n
//umber of spaces. 
// s represents a valid expression. 
// All the integers in the expression are non-negative integers in the range [0,
// 231 - 1]. 
// The answer is guaranteed to fit in a 32-bit integer. 
// 
// Related Topics String Stack 
// 👍 2203 👎 344


#include <iostream>
#include <stack>
#include <string>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findDigit(string &s, int &position) {
        string digit;
        while(position < s.length()) {
            if(s[position] >= '0' && s[position] <= '9') {
                digit += s[position];
            } else if(!digit.empty()) {
                break;
            }
            ++position;
        }
        return stoi(digit);
    }

    char findOp(string &s, int &position) {
        while(position < s.length()) {
            if(s[position] == '+' || s[position] == '-' || s[position] == '*' || s[position] == '/')
                return s[position];
            else
                ++position;
        }
        return '\0';
    }

    int stackSolution(string s) {
        stack<int> digit_s;
        int position = 0;
        digit_s.push(findDigit(s, position));
        while(position < s.length()) {
            char op = findOp(s, position);
            if(op == '\0') break;
            int digit = findDigit(s, position);
            if(op == '*') {
                int val = digit_s.top() * digit;
                digit_s.pop();
                digit_s.push(val);
            } else if(op == '/') {
                int val = digit_s.top() / digit;
                digit_s.pop();
                digit_s.push(val);
            } else if(op == '-') {
                digit_s.push(-digit);
            } else {
                digit_s.push(digit);
            }

        }
        int num = digit_s.top();
        digit_s.pop();
        while(!digit_s.empty()) {
            int first = digit_s.top();
            digit_s.pop();
            num += first;
        }
        return int(num);
    }

    int noStackSolution(string &s) {
        /*
         * The idea of without using stack is that stores every results to prev once
         * + or - occurred, and calculate * or / to cur.
         */
        int position = 0;
        int prev = 0, cur = findDigit(s, position);
        while(position < s.length()) {
            char op = findOp(s, position);
            if(op == '\0') break;
            int digit = findDigit(s, position);
            if(op == '*') {
                cur *= digit;
            } else if(op == '/') {
                cur /= digit;
            } else if(op == '-') {
                prev += cur;
                cur = -digit;
            } else {
                prev += cur;
                cur = digit;
            }
        }
        return prev + cur;
    }

    int calculate(string s) {
        return noStackSolution(s);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    solution.calculate("3+2*2");
    return 0;
}