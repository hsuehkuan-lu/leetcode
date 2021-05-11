//There are several cards arranged in a row, and each card has an associated num
//ber of points The points are given in the integer array cardPoints. 
//
// In one step, you can take one card from the beginning or from the end of the 
//row. You have to take exactly k cards. 
//
// Your score is the sum of the points of the cards you have taken. 
//
// Given the integer array cardPoints and the integer k, return the maximum scor
//e you can obtain. 
//
// 
// Example 1: 
//
// 
//Input: cardPoints = [1,2,3,4,5,6,1], k = 3
//Output: 12
//Explanation: After the first step, your score will always be 1. However, choos
//ing the rightmost card first will maximize your total score. The optimal strateg
//y is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 1
//2.
// 
//
// Example 2: 
//
// 
//Input: cardPoints = [2,2,2], k = 2
//Output: 4
//Explanation: Regardless of which two cards you take, your score will always be
// 4.
// 
//
// Example 3: 
//
// 
//Input: cardPoints = [9,7,7,9,7,7,9], k = 7
//Output: 55
//Explanation: You have to take all the cards. Your score is the sum of points o
//f all cards.
// 
//
// Example 4: 
//
// 
//Input: cardPoints = [1,1000,1], k = 1
//Output: 1
//Explanation: You cannot take the card in the middle. Your best score is 1. 
// 
//
// Example 5: 
//
// 
//Input: cardPoints = [1,79,80,1,1,1,200,1], k = 3
//Output: 202
// 
//
// 
// Constraints: 
//
// 
// 1 <= cardPoints.length <= 10^5 
// 1 <= cardPoints[i] <= 10^4 
// 1 <= k <= cardPoints.length 
// 
// Related Topics Array Dynamic Programming Sliding Window 
// 👍 1431 👎 66


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
static int x = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return 0;}();
class Solution {
public:
    int slidingWindowSolution(vector<int> &cardPoints, int k) {
        int sum = 0, max_point;
        for(int i=0; i<k; ++i) {
            sum += cardPoints[i];
        }
        max_point = sum;
        int i = cardPoints.size() - 1;
        while(k > 0) {
            sum += cardPoints[i--] - cardPoints[--k];
            max_point = max(max_point, sum);
        }
        return max_point;
    }
    int maxScore(vector<int>& cardPoints, int k) {
        return slidingWindowSolution(cardPoints, k);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> v = {1,2,3,4,5,6,1};
    solution.maxScore(v, 3);
    return 0;
}