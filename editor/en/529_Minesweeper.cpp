//Let's play the minesweeper game (Wikipedia, online game)! 
//
// You are given an m x n char matrix board representing the game board where: 
//
// 
// 'M' represents an unrevealed mine, 
// 'E' represents an unrevealed empty square, 
// 'B' represents a revealed blank square that has no adjacent mines (i.e., abov
//e, below, left, right, and all 4 diagonals), 
// digit ('1' to '8') represents how many mines are adjacent to this revealed sq
//uare, and 
// 'X' represents a revealed mine. 
// 
//
// You are also given an integer array click where click = [clickr, clickc] repr
//esents the next click position among all the unrevealed squares ('M' or 'E'). 
//
// Return the board after revealing this position according to the following rul
//es: 
//
// 
// If a mine 'M' is revealed, then the game is over. You should change it to 'X'
//. 
// If an empty square 'E' with no adjacent mines is revealed, then change it to 
//a revealed blank 'B' and all of its adjacent unrevealed squares should be reveal
//ed recursively. 
// If an empty square 'E' with at least one adjacent mine is revealed, then chan
//ge it to a digit ('1' to '8') representing the number of adjacent mines. 
// Return the board when no more squares will be revealed. 
// 
//
// 
// Example 1: 
//
// 
//Input: board = [["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","
//E"],["E","E","E","E","E"]], click = [3,0]
//Output: [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B
//","B","B","B","B"]]
// 
//
// Example 2: 
//
// 
//Input: board = [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","
//B"],["B","B","B","B","B"]], click = [1,2]
//Output: [["B","1","E","1","B"],["B","1","X","1","B"],["B","1","1","1","B"],["B
//","B","B","B","B"]]
// 
//
// 
// Constraints: 
//
// 
// m == board.length 
// n == board[i].length 
// 1 <= m, n <= 50 
// board[i][j] is either 'M', 'E', 'B', or a digit from '1' to '8'. 
// click.length == 2 
// 0 <= clickr < m 
// 0 <= clickc < n 
// board[clickr][clickc] is either 'M' or 'E'. 
//
// 👍 991 👎 703
	

#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int m, n;
public:
    char findMine(vector<vector<char>> &board, int x, int y) {
        int cnt = 0;
        for(int i=-1; i<=1; ++i) {
            for(int j=-1; j<=1; ++j) {
                if(i==0 && j==0) continue;
                int dx = x + i, dy = y + j;
                if(dx >= 0 && dx < m && dy >= 0 && dy < n) {
                    if(board[dx][dy] == 'M')
                        ++cnt;
                }
            }
        }
        return cnt == 0 ? 'B' : ('0' + cnt);
    }
    void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int x, int y) {
        if(visited[x][y]) return;
        char ch = findMine(board, x, y);
        visited[x][y] = true;
        board[x][y] = ch;
        if(ch != 'B') {
            return;
        } else {
            for(int i=-1; i<=1; ++i) {
                for(int j=-1; j<=1; ++j) {
                    if(i == 0 && j == 0) continue;
                    int dx = x + i, dy = y + j;
                    if(dx >= 0 && dx < m && dy >= 0 && dy < n && !visited[dx][dy]) {
                        dfs(board, visited, dx, dy);
                    }
                }
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click.front(), y = click.back();
        if(board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }
        m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        dfs(board, visited, x, y);
        return board;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    return 0;
}