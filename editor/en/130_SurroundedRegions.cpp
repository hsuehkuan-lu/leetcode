//Given an m x n matrix board containing 'X' and 'O', capture all regions surrou
//nded by 'X'. 
//
// A region is captured by flipping all 'O's into 'X's in that surrounded region
//. 
//
// 
// Example 1: 
//
// 
//Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O"
//,"X","X"]]
//Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X
//"]]
//Explanation: Surrounded regions should not be on the border, which means that 
//any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not o
//n the border and it is not connected to an 'O' on the border will be flipped to 
//'X'. Two cells are connected if they are adjacent cells connected horizontally o
//r vertically.
// 
//
// Example 2: 
//
// 
//Input: board = [["X"]]
//Output: [["X"]]
// 
//
// 
// Constraints: 
//
// 
// m == board.length 
// n == board[i].length 
// 1 <= m, n <= 200 
// board[i][j] is 'X' or 'O'. 
// 
// Related Topics Depth-first Search Breadth-first Search Union Find 
// 👍 2598 👎 760


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int m, n;
    void borderFlip(vector<vector<char>> &board, int x, int y) {
        int dir_x[] = {-1, 0, 1, 0}, dir_y[] = {0, 1, 0, -1};
        board[x][y] = '#';
        for(int i=0; i<4; ++i) {
            int xi = x + dir_x[i], yj = y + dir_y[i];
            if(xi >= 0 && xi < m && yj >= 0 && yj < n) {
                if(board[xi][yj] == 'O') borderFlip(board, xi, yj);
            }
        }
    }
    void borderSolution(vector<vector<char>> &board) {
        for(int i=0; i<m; ++i) {
            if(board[i][0] == 'O') borderFlip(board, i, 0);
            if(board[i][n-1] == 'O') borderFlip(board, i, n-1);
        }
        for(int i=0; i<n; ++i) {
            if(board[0][i] == 'O') borderFlip(board, 0, i);
            if(board[m-1][i] == 'O') borderFlip(board, m-1, i);
        }
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(board[i][j] == '#')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
    bool canFlip(vector<vector<char>> &board, int x, int y, vector<vector<bool>> &visited) {
        if(visited[x][y]) return false;
        int dir_x[] = {-1, 0, 1, 0}, dir_y[] = {0, 1, 0, -1};
        visited[x][y] = true;
        if(x == 0 || x == m-1 || y == 0 || y == n-1) return false;
        bool can_flip = true;
        for(int i=0; i<4; ++i) {
            int xi = x + dir_x[i], yj = y + dir_y[i];
            if(xi >= 0 && xi < m && yj >= 0 && yj < n) {
                if(!visited[xi][yj] && board[xi][yj] == 'O') {
                    if(!canFlip(board, xi, yj, visited))
                        can_flip = false;
                }
            }
        }
        return can_flip;
    }
    void flip(vector<vector<char>> &board, int x, int y) {
        int dir_x[] = {-1, 0, 1, 0}, dir_y[] = {0, 1, 0, -1};
        board[x][y] = 'X';
        for(int i=0; i<4; ++i) {
            int xi = x + dir_x[i], yj = y + dir_y[i];
            if(xi > 0 && xi < m-1 && yj > 0 && yj < n-1) {
                if(board[xi][yj] == 'O') flip(board, xi, yj);
            }
        }
    }
    void dfsSolution(vector<vector<char>> &board) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=1; i<m-1; ++i) {
            for(int j=1; j<n-1; ++j) {
                if(board[i][j] == 'O' && canFlip(board, i, j, visited))
                    flip(board, i, j);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        m = board.size(), n = board[0].size();
//        dfsSolution(board);
        borderSolution(board);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<vector<char>> board = {{'O', 'O','O'},{'O', 'O','O'},{'O', 'O','O'}};
    solution.solve(board);
    return 0;
}