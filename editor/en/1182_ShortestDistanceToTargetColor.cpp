//You are given an array colors, in which there are three colors: 1, 2 and 3. 
//
// You are also given some queries. Each query consists of two integers i and c,
// return the shortest distance between the given index i and the target color c. 
//If there is no solution return -1. 
//
// 
// Example 1: 
//
// 
//Input: colors = [1,1,2,1,3,2,2,3,3], queries = [[1,3],[2,2],[6,1]]
//Output: [3,0,3]
//Explanation: 
//The nearest 3 from index 1 is at index 4 (3 steps away).
//The nearest 2 from index 2 is at index 2 itself (0 steps away).
//The nearest 1 from index 6 is at index 3 (3 steps away).
// 
//
// Example 2: 
//
// 
//Input: colors = [1,2], queries = [[0,3]]
//Output: [-1]
//Explanation: There is no 3 in the array.
// 
//
// 
// Constraints: 
//
// 
// 1 <= colors.length <= 5*10^4 
// 1 <= colors[i] <= 3 
// 1 <= queries.length <= 5*10^4 
// queries[i].length == 2 
// 0 <= queries[i][0] < colors.length 
// 1 <= queries[i][1] <= 3 
// 
// Related Topics Binary Search 
// 👍 225 👎 7


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
static int x = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return 0;}();
class Solution {
public:
    int binarySearch(vector<int> &v, const int &idx) {
        if(v.empty()) return -1;
        int left = 0, right = v.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(v[mid] >= idx) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if(left == 0) return abs(v[left] - idx);
        else return abs(v[left] - idx) > abs(idx - v[left-1]) ? abs(idx - v[left-1]) : abs(v[left] - idx);
    }
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<vector<int>> mp(3, vector<int>());
        for(int i=0; i<colors.size(); ++i)
            mp[colors[i]-1].push_back(i);
        vector<int> ans;
        ans.reserve(queries.size());
        for(auto &q: queries) {
            ans.push_back(binarySearch(mp[q.back()-1], q.front()));
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> colors = {1,1,2,1,3,2,2,3,3};
    vector<vector<int>> q = {{1,3},{2,2},{6,1}};
//    vector<int> colors = {2,1,2,2,1};
//    vector<vector<int>> q = {{2,1}};
    solution.shortestDistanceColor(colors, q);
    return 0;
}