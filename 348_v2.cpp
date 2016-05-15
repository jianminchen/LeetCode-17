/*
  348_v2.cpp
  Design Tic-Tac-Toe

  I forgot to add abs in my first submission and got a WA.
*/

class TicTacToe {
  vector<int> rows, cols;
  int diagonal, anti_diagonal;

 public:
  /** Initialize your data structure here. */
  TicTacToe(int n) {
    rows.resize(n);
    cols.resize(n);
    fill(rows.begin(), rows.end(), 0);
    fill(cols.begin(), cols.end(), 0);
    diagonal = 0;
    anti_diagonal = 0;
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
    int n = rows.size();
    int add = (player == 1 ? 1 : -1);
    rows[row] += add;
    cols[col] += add;
    if (row == col) diagonal += add;
    if (row + col == n - 1) anti_diagonal += add;

    if (abs(rows[row]) == n || abs(cols[col]) == n || abs(diagonal) == n ||
        abs(anti_diagonal) == n)
      return player;

    return 0;
  }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */