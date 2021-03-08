//Given an array of meeting time intervals intervals where intervals[i] = [start
//i, endi], return the minimum number of conference rooms required. 
//
// 
// Example 1: 
// Input: intervals = [[0,30],[5,10],[15,20]]
//Output: 2
// Example 2: 
// Input: intervals = [[7,10],[2,4]]
//Output: 1
// 
// 
// Constraints: 
//
// 
// 1 <= intervals.length <= 104 
// 0 <= starti < endi <= 106 
// 
// Related Topics Heap Greedy Sort 
// 👍 3508 👎 57


#include <iostream>
#include <vector>
#include <map>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> mp;
        for(auto &i: intervals) {
            ++mp[i[0]];
            --mp[i[1]];
        }
        int cnt = 0, max_cnt = 0;
        for(auto &i: mp) {
            cnt += i.second;
            max_cnt = max(cnt, max_cnt);
        }
        return max_cnt;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    return 0;
}