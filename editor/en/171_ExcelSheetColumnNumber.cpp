//Given a string columnTitle that represents the column title as appear in an Ex
//cel sheet, return its corresponding column number. 
//
// For example: 
//
// 
//A -> 1
//B -> 2
//C -> 3
//...
//Z -> 26
//AA -> 27
//AB -> 28 
//...
// 
//
// 
// Example 1: 
//
// 
//Input: columnTitle = "A"
//Output: 1
// 
//
// Example 2: 
//
// 
//Input: columnTitle = "AB"
//Output: 28
// 
//
// Example 3: 
//
// 
//Input: columnTitle = "ZY"
//Output: 701
// 
//
// Example 4: 
//
// 
//Input: columnTitle = "FXSHRXW"
//Output: 2147483647
// 
//
// 
// Constraints: 
//
// 
// 1 <= columnTitle.length <= 7 
// columnTitle consists only of uppercase English letters. 
// columnTitle is in the range ["A", "FXSHRXW"]. 
// 
// Related Topics Math 
// 👍 1586 👎 194


#include <iostream>
#include <string>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long cur = 1, idx = 0;
        for(int i=columnTitle.size()-1; i>=0; --i) {
            idx += long(columnTitle[i] - 'A' + 1) * cur;
            cur *= 26;
        }
        return int(idx);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    solution.titleToNumber("AB");
    return 0;
}