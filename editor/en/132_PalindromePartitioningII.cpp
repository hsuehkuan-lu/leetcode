//Given a string s, partition s such that every substring of the partition is a 
//palindrome. 
//
// Return the minimum cuts needed for a palindrome partitioning of s. 
//
// 
// Example 1: 
//
// 
//Input: s = "aab"
//Output: 1
//Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 
//cut.
// 
//
// Example 2: 
//
// 
//Input: s = "a"
//Output: 0
// 
//
// Example 3: 
//
// 
//Input: s = "ab"
//Output: 1
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 2000 
// s consists of lower-case English letters only. 
// 
// Related Topics String Dynamic Programming 
// 👍 2299 👎 64
	

#include <iostream>
#include <string>
#include <queue>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
//    bool isPalindrome(string &s, int lo, int hi) {
//        while(lo < hi) {
//            if(s[lo++] != s[hi--]) return false;
//        }
//        return true;
//    }
//    int bfs(string s) {
//        int level = 0, n = s.size();
//        vector<bool> visited(n);
//        queue<int> start, next;
//        start.push(0);
//        while(!start.empty()) {
//            while(!start.empty()) {
//                auto lo = start.front();
//                start.pop();
//                visited[lo] = true;
//                if(isPalindrome(s, lo, n-1)) return level;
//                for(int hi=lo; hi<n; ++hi) {
//                    if(!visited[hi+1] && isPalindrome(s, lo, hi)) {
//                        next.push(hi+1);
//                    }
//                }
//            }
//            swap(start, next);
//            ++level;
//        }
//        return level;
//    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n);
        vector<vector<bool>> is_palindrome(n, vector<bool>(n, false));
        for(int hi=0; hi<n; ++hi) {
            int min_cut = hi;
            for(int lo=0; lo<=hi; ++lo) {
                if(s[lo] == s[hi] && (hi - lo <= 2 || is_palindrome[lo+1][hi-1])) {
                    is_palindrome[lo][hi] = true;
                    min_cut = lo == 0 ? 0 : min(min_cut, 1 + dp[lo-1]);
                }
            }
            dp[hi] = min_cut;
        }
        return dp[n-1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    cout << solution.minCut("apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp");
    return 0;
}