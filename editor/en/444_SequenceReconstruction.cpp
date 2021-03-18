//Check whether the original sequence org can be uniquely reconstructed from the
// sequences in seqs. The org sequence is a permutation of the integers from 1 to 
//n, with 1 ≤ n ≤ 104. Reconstruction means building a shortest common supersequen
//ce of the sequences in seqs (i.e., a shortest sequence so that all sequences in 
//seqs are subsequences of it). Determine whether there is only one sequence that 
//can be reconstructed from seqs and it is the org sequence. 
//
// 
// Example 1: 
//
// 
//Input: org = [1,2,3], seqs = [[1,2],[1,3]]
//Output: false
//Explanation: [1,2,3] is not the only one sequence that can be reconstructed, b
//ecause [1,3,2] is also a valid sequence that can be reconstructed.
// 
//
// Example 2: 
//
// 
//Input: org = [1,2,3], seqs = [[1,2]]
//Output: false
//Explanation: The reconstructed sequence can only be [1,2].
// 
//
// Example 3: 
//
// 
//Input: org = [1,2,3], seqs = [[1,2],[1,3],[2,3]]
//Output: true
//Explanation: The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct th
//e original sequence [1,2,3].
// 
//
// Example 4: 
//
// 
//Input: org = [4,1,5,2,6,3], seqs = [[5,2,6,3],[4,1,5,2]]
//Output: true
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 10^4 
// org is a permutation of {1,2,...,n}. 
// 1 <= segs[i].length <= 10^5 
// seqs[i][j] fits in a 32-bit signed integer. 
// 
//
// 
//
// UPDATE (2017/1/8): 
//The seqs parameter had been changed to a list of list of strings (instead of a
// 2d array of strings). Please reload the code definition to get the latest chang
//es. 
// Related Topics Graph Topological Sort 
// 👍 357 👎 1193


#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int n;
    bool topologicalSortSolution(vector<int> &org, vector<vector<int>> &seqs) {
        if(seqs.empty()) return false;
        // init graph first
        vector<vector<int>> graph(n+1);
        vector<int> in_degree(n+1);
        for(auto &seq: seqs) {
            for(int i=0; i<seq.size()-1; ++i) {
                graph[seq[i]].push_back(seq[i+1]);
                ++in_degree[seq[i+1]];
            }
        }
        // put every zero in_degree node to queue, and iterate through all nodes
        queue<int> q;
//        for(int i=1; i<=n; ++i)
//            if(in_degree[i] == 0) q.push(i);
        int cnt = 1;
        q.push(org[0]);
        // iterate
        for(int i=1; i<n; ++i) {
            if(q.empty()) return false;
            int node = q.front();
            q.pop();
            for(auto &p: graph[node]) {
                if(p == org[i]) {
                    q.push(p);
                    ++cnt;
                }
            }
        }
        return cnt == n;
    }
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        n = org.size();
        return topologicalSortSolution(org, seqs);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<int> org = {1,2,3};
    vector<vector<int>> seqs = {{1,2}, {1,3}};
    solution.sequenceReconstruction(org, seqs);
    return 0;
}