//Given an m x n grid of characters board and a string word, return true if word
// exists in the grid. 
//
// The word can be constructed from letters of sequentially adjacent cells, wher
//e adjacent cells are horizontally or vertically neighboring. The same letter cel
//l may not be used more than once. 
//
// Note: There will be some test cases with a board or a word larger than constr
//aints to test if your solution is using pruning. 
//
// 
// Example 1: 
//
// 
//Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
// "ABCCED"
//Output: true
// 
//
// Example 2: 
//
// 
//Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
// "SEE"
//Output: true
// 
//
// Example 3: 
//
// 
//Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
// "ABCB"
//Output: false
// 
//
// 
// Constraints: 
//
// 
// m == board.length 
// n = board[i].length 
// 1 <= m, n <= 6 
// 1 <= word.length <= 15 
// board and word consists of only lowercase and uppercase English letters. 
// 
// Related Topics Array Backtracking 
// 👍 5321 👎 235


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    int m, n;
public:
    bool optimizeDFS(vector<vector<char>> &board, string &word, int x, int y, int depth) {
        if(depth == word.length() - 1) return true;
        bool exists = false;
        int rows[] = {0, 1, 0, -1};
        int cols[] = {1, 0, -1, 0};
        for(int i=0; i<4; ++i){
            int xi = x + rows[i], yj = y + cols[i];
            if (xi >= 0 && xi < m && yj >= 0 && yj < n)
                if (board[xi][yj] == word[depth + 1]) {
                    board[xi][yj] = '#';
                    exists |= optimizeDFS(board, word, xi, yj, depth + 1);
                    board[xi][yj] = word[depth + 1];
                }
            if(exists) break;
        }
        return exists;
    }

    bool dfs(vector<vector<char>> &board, string &word, int x, int y, int depth, vector<vector<bool>> &visited) {
        if(depth == word.length() - 1) return true;
        bool exists = false;
        int rows[] = {0, 1, 0, -1};
        int cols[] = {1, 0, -1, 0};
        for(int i=0; i<4; ++i){
            int xi = x + rows[i], yj = y + cols[i];
            if (xi >= 0 && xi < m && yj >= 0 && yj < n)
                if (!visited[xi][yj] && board[xi][yj] == word[depth + 1]) {
                    visited[xi][yj] = true;
                    exists |= dfs(board, word, xi, yj, depth + 1, visited);
                    visited[xi][yj] = false;
                }
            if(exists) break;
        }
        return exists;
    }

    bool visit(vector<vector<char>> &board, string &word, int x, int y, vector<vector<bool>> visited) {
        int position = 1;
        while(position < word.length()) {
            bool found = false;
            for(int i=-1; i<=1; i+=2) {
                for(int j=-1; j<=1; j+=2) {
                    int xi = x+i, yj = y+j;
                    if(xi >= 0 && xi < m && yj >= 0 && yj < n)
                        if(board[xi][yj] == word[position+1]) {
                            x = xi, y = yj;
                            found = true;
                            visited[xi][yj] = true;
                            break;
                        }
                }
            }
            if(!found) return false;
            ++position;
        }
        return true;
    }
    bool hashMapSolution(vector<vector<char>> &board, string &word) {
        if(board.empty()) return false;
        m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));

        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(!visited[i][j] && board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if(dfs(board, word, i, j, 0, visited))
                        return true;
                    visited[i][j] = false;
                }

            }
        }
        return false;
    }

    bool optimizeSolution(vector<vector<char>> &board, string &word) {
        if(board.empty()) return false;
        m = board.size(), n = board[0].size();

        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(board[i][j] == word[0]) {
                    board[i][j] = '#';
                    if(optimizeDFS(board, word, i, j, 0))
                        return true;
                    board[i][j] = word[0];
                }

            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        return optimizeSolution(board, word);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    solution.exist(board, "SEE");
    return 0;
}