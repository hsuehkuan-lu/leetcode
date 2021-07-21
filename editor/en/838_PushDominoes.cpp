//There are n dominoes in a line, and we place each domino vertically upright. I
//n the beginning, we simultaneously push some of the dominoes either to the left 
//or to the right. 
//
// After each second, each domino that is falling to the left pushes the adjacen
//t domino on the left. Similarly, the dominoes falling to the right push their ad
//jacent dominoes standing on the right. 
//
// When a vertical domino has dominoes falling on it from both sides, it stays s
//till due to the balance of the forces. 
//
// For the purposes of this question, we will consider that a falling domino exp
//ends no additional force to a falling or already fallen domino. 
//
// You are given a string dominoes representing the initial state where: 
//
// 
// dominoes[i] = 'L', if the ith domino has been pushed to the left, 
// dominoes[i] = 'R', if the ith domino has been pushed to the right, and 
// dominoes[i] = '.', if the ith domino has not been pushed. 
// 
//
// Return a string representing the final state. 
//
// 
// Example 1: 
//
// 
//Input: dominoes = "RR.L"
//Output: "RR.L"
//Explanation: The first domino expends no additional force on the second domino
//.
// 
//
// Example 2: 
//
// 
//Input: dominoes = ".L.R...LR..L.."
//Output: "LL.RR.LLRRLL.."
// 
//
// 
// Constraints: 
//
// 
// n == dominoes.length 
// 1 <= n <= 105 
// dominoes[i] is either 'L', 'R', or '.'. 
// 
// Related Topics Two Pointers String Dynamic Programming 
// 👍 1071 👎 84
	

#include <iostream>
#include <string>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string threeNSolution(string dominoes) {
        int lo = 0, hi, n = dominoes.size();
        while(lo < n) {
            while(lo < n && dominoes[lo] == '.') {
                ++lo;
            }
            hi = lo+1;
            while(hi < n && dominoes[hi] == '.') {
                ++hi;
            }
            if(hi == n) break;
            if(dominoes[lo] == dominoes[hi]) {
                for(int i=lo; i<=hi; ++i)
                    dominoes[i] = dominoes[lo];
            } else if(dominoes[lo] == 'R' && dominoes[hi] == 'L') {
                int mid = lo + (hi - lo) / 2;
                for(int i=lo; i<=mid; ++i)
                    dominoes[i] = 'R';
                for(int i=mid+1; i<=hi; ++i)
                    dominoes[i] = 'L';
                // if odd
                if((hi - lo - 1) % 2 == 1) dominoes[mid] = '.';
            }
            lo = hi;
        }

        for(int i=0; i<n; ++i)
            if(dominoes[i] == 'R') break;
            else if(dominoes[i] == 'L') {
                for(int j=0; j<i; ++j)
                    dominoes[j] = 'L';
                break;
            }
        for(int i=n-1; i>=0; --i)
            if(dominoes[i] == 'L') break;
            else if(dominoes[i] == 'R') {
                for(int j=n-1; j>i; --j)
                    dominoes[j] = 'R';
                break;
            }
        return dominoes;
    }
    string pushDominoes(string dominoes) {
        char prev = 'L';
        int cur = 0, prev_idx = -1, n = dominoes.size();
        while(cur < n) {
            if(dominoes[cur] == '.') {
                ++cur;
            } else {
                if(dominoes[cur] == 'L') {
                    if(prev == 'L') {
                        for(int i=prev_idx+1; i<=cur; ++i)
                            dominoes[i] = 'L';
                    } else {
                        int head = prev_idx + 1, tail = cur - 1;
                        while(head < tail) {
                            dominoes[head++] = 'R';
                            dominoes[tail--] = 'L';
                        }
                    }
                    prev_idx = cur;
                    prev = 'L';
                } else {
                    if(prev == 'R') {
                        for(int i=prev_idx+1; i<=cur; ++i)
                            dominoes[i] = 'R';
                    }
                    prev_idx = cur;
                    prev = 'R';
                }
                ++cur;
            }
        }
        if(prev == 'R') {
            for(int i=prev_idx+1; i<n; ++i)
                dominoes[i] = 'R';
        }
        return dominoes;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    solution.pushDominoes(".L.R...LR..L.L");
    return 0;
}