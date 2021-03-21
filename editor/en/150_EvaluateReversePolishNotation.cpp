//Evaluate the value of an arithmetic expression in Reverse Polish Notation. 
//
// Valid operators are +, -, *, and /. Each operand may be an integer or another
// expression. 
//
// Note that division between two integers should truncate toward zero. 
//
// It is guaranteed that the given RPN expression is always valid. That means th
//e expression would always evaluate to a result, and there will not be any divisi
//on by zero operation. 
//
// 
// Example 1: 
//
// 
//Input: tokens = ["2","1","+","3","*"]
//Output: 9
//Explanation: ((2 + 1) * 3) = 9
// 
//
// Example 2: 
//
// 
//Input: tokens = ["4","13","5","/","+"]
//Output: 6
//Explanation: (4 + (13 / 5)) = 6
// 
//
// Example 3: 
//
// 
//Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
//Output: 22
//Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
//= ((10 * (6 / (12 * -11))) + 17) + 5
//= ((10 * (6 / -132)) + 17) + 5
//= ((10 * 0) + 17) + 5
//= (0 + 17) + 5
//= 17 + 5
//= 22
// 
//
// 
// Constraints: 
//
// 
// 1 <= tokens.length <= 104 
// tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the 
//range [-200, 200]. 
// 
// Related Topics Stack 
// 👍 1495 👎 516


#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isNum(string &s) {
        int i = 0;
        if(s[0] == '-' && s.size() > 1) ++i;
        for(; i<s.size(); ++i) if(!isdigit(s[i])) return false;
        return true;
    }
    int stackSolution(vector<string> &tokens) {
        stack<int> s;
        for(auto &i: tokens) {
            if(isNum(i)) {
                s.push(stoi(i));
            } else {
                int first, second;
                second = s.top(), s.pop();
                first = s.top(), s.pop();
                if(i == "+") {
                    s.push(first + second);
                } else if(i == "-") {
                    s.push(first - second);
                } else if(i == "*") {
                    s.push(first * second);
                } else {
                    s.push(first / second);
                }
            }
        }
        return s.top();
    }
    int evalRPN(vector<string>& tokens) {
        return stackSolution(tokens);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    return 0;
}