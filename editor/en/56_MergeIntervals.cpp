//Given an array of intervals where intervals[i] = [starti, endi], merge all ove
//rlapping intervals, and return an array of the non-overlapping intervals that co
//ver all the intervals in the input. 
//
// 
// Example 1: 
//
// 
//Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
//Output: [[1,6],[8,10],[15,18]]
//Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
// 
//
// Example 2: 
//
// 
//Input: intervals = [[1,4],[4,5]]
//Output: [[1,5]]
//Explanation: Intervals [1,4] and [4,5] are considered overlapping.
// 
//
// 
// Constraints: 
//
// 
// 1 <= intervals.length <= 104 
// intervals[i].length == 2 
// 0 <= starti <= endi <= 104 
// 
// Related Topics Array Sort 
// 👍 6677 👎 364


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        /*
         * Declare custom C++ sort comparator to sort in different data types,
         * similar to Python sort with lambda.
         * Algorithm first sort the intervals based on the start value,
         * then iterate the sorted intervals, and dynamically merge the intervals
         * on intervals[i].end, intervals[i].start for i in intervals.size()
         */
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b){
            return a.front() < b.front();
        });
        vector<vector<int>> ans;
        for(int i=0; i<intervals.size(); ++i) {
            int start = intervals[i].front();
            int end = intervals[i].back();
            while(i<intervals.size()-1 && end >= intervals[i+1].front()) {
                end = max(end, intervals[i+1].back());
                ++i;
            }
            ans.push_back({start, end});
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    return 0;
}