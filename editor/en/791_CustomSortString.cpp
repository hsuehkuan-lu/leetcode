//order and str are strings composed of lowercase letters. In order, no letter o
//ccurs more than once. 
//
// order was sorted in some custom order previously. We want to permute the char
//acters of str so that they match the order that order was sorted. More specifica
//lly, if x occurs before y in order, then x should occur before y in the returned
// string. 
//
// Return any permutation of str (as a string) that satisfies this property. 
//
// 
//Example:
//Input: 
//order = "cba"
//str = "abcd"
//Output: "cbad"
//Explanation: 
//"a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b
//", and "a". 
//Since "d" does not appear in order, it can be at any position in the returned 
//string. "dcba", "cdba", "cbda" are also valid outputs.
// 
//
// 
//
// Note: 
//
// 
// order has length at most 26, and no character is repeated in order. 
// str has length at most 200. 
// order and str consist of lowercase letters only. 
// 
// Related Topics Hash Table String Sorting 
// 👍 1223 👎 233


 <iostream>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string customSortString(string order, string str) {
        int arr[26] = {0};
        for(auto &ch: str) ++arr[ch - 'a'];
        string ans;
        for(auto &ch: order) {
            while(arr[ch - 'a'] > 0) {
                ans += ch;
                --arr[ch - 'a'];
            }
        }
        for(int i=0; i<26; ++i) {
            while(arr[i] > 0) {
                ans += 'a' + i;
                --arr[i];
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    return 0;
}