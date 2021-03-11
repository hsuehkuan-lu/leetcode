//Given an array of points where points[i] = [xi, yi] represents a point on the 
//X-Y plane and an integer k, return the k closest points to the origin (0, 0). 
//
// The distance between two points on the X-Y plane is the Euclidean distance (i
//.e, √(x1 - x2)2 + (y1 - y2)2). 
//
// You may return the answer in any order. The answer is guaranteed to be unique
// (except for the order that it is in). 
//
// 
// Example 1: 
//
// 
//Input: points = [[1,3],[-2,2]], k = 1
//Output: [[-2,2]]
//Explanation:
//The distance between (1, 3) and the origin is sqrt(10).
//The distance between (-2, 2) and the origin is sqrt(8).
//Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
//We only want the closest k = 1 points from the origin, so the answer is just [
//[-2,2]].
// 
//
// Example 2: 
//
// 
//Input: points = [[3,3],[5,-1],[-2,4]], k = 2
//Output: [[3,3],[-2,4]]
//Explanation: The answer [[-2,4],[3,3]] would also be accepted.
// 
//
// 
// Constraints: 
//
// 
// 1 <= k <= points.length <= 104 
// -104 < xi, yi < 104 
// 
// Related Topics Divide and Conquer Heap Sort 
// 👍 2796 👎 146


#include <iostream>
#include <utility>
#include <cmath>
#include <queue>
#include <map>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
struct Compare {
    constexpr bool operator()(pair<double, vector<int>> const &a, pair<double, vector<int>> const &b) const noexcept {
        return a.first > b.first;
    }
};
class Solution {
public:
    static double distance(vector<int> &point) {
        return sqrt(pow(point.front(), 2) + pow(point.back(), 2));
    }
    vector<vector<int>> priorityQueueSolution(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, Compare> Q;
        for(auto &i: points) {
            Q.push(make_pair<double, vector<int>>(distance(i), static_cast<vector<int, allocator<int>> &&>(i)));
        }
        vector<vector<int>> v;
        for(int i=0; i<k; ++i) {
            v.push_back(Q.top().second);
            Q.pop();
        }
        return v;
    }
    vector<vector<int>> mapSolution(vector<vector<int>>& points, int k) {
        map<double, vector<vector<int>>> mp;
        vector<vector<int>> v;
        for(auto &i: points)
            mp[distance(i)].push_back(i);
        int i = 0;
        for(auto &it : mp) {
            for(auto &point: it.second) {
                if(i == k) break;
                v.push_back(point);
                ++i;
            }
        }
        return v;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        return mapSolution(points, k);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<vector<int>> points = {{10, 8}, {1, 5}, {2, 2}};
    solution.kClosest(points, 2);
    return 0;
}