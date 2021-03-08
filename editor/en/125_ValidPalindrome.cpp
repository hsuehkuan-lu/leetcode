//Given a string, determine if it is a palindrome, considering only alphanumeric
// characters and ignoring cases. 
//
// Note: For the purpose of this problem, we define empty string as valid palind
//rome. 
//
// Example 1: 
//
// 
//Input: "A man, a plan, a canal: Panama"
//Output: true
// 
//
// Example 2: 
//
// 
//Input: "race a car"
//Output: false
// 
//
// 
// Constraints: 
//
// 
// s consists only of printable ASCII characters. 
// 
// Related Topics Two Pointers String 
// 👍 1701 👎 3493


//leetcode submit region begin(Prohibit modification and deletion)
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() <= 1) { return true; }
        int i=0, j=s.size()-1;
        while(i < j) {
            while(!isalpha(s[i]) && i < s.size()) i++;
            while(!isalpha(s[j]) && j > 0) j--;
            if(i >= s.size() || j < 0) return true;
            if(tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    cout << solution.isPalindrome("0P");
    return 0;
}