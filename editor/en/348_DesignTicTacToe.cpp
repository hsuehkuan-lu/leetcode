//Assume the following rules are for the tic-tac-toe game on an n x n board betw
//een two players: 
//
// 
// A move is guaranteed to be valid and is placed on an empty block. 
// Once a winning condition is reached, no more moves are allowed. 
// A player who succeeds in placing n of their marks in a horizontal, vertical, 
//or diagonal row wins the game. 
// 
//
// Implement the TicTacToe class: 
//
// 
// TicTacToe(int n) Initializes the object the size of the board n. 
// int move(int row, int col, int player) Indicates that player with id player p
//lays at the cell (row, col) of the board. The move is guaranteed to be a valid m
//ove. 
// 
//
// Follow up: 
//Could you do better than O(n2) per move() operation? 
//
// 
// Example 1: 
//
// 
//Input
//["TicTacToe", "move", "move", "move", "move", "move", "move", "move"]
//[[3], [0, 0, 1], [0, 2, 2], [2, 2, 1], [1, 1, 2], [2, 0, 1], [1, 0, 2], [2, 1,
// 1]]
//Output
//[null, 0, 0, 0, 0, 0, 0, 1]
//
//Explanation
//TicTacToe ticTacToe = new TicTacToe(3);
//Assume that player 1 is "X" and player 2 is "O" in the board.
//ticTacToe.move(0, 0, 1); // return 0 (no one wins)
//|X| | |
//| | | |    // Player 1 makes a move at (0, 0).
//| | | |
//
//ticTacToe.move(0, 2, 2); // return 0 (no one wins)
//|X| |O|
//| | | |    // Player 2 makes a move at (0, 2).
//| | | |
//
//ticTacToe.move(2, 2, 1); // return 0 (no one wins)
//|X| |O|
//| | | |    // Player 1 makes a move at (2, 2).
//| | |X|
//
//ticTacToe.move(1, 1, 2); // return 0 (no one wins)
//|X| |O|
//| |O| |    // Player 2 makes a move at (1, 1).
//| | |X|
//
//ticTacToe.move(2, 0, 1); // return 0 (no one wins)
//|X| |O|
//| |O| |    // Player 1 makes a move at (2, 0).
//|X| |X|
//
//ticTacToe.move(1, 0, 2); // return 0 (no one wins)
//|X| |O|
//|O|O| |    // Player 2 makes a move at (1, 0).
//|X| |X|
//
//ticTacToe.move(2, 1, 1); // return 1 (player 1 wins)
//|X| |O|
//|O|O| |    // Player 1 makes a move at (2, 1).
//|X|X|X|
// 
//
// 
// Constraints: 
//
// 
// 2 <= n <= 100 
// player is 1 or 2. 
// 1 <= row, col <= n 
// (row, col) are unique for each different call to move. 
// At most n2 calls will be made to move. 
// 
// Related Topics Design 
// 👍 1041 👎 72


#include <iostream>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class TicTacToe {
private:
    int state, n;
    vector<vector<int>> board;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        this->n = n;
        state = 0;
        vector<vector<int>> b(n, vector<int>(n, 0));
        board = b;
    }
    bool checkWin(const int &row, const int &col, const int &player) {
        // check column & row
        bool row_win, col_win, diag_win;
        row_win = col_win = true;
        diag_win = false;
        for(int i=0; i<n; ++i) {
            if(board[row][i] != player) row_win = false;
            if(board[i][col] != player) col_win = false;
            if(!row_win && !col_win) break;
        }

        if(row == col) {
            bool left_diag = true;
            for(int i=0; i<n; ++i) {
                if(board[i][i] != player) left_diag = false;
                if(!left_diag) break;
            }
            diag_win |= left_diag;
        }
        if(row == n - 1 - col) {
            bool right_diag = true;
            for(int i=0; i<n; ++i) {
                if(board[i][n-1-i] != player) right_diag = false;
                if(!right_diag) break;
            }
            diag_win |= right_diag;
        }
        return row_win || col_win || diag_win;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if(board[row][col] == 0) {
            board[row][col] = player;
            if(checkWin(row, col, player))
                state = player;
        }
        return state;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    TicTacToe *obj = new TicTacToe(2);
    obj->move(0,1,1);
    obj->move(1,1,2);
    obj->move(1,0,1);
    return 0;
}