//Write an algorithm to determine if a number n is happy. 
//
// A happy number is a number defined by the following process: 
//
// 
// Starting with any positive integer, replace the number by the sum of the squa
//res of its digits. 
// Repeat the process until the number equals 1 (where it will stay), or it loop
//s endlessly in a cycle which does not include 1. 
// Those numbers for which this process ends in 1 are happy. 
// 
//
// Return true if n is a happy number, and false if not. 
//
// 
// Example 1: 
//
// 
//Input: n = 19
//Output: true
//Explanation:
//12 + 92 = 82
//82 + 22 = 68
//62 + 82 = 100
//12 + 02 + 02 = 1
// 
//
// Example 2: 
//
// 
//Input: n = 2
//Output: false
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 231 - 1 
// 
// Related Topics Hash Table Math 
// 👍 2974 👎 493


#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> splitNum(int num) {
        vector<int> nums;
        while(num) {
            nums.push_back(num % 10);
            num /= 10;
        }
        return nums;
    }

    bool isHappy(int n) {
        unordered_set<int> s;
        int num = n;
        while(1) {
            vector<int> nums = splitNum(num);
            num = 0;
            for(auto &i: nums)
                num += pow(i, 2);
            if(num == 1)
                return true;
            if(s.find(num) != s.end())
                return false;
            s.insert(num);
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    return 0;
}