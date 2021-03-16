//According to Wikipedia's article: "The Game of Life, also known simply as Life
//, is a cellular automaton devised by the British mathematician John Horton Conwa
//y in 1970." 
//
// The board is made up of an m x n grid of cells, where each cell has an initia
//l state: live (represented by a 1) or dead (represented by a 0). Each cell inter
//acts with its eight neighbors (horizontal, vertical, diagonal) using the followi
//ng four rules (taken from the above Wikipedia article): 
//
// 
// Any live cell with fewer than two live neighbors dies as if caused by under-p
//opulation. 
// Any live cell with two or three live neighbors lives on to the next generatio
//n. 
// Any live cell with more than three live neighbors dies, as if by over-populat
//ion. 
// Any dead cell with exactly three live neighbors becomes a live cell, as if by
// reproduction. 
// 
//
// The next state is created by applying the above rules simultaneously to every
// cell in the current state, where births and deaths occur simultaneously. Given 
//the current state of the m x n grid board, return the next state. 
//
// 
// Example 1: 
//
// 
//Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
//Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
// 
//
// Example 2: 
//
// 
//Input: board = [[1,1],[1,0]]
//Output: [[1,1],[1,1]]
// 
//
// 
// Constraints: 
//
// 
// m == board.length 
// n == board[i].length 
// 1 <= m, n <= 25 
// board[i][j] is 0 or 1. 
// 
//
// 
// Follow up: 
//
// 
// Could you solve it in-place? Remember that the board needs to be updated simu
//ltaneously: You cannot update some cells first and then use their updated values
// to update other cells. 
// In this question, we represent the board using a 2D array. In principle, the 
//board is infinite, which would cause problems when the active area encroaches up
//on the border of the array (i.e., live cells reach the border). How would you ad
//dress these problems? 
// 
// Related Topics Array 
// 👍 2529 👎 326


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int m, n;
    int countNeighbor(vector<vector<int>> &board, int &x, int &y) {
        int cnt = 0;
        for(int i=-1; i<=1; ++i) {
            for(int j=-1; j<=1; ++j) {
                int xi = x + i, yi = y + j;
                if(i == 0 && j == 0 || !(xi >= 0 && xi < m) || !(yi >= 0 && yi < n)) continue;
                if(board[xi][yi]) ++cnt;
            }
        }
        return cnt;
    }
    bool checkAlive(vector<vector<int>> &board, int &x, int &y) {
        int cnt = countNeighbor(board, x, y);
        if(board[x][y]) {
            if(cnt >= 2 && cnt <= 3) return true;
        } else {
            if(cnt == 3) return true;
        }
        return false;
    }
    void duplicateSolution(vector<vector<int>> &board) {
        vector<vector<int>> next_board(board);
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                next_board[i][j] = checkAlive(board, i, j) ? 1 : 0;
        board.assign(next_board.begin(), next_board.end());
    }
    int countAliveNeighbor(vector<vector<int>> &board, int &x, int &y) {
        int cnt = 0;
        for(int i=-1; i<=1; ++i) {
            for(int j=-1; j<=1; ++j) {
                int xi = x + i, yi = y + j;
                if(i == 0 && j == 0 || !(xi >= 0 && xi < m) || !(yi >= 0 && yi < n)) continue;
                if(board[xi][yi] == 1 || board[xi][yi] == 2) ++cnt;
            }
        }
        return cnt;
    }
    int getState(vector<vector<int>> &board, int &x, int &y) {
        int cnt = countAliveNeighbor(board, x, y);
        if(board[x][y]) {
            if(cnt >= 2 && cnt <= 3) return 1;
            else return 2;
        } else {
            if(cnt == 3) return 3;
            else return 0;
        }
    }
    void constantSpaceSolution(vector<vector<int>> &board) {
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                board[i][j] = getState(board, i, j);
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                board[i][j] = (board[i][j] == 1 || board[i][j] == 3) ? 1 : 0;
    }
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size(), n = board[0].size();
        constantSpaceSolution(board);
   }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<vector<int>> board = {{0,1,0}, {0,0,1}, {1,1,1}, {0,0,0}};
    solution.gameOfLife(board);
    return 0;
}