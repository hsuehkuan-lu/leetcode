//Given an array of characters chars, compress it using the following algorithm:
// 
//
// Begin with an empty string s. For each group of consecutive repeating charact
//ers in chars: 
//
// 
// If the group's length is 1, append the character to s. 
// Otherwise, append the character followed by the group's length. 
// 
//
// The compressed string s should not be returned separately, but instead be sto
//red in the input character array chars. Note that group lengths that are 10 or l
//onger will be split into multiple characters in chars. 
//
// After you are done modifying the input array, return the new length of the ar
//ray. 
// 
//
// Follow up: 
//Could you solve it using only O(1) extra space? 
//
// 
// Example 1: 
//
// 
//Input: chars = ["a","a","b","b","c","c","c"]
//Output: Return 6, and the first 6 characters of the input array should be: ["a
//","2","b","2","c","3"]
//Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3"
//.
// 
//
// Example 2: 
//
// 
//Input: chars = ["a"]
//Output: Return 1, and the first character of the input array should be: ["a"]
//Explanation: The only group is "a", which remains uncompressed since it's a si
//ngle character.
// 
//
// Example 3: 
//
// 
//Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
//Output: Return 4, and the first 4 characters of the input array should be: ["a
//","b","1","2"].
//Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
// 
//
// Example 4: 
//
// 
//Input: chars = ["a","a","a","b","b","a","a"]
//Output: Return 6, and the first 6 characters of the input array should be: ["a
//","3","b","2","a","2"].
//Explanation: The groups are "aaa", "bb", and "aa". This compresses to "a3b2a2"
//. Note that each group is independent even if two groups have the same character
//.
// 
//
// 
// Constraints: 
//
// 
// 1 <= chars.length <= 2000 
// chars[i] is a lower-case English letter, upper-case English letter, digit, or
// symbol. 
// 
// Related Topics String 
// 👍 1281 👎 3237


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;
        for(int i=0, j=0; i<chars.size(); ) {
            char ch = chars[i];
            for(j=i; j<chars.size() && chars[j] == ch; ++j) {

            }
            if(j - i == 1) {
                ++ans;
            } else {
                ++ans;
                int n_digit = 0;
                for(int k=j-i; k>0; k/=10) {
                    chars[i + n_digit++ + 1] = k % 10 + '0';
                }
                reverse(chars.begin() + i + 1, chars.begin() + i + n_digit + 1);
                chars.erase(chars.begin() + i + n_digit + 1, chars.begin() + j);
                j = i + n_digit + 1;
                ans += n_digit;
            }
            i = j;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<char> v = {'a', 'a', 'b','b','c','c','c'};
    solution.compress(v);
    return 0;
}