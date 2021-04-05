//
//Given a list of daily temperatures T, return a list such that, for each day in
// the input, tells you how many days you would have to wait until a warmer temper
//ature. If there is no future day for which this is possible, put 0 instead.
// 
//For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 7
//3], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
// 
//
// Note:
//The length of temperatures will be in the range [1, 30000].
//Each temperature will be an integer in the range [30, 100].
// Related Topics Hash Table Stack 
// 👍 4038 👎 123


#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> stackSolution(vector<int> &T) {
        vector<int> v(T.size(), 0);
        // temp, index
        stack<pair<int, int>> s;
        for(int i=0; i<T.size(); ++i) {
            if(!s.empty() && s.top().first < T[i]) {
                while(!s.empty() && s.top().first < T[i]) {
                    v[s.top().second] = i - s.top().second;
                    s.pop();
                }
            }
            s.push(make_pair(T[i], i));
        }
        return v;
    }
    vector<int> bruteForceSolution(vector<int> &T) {
        vector<int> v;
        for(int i=0; i<T.size(); ++i) {
            int ans = 0;
            for(int j=i+1; j<T.size(); ++j) {
                if(T[j] > T[i]) {
                    ans = j - i;
                    break;
                }
            }
            v.push_back(ans);
        }
        return v;
    }
    vector<int> dailyTemperatures(vector<int>& T) {
        return stackSolution(T);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> T = {73,74,75,71,69,72,76,73};
    solution.dailyTemperatures(T);
    return 0;
}