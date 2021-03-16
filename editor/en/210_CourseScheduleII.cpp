//There are a total of n courses you have to take labelled from 0 to n - 1. 
//
// Some courses may have prerequisites, for example, if prerequisites[i] = [ai, 
//bi] this means you must take the course bi before the course ai. 
//
// Given the total number of courses numCourses and a list of the prerequisite p
//airs, return the ordering of courses you should take to finish all courses. 
//
// If there are many valid answers, return any of them. If it is impossible to f
//inish all courses, return an empty array. 
//
// 
// Example 1: 
//
// 
//Input: numCourses = 2, prerequisites = [[1,0]]
//Output: [0,1]
//Explanation: There are a total of 2 courses to take. To take course 1 you shou
//ld have finished course 0. So the correct course order is [0,1].
// 
//
// Example 2: 
//
// 
//Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
//Output: [0,2,1,3]
//Explanation: There are a total of 4 courses to take. To take course 3 you shou
//ld have finished both courses 1 and 2. Both courses 1 and 2 should be taken afte
//r you finished course 0.
//So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3
//].
// 
//
// Example 3: 
//
// 
//Input: numCourses = 1, prerequisites = []
//Output: [0]
// 
//
// 
// Constraints: 
//
// 
// 1 <= numCourses <= 2000 
// 0 <= prerequisites.length <= numCourses * (numCourses - 1) 
// prerequisites[i].length == 2 
// 0 <= ai, bi < numCourses 
// ai != bi 
// All the pairs [ai, bi] are distinct. 
// 
// Related Topics Depth-first Search Breadth-first Search Graph Topological Sort
// 
// 👍 3442 👎 162


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> topologicalSortSolution(int &numCourses, vector<vector<int>> &prerequisites) {
        /*
         * n courses labeled from 0 to n-1
         * prerequisites = [course, prerequisite]
         * 0 -> 1
         * in_degree: '0' = 0, '1' = 1
         * in_degree means the number of vertices indicate to the node.
         */
        vector<int> ans;
        if(prerequisites.empty()) {
            for(int i=0; i<numCourses; ++i)
                ans.push_back(i);
            return ans;
        }
        vector<vector<int>> graph(numCourses);
        vector<int> in_degree(numCourses, 0);
        for(auto &edge: prerequisites) {
            graph[edge.back()].push_back(edge.front());
            ++in_degree[edge.front()];
        }
        queue<int> q;
        for(int i=0; i<numCourses; ++i)
            if(in_degree[i] == 0) q.push(i);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto &v: graph[node]) {
                if(--in_degree[v] == 0)
                    q.push(v);
            }
        }
        if(ans.size() == numCourses)
            return ans;
        else
            return {};
    }
    bool isCycle(vector<vector<int>> &graph, int &course, vector<bool> &visited, vector<bool> &path,
                   vector<int> &ans) {
        if(visited[course]) return path[course];
        visited[course] = path[course] = true;
        for(auto &v: graph[course]) {
            if(isCycle(graph, v, visited, path, ans)) return true;
        }
        path[course] = false;
        ans.push_back(course);
        return false;
    }
    vector<int> dfsSolution(int &numCourses, vector<vector<int>> &prerequisites) {
        vector<int> ans;
        // first check if there is any prerequisites, if none then return numCourses
        if(prerequisites.empty()) {
            for(int i=0; i<numCourses; ++i) ans.push_back(i);
            return ans;
        }
        // build graph
        vector<vector<int>> graph(numCourses);
        vector<bool> visited(numCourses), path(numCourses);
        for(auto &edge: prerequisites)
            graph[edge.back()].push_back(edge.front());
        for(int i=0; i<numCourses; ++i) {
            if(isCycle(graph, i, visited, path, ans))
                return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//        return topologicalSortSolution(numCourses, prerequisites);
        return dfsSolution(numCourses, prerequisites);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<vector<int>> prerequisites = {{1,0}, {2,0}, {3,1}, {3,2}};
    solution.findOrder(4, prerequisites);
    return 0;
}