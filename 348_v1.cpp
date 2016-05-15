/*
  348_v1.cpp
  Design Tic-Tac-Toe

  In my first submission I've made a mistake and written something like this:
  "if (val1 == 0 && val2 == 0) horizontal[player][row][col] = val;". Ideally it
  should be "if (val1 == 0 || val2 == 0) horizontal[player][row][col] = val;".
  In fact, for simplicity we don't even need to check "if (val1)" and "if
  (val2)" in the following statements as well.

  Then later after checking the discussion I've found my solution is really
  stupid...though it is O(1).
*/

class TicTacToe {
  vector<vector<int>> board, horizontal[2], vertical[2], mainDiag[2],
      antiDiag[2];

 public:
  /** Initialize your data structure here. */
  TicTacToe(int n) {
    board.resize(n);
    for (int i = 0; i < n; i++) {
      board[i].resize(n);
      fill(board[i].begin(), board[i].end(), 0);
    }
    for (int i = 0; i < 2; i++) {
      horizontal[i].resize(n);
      vertical[i].resize(n);
      mainDiag[i].resize(n);
      antiDiag[i].resize(n);
      for (int j = 0; j < n; j++) {
        horizontal[i][j].resize(n);
        vertical[i][j].resize(n);
        mainDiag[i][j].resize(n);
        antiDiag[i][j].resize(n);
        fill(horizontal[i][j].begin(), horizontal[i][j].end(), 0);
        fill(vertical[i][j].begin(), vertical[i][j].end(), 0);
        fill(mainDiag[i][j].begin(), mainDiag[i][j].end(), 0);
        fill(antiDiag[i][j].begin(), antiDiag[i][j].end(), 0);
      }
    }
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
    int n = board.size();
    board[row][col] = player;
    player--;

    int val1, val2, val;
    val1 = col >= 1 ? horizontal[player][row][col - 1] : 0;
    val2 = col < n - 1 ? horizontal[player][row][col + 1] : 0;
    val = val1 + val2 + 1;
    horizontal[player][row][col] = val;
    if (val1) horizontal[player][row][col - val1] = val;
    if (val2) horizontal[player][row][col + val2] = val;
    if (val == n) return player + 1;

    val1 = row >= 1 ? vertical[player][row - 1][col] : 0;
    val2 = row < n - 1 ? vertical[player][row + 1][col] : 0;
    val = val1 + val2 + 1;
    vertical[player][row][col] = val;
    if (val1) vertical[player][row - val1][col] = val;
    if (val2) vertical[player][row + val2][col] = val;
    if (val == n) return player + 1;

    if (row == col) {
      val1 = row >= 1 ? mainDiag[player][row - 1][col - 1] : 0;
      val2 = row < n - 1 ? mainDiag[player][row + 1][col + 1] : 0;
      val = val1 + val2 + 1;
      mainDiag[player][row][col] = val;
      if (val1) mainDiag[player][row - val1][col - val1] = val;
      if (val2) mainDiag[player][row + val2][col + val2] = val;
      if (val == n) return player + 1;
    }

    if (row + col == n - 1) {
      val1 = row >= 1 ? antiDiag[player][row - 1][col + 1] : 0;
      val2 = row < n - 1 ? antiDiag[player][row + 1][col - 1] : 0;
      val = val1 + val2 + 1;
      antiDiag[player][row][col] = val;
      if (val1) antiDiag[player][row - val1][col + val1] = val;
      if (val2) antiDiag[player][row + val2][col - val2] = val;
      if (val == n) return player + 1;
    }

    return 0;
  }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */