//There are a total of numCourses courses you have to take, labeled from 0 to nu
//mCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai,
// bi] indicates that you must take course bi first if you want to take course ai.
// 
//
// 
// For example, the pair [0, 1], indicates that to take course 0 you have to fir
//st take course 1. 
// 
//
// Return true if you can finish all courses. Otherwise, return false. 
//
// 
// Example 1: 
//
// 
//Input: numCourses = 2, prerequisites = [[1,0]]
//Output: true
//Explanation: There are a total of 2 courses to take. 
//To take course 1 you should have finished course 0. So it is possible.
// 
//
// Example 2: 
//
// 
//Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
//Output: false
//Explanation: There are a total of 2 courses to take. 
//To take course 1 you should have finished course 0, and to take course 0 you s
//hould also have finished course 1. So it is impossible.
// 
//
// 
// Constraints: 
//
// 
// 1 <= numCourses <= 105 
// 0 <= prerequisites.length <= 5000 
// prerequisites[i].length == 2 
// 0 <= ai, bi < numCourses 
// All the pairs prerequisites[i] are unique. 
// 
// Related Topics Depth-first Search Breadth-first Search Graph Topological Sort
// 
// 👍 5434 👎 224


#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isCycle(vector<vector<int>> &graph, int &course, vector<bool> &path, vector<bool> &visited) {
        if(visited[course]) return path[course];
        visited[course] = path[course] = true;
        for(auto &c: graph[course]) {
            if(isCycle(graph, c, path, visited)) return true;
        }
        path[course] = false;
        return false;
    }
    bool dfsSolution(int &numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto &course: prerequisites) graph[course.back()].push_back(course.front());
        vector<bool> path(numCourses), visited(numCourses);
        for(int i=0; i<numCourses; ++i) {
            if(isCycle(graph, i, path, visited)) return false;
        }
        return true;
    }
    bool topologicalSortSolution(int &numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> in_degree(numCourses, 0);
        for(auto &edge: prerequisites) {
            graph[edge.back()].push_back(edge.front());
            ++in_degree[edge.front()];
        }
        queue<int> q;
        for(int i=0; i<numCourses; ++i)
            if(in_degree[i] == 0) q.push(i);
        int total = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ++total;
            for(auto &v: graph[node]) {
                if(--in_degree[v] == 0)
                    q.push(v);
            }
        }
        return total == numCourses;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        return dfsSolution(numCourses, prerequisites);
//        return topologicalSortSolution(numCourses, prerequisites);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<vector<int>> prerequisites = {{1,0}, {0,1}, {2, 3}};
    solution.canFinish(4, prerequisites);
    return 0;
}