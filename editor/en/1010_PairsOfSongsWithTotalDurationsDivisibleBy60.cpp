//You are given a list of songs where the ith song has a duration of time[i] sec
//onds. 
//
// Return the number of pairs of songs for which their total duration in seconds
// is divisible by 60. Formally, we want the number of indices i, j such that i < 
//j with (time[i] + time[j]) % 60 == 0. 
//
// 
// Example 1: 
//
// 
//Input: time = [30,20,150,100,40]
//Output: 3
//Explanation: Three pairs have a total duration divisible by 60:
//(time[0] = 30, time[2] = 150): total duration 180
//(time[1] = 20, time[3] = 100): total duration 120
//(time[1] = 20, time[4] = 40): total duration 60
// 
//
// Example 2: 
//
// 
//Input: time = [60,60,60]
//Output: 3
//Explanation: All three pairs have a total duration of 120, which is divisible 
//by 60.
// 
//
// 
// Constraints: 
//
// 
// 1 <= time.length <= 6 * 104 
// 1 <= time[i] <= 500 
// 
// Related Topics Array 
// 👍 1352 👎 81


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int nSquareSolution(vector<int> &time) {
        int cnt = 0, n = time.size();
        for(int i=0; i<n; ++i) {
            for(int j=i+1; j<n; ++j) {
                if((time[i] + time[j]) % 60 == 0)
                    ++cnt;
            }
        }
        return cnt;
    }
    int linearSolution(vector<int> &time) {
        int arr[61];
        memset(arr, 0, sizeof(arr));
        int cnt = 0;
        for(auto &i: time) {
            int mod = i % 60;
            cnt += arr[(60 - mod) % 60];
            ++arr[mod];
        }
        return cnt;
    }
    int numPairsDivisibleBy60(vector<int>& time) {
        int arr[61];
        memset(arr, 0, sizeof(arr));
        int cnt = 0;
        for(auto &i: time) {
            int mod = i % 60;
            cnt += arr[(60 - mod) % 60];
            ++arr[mod];
        }
        return cnt;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> v={30,20,150,272,40};
    solution.numPairsDivisibleBy60(v);
    return 0;
}