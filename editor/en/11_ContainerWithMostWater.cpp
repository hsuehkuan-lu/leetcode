//Given n non-negative integers a1, a2, ..., an , where each represents a point 
//at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of
// the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x
//-axis forms a container, such that the container contains the most water. 
//
// Notice that you may not slant the container. 
//
// 
// Example 1: 
//
// 
//Input: height = [1,8,6,2,5,4,8,3,7]
//Output: 49
//Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,
//3,7]. In this case, the max area of water (blue section) the container can conta
//in is 49.
// 
//
// Example 2: 
//
// 
//Input: height = [1,1]
//Output: 1
// 
//
// Example 3: 
//
// 
//Input: height = [4,3,2,1,4]
//Output: 16
// 
//
// Example 4: 
//
// 
//Input: height = [1,2,1]
//Output: 2
// 
//
// 
// Constraints: 
//
// 
// n == height.length 
// 2 <= n <= 105 
// 0 <= height[i] <= 104 
// 
// Related Topics Array Two Pointers 
// 👍 9966 👎 734


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
static int x = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return 0;}();
class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo = 0, hi = height.size() - 1;
        int area = 0;
        while(lo <= hi) {
            if(height[lo] >= height[hi]) {
                area = max(area, height[hi] * (hi - lo));
                --hi;
            } else {
                area = max(area, height[lo] * (hi - lo));
                ++lo;
            }
        }
        return area;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> v = {4,3,2,1,4};
    solution.maxArea(v);
    return 0;
}