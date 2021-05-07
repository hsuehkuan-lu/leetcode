//Given a characters array tasks, representing the tasks a CPU needs to do, wher
//e each letter represents a different task. Tasks could be done in any order. Eac
//h task is done in one unit of time. For each unit of time, the CPU could complet
//e either one task or just be idle. 
//
// However, there is a non-negative integer n that represents the cooldown perio
//d between two same tasks (the same letter in the array), that is that there must
// be at least n units of time between any two same tasks. 
//
// Return the least number of units of times that the CPU will take to finish al
//l the given tasks. 
//
// 
// Example 1: 
//
// 
//Input: tasks = ["A","A","A","B","B","B"], n = 2
//Output: 8
//Explanation: 
//A -> B -> idle -> A -> B -> idle -> A -> B
//There is at least 2 units of time between any two same tasks.
// 
//
// Example 2: 
//
// 
//Input: tasks = ["A","A","A","B","B","B"], n = 0
//Output: 6
//Explanation: On this case any permutation of size 6 would work since n = 0.
//["A","A","A","B","B","B"]
//["A","B","A","B","A","B"]
//["B","B","B","A","A","A"]
//...
//And so on.
// 
//
// Example 3: 
//
// 
//Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
//Output: 16
//Explanation: 
//One possible solution is
//A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle ->
// idle -> A
// 
//
// 
// Constraints: 
//
// 
// 1 <= task.length <= 104 
// tasks[i] is upper-case English letter. 
// The integer n is in the range [0, 100]. 
// 
// Related Topics Array Greedy Queue 
// 👍 4724 👎 898


#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
static int x = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return 0;}();
class Solution {
public:
    int idleTimeSolution(vector<char> &tasks, int n) {
        int arr[26] = {0};
        for(auto &ch: tasks) ++arr[ch - 'A'];
        sort(begin(arr), end(arr), greater<>());
        int i = 25;
        while(arr[i] != arr[0]) --i;
        int ans = (arr[0] - 1) * (n + 1) + i + 1;
        return max((int)tasks.size(), ans);
    }
    int priorityQueueSolution(vector<char>& tasks, int n) {
        int arr[26];
        memset(arr, 0, sizeof(arr));
        for (auto &ch: tasks) ++arr[ch - 'A'];
        priority_queue<int> max_heap;
        for (auto &i: arr) if (i) max_heap.push(i);
        int cnt = 0, cycle = n + 1;
        while (!max_heap.empty()) {
            queue<int> q;
            for (int i = 0; i < cycle; ++i) {
                if (!max_heap.empty()) {
                    q.push(max_heap.top());
                    max_heap.pop();
                }
            }
            int sz = q.size();
            while (!q.empty()) {
                if (--q.front() > 0) {
                    max_heap.push(q.front());
                }
                q.pop();
            }
            cnt += max_heap.empty() ? sz : cycle;
        }
        return cnt;
    }
    int leastInterval(vector<char>& tasks, int n) {
        return idleTimeSolution(tasks, n);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<char> v = {'A', 'A','A','B','B','B'};
    solution.leastInterval(v, 0);
    return 0;
}