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
#include <queue>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int solveMinMeetingRoomsWithPriorityQueue(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            return a.front() < b.front();
        });
        priority_queue<int, vector<int>, greater<>> min_heap;
        min_heap.push(intervals[0].back());
        for(int i=1; i<intervals.size(); ++i) {
            if(intervals[i].front() >= min_heap.top())
                min_heap.pop();
            min_heap.push(intervals[i].back());
        }
        return min_heap.size();
    }
    int solveMinMeetingRoomsWithMap(vector<vector<int>>& intervals) {
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
    int minMeetingRooms(vector<vector<int>>& intervals) {
        return solveMinMeetingRoomsWithPriorityQueue(intervals);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    return 0;
}