//Given a string s. You should re-order the string using the following algorithm
//: 
//
// 
// Pick the smallest character from s and append it to the result. 
// Pick the smallest character from s which is greater than the last appended ch
//aracter to the result and append it. 
// Repeat step 2 until you cannot pick more characters. 
// Pick the largest character from s and append it to the result. 
// Pick the largest character from s which is smaller than the last appended cha
//racter to the result and append it. 
// Repeat step 5 until you cannot pick more characters. 
// Repeat the steps from 1 to 6 until you pick all characters from s. 
// 
//
// In each step, If the smallest or the largest character appears more than once
// you can choose any occurrence and append it to the result. 
//
// Return the result string after sorting s with this algorithm. 
//
// 
// Example 1: 
//
// 
//Input: s = "aaaabbbbcccc"
//Output: "abccbaabccba"
//Explanation: After steps 1, 2 and 3 of the first iteration, result = "abc"
//After steps 4, 5 and 6 of the first iteration, result = "abccba"
//First iteration is done. Now s = "aabbcc" and we go back to step 1
//After steps 1, 2 and 3 of the second iteration, result = "abccbaabc"
//After steps 4, 5 and 6 of the second iteration, result = "abccbaabccba"
// 
//
// Example 2: 
//
// 
//Input: s = "rat"
//Output: "art"
//Explanation: The word "rat" becomes "art" after re-ordering it with the mentio
//ned algorithm.
// 
//
// Example 3: 
//
// 
//Input: s = "leetcode"
//Output: "cdelotee"
// 
//
// Example 4: 
//
// 
//Input: s = "ggggggg"
//Output: "ggggggg"
// 
//
// Example 5: 
//
// 
//Input: s = "spo"
//Output: "ops"
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 500 
// s contains only lower-case English letters. 
// 
// Related Topics String Sort 
// 👍 354 👎 390


#include <iostream>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string sortString(string s) {
        int arr[26];
        memset(arr, 0, sizeof arr);
        for(auto &ch: s) ++arr[ch - 'a'];
        string ans;
        while(ans.size() != s.size()) {
            for(int i=0; i<26; ++i)
                if(arr[i]-- > 0) {
                    ans += 'a' + i;
                }
            for(int i=25; i>=0; --i)
                if(arr[i]-- > 0) {
                    ans += 'a' + i;
                }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    solution.sortString("aaabbbccc");
    return 0;
}