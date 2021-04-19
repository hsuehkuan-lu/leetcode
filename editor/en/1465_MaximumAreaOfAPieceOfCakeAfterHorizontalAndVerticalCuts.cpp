//Given a rectangular cake with height h and width w, and two arrays of integers
// horizontalCuts and verticalCuts where horizontalCuts[i] is the distance from th
//e top of the rectangular cake to the ith horizontal cut and similarly, verticalC
//uts[j] is the distance from the left of the rectangular cake to the jth vertical
// cut. 
//
// Return the maximum area of a piece of cake after you cut at each horizontal a
//nd vertical position provided in the arrays horizontalCuts and verticalCuts. Sin
//ce the answer can be a huge number, return this modulo 10^9 + 7. 
//
// 
// Example 1: 
//
// 
//
// 
//Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
//Output: 4 
//Explanation: The figure above represents the given rectangular cake. Red lines
// are the horizontal and vertical cuts. After you cut the cake, the green piece o
//f cake has the maximum area.
// 
//
// Example 2: 
//
// 
//
// 
//Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
//Output: 6
//Explanation: The figure above represents the given rectangular cake. Red lines
// are the horizontal and vertical cuts. After you cut the cake, the green and yel
//low pieces of cake have the maximum area.
// 
//
// Example 3: 
//
// 
//Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
//Output: 9
// 
//
// 
// Constraints: 
//
// 
// 2 <= h, w <= 10^9 
// 1 <= horizontalCuts.length < min(h, 10^5) 
// 1 <= verticalCuts.length < min(w, 10^5) 
// 1 <= horizontalCuts[i] < h 
// 1 <= verticalCuts[i] < w 
// It is guaranteed that all elements in horizontalCuts are distinct. 
// It is guaranteed that all elements in verticalCuts are distinct. 
// 
// Related Topics Array 
// 👍 309 👎 120


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    const unsigned int mod = 1000000007;
public:
    int sortSolution(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int m = max(horizontalCuts[0], h - horizontalCuts.back()), n = max(verticalCuts[0], w - verticalCuts.back());
        for(int i=0; i<horizontalCuts.size()-1; ++i)
            m = max(m, horizontalCuts[i+1] - horizontalCuts[i]);
        for(int i=0; i<verticalCuts.size()-1; ++i)
            n = max(n, verticalCuts[i+1] - verticalCuts[i]);
        return (long)m * n % 1000000007;
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int m = max(horizontalCuts[0], h - horizontalCuts.back()), n = max(verticalCuts[0], w - verticalCuts.back());
        for(int i=0; i<horizontalCuts.size()-1; ++i)
            m = max(m, horizontalCuts[i+1] - horizontalCuts[i]);
        for(int i=0; i<verticalCuts.size()-1; ++i)
            n = max(n, verticalCuts[i+1] - verticalCuts[i]);
        return ((long)m * n) % mod;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    return 0;
}