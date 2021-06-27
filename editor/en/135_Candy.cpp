//There are n children standing in a line. Each child is assigned a rating value
// given in the integer array ratings. 
//
// You are giving candies to these children subjected to the following requireme
//nts: 
//
// 
// Each child must have at least one candy. 
// Children with a higher rating get more candies than their neighbors. 
// 
//
// Return the minimum number of candies you need to have to distribute the candi
//es to the children. 
//
// 
// Example 1: 
//
// 
//Input: ratings = [1,0,2]
//Output: 5
//Explanation: You can allocate to the first, second and third child with 2, 1, 
//2 candies respectively.
// 
//
// Example 2: 
//
// 
//Input: ratings = [1,2,2]
//Output: 4
//Explanation: You can allocate to the first, second and third child with 1, 2, 
//1 candies respectively.
//The third child gets 1 candy because it satisfies the above two conditions.
// 
//
// 
// Constraints: 
//
// 
// n == ratings.length 
// 1 <= n <= 2 * 104 
// 0 <= ratings[i] <= 2 * 104 
// 
// Related Topics Array Greedy 
// 👍 1740 👎 205


#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
static int x = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return 0;}();
class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty()) return 0;
        vector<int> v(ratings.size(), 1);
        for(int i=0; i<ratings.size() - 1; ++i) {
            if(ratings[i+1] > ratings[i]) {
                v[i+1] = v[i] + 1;
            }
        }
        for(int i=ratings.size()-1; i>0; --i) {
            if(ratings[i-1] > ratings[i]) {
                v[i-1] = max(v[i-1], v[i] + 1);
            }
        }
        return accumulate(v.begin(), v.end(), 0);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> ratings = {1,0,2};
    solution.candy(ratings);
    return 0;
}