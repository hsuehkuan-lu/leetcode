//Given a binary string s and an integer k. 
//
// Return True if every binary code of length k is a substring of s. Otherwise, 
//return False. 
//
// 
// Example 1: 
//
// 
//Input: s = "00110110", k = 2
//Output: true
//Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They 
//can be all found as substrings at indicies 0, 1, 3 and 2 respectively.
// 
//
// Example 2: 
//
// 
//Input: s = "00110", k = 2
//Output: true
// 
//
// Example 3: 
//
// 
//Input: s = "0110", k = 1
//Output: true
//Explanation: The binary codes of length 1 are "0" and "1", it is clear that bo
//th exist as a substring. 
// 
//
// Example 4: 
//
// 
//Input: s = "0110", k = 2
//Output: false
//Explanation: The binary code "00" is of length 2 and doesn't exist in the arra
//y.
// 
//
// Example 5: 
//
// 
//Input: s = "0000000001011100", k = 4
//Output: false
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 5 * 10^5 
// s consists of 0's and 1's only. 
// 1 <= k <= 20 
// 
// Related Topics String Bit Manipulation 
// 👍 284 👎 49


#include <iostream>
#include <cmath>
#include <string>
#include <bitset>
#include <unordered_set>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string convertNumToBits(long long digit, int &k) {
        string binary = bitset<20>(digit).to_string();
        return binary.substr(binary.length() - k, k);
    }
    bool allPermutationSolution(string &s, int &k) {
        if(k > s.length()) return false;
        long long total = pow(2, k);
        for(long long i=0; i<=total; ++i) {
            string binary = convertNumToBits(i, k);
            if(s.find(binary) == string::npos)
                return false;
        }
        return true;
    }
    bool hashSetSolution(string &s, int &k) {
        unordered_set<string> bit_set;
        int total = 1 << k;
        int l = s.size() - k + 1;
        for(int i=0; i<l; ++i) {
            string substr = s.substr(i, k);
            if(bit_set.find(substr) == bit_set.end()) {
                bit_set.insert(substr);
                total--;
                if(total == 0) return true;
            }
        }
        return false;
    }
    bool vectorSolution(string &s, int &k) {
        /*
         * This method is using Rolling Hashing, since the problem is exactly
         * bit on-the-fly, and hash value can be generated based on appearing
         * sequence of k-th elements!
         *
         * e.g. 000101 k=2
         *  1. 0
         *  2. 00
         *  3. 00
         *  4. 01
         *  5. 10
         *  6. 01
         */
        int total = 1 << k, l = s.size();
        int all_one = total - 1;
        bool bit_set[total];
        memset(bit_set, false, total);
        int hash_val = 0;
        for(int i=0; i<l; ++i) {
            hash_val = ((hash_val << 1) & all_one) | (s[i] - '0');
            // start check bit string from k
            if(i >= k-1 && !bit_set[hash_val]) {
                --total;
                bit_set[hash_val] = true;
                if(total == 0) return true;
            }
        }
        return false;
    }
    bool hasAllCodes(string s, int k) {
//        return hashSetSolution(s, k);
        return vectorSolution(s, k);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    solution.hasAllCodes("00110", 2);
    return 0;
}