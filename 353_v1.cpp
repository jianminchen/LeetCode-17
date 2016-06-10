/*
  353_v1.cpp
  Design Snake Game

  The problem itself is not difficult, just use a deque to simulate the
  positions of the snake. My first submission got MLE since there can be board
  of 10000 x 10000 and initially I've used a 2D array to keep track of the
  status of the board. My second and third submissions got WA because a snake
  can move its head to its tail and this won't be considered as "bites its
  body".
*/

class SnakeGame {
 private:
  unordered_map<string, pair<int, int>> directionMap;
  map<pair<int, int>, int>
      board;  //-2 indicates the cell has been occupied by the snake
  int boardRow, boardCol;
  vector<pair<int, int>> _foodList;
  int currFood;
  bool valid(pair<int, int> p) {
    int r = p.first, c = p.second;
    if (r < 0 || r >= boardRow || c < 0 || c >= boardCol) return false;
    return true;
  }
  deque<pair<int, int>> snake;
  int currentScore;

  void outputSnake() {
    for (auto p : snake) cout << p.first << " " << p.second << endl;
    cout << endl;
  }

 public:
  /** Initialize your data structure here.
      @param width - screen width
      @param height - screen height
      @param food - A list of food positions
      E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the
     second is at [1,0]. */
  SnakeGame(int width, int height, vector<pair<int, int>> food) {
    boardRow = height;
    boardCol = width;

    directionMap.clear();
    directionMap["U"] = make_pair(-1, 0);
    directionMap["L"] = make_pair(0, -1);
    directionMap["R"] = make_pair(0, 1);
    directionMap["D"] = make_pair(1, 0);

    _foodList = food;
    currFood = 0;
    if (currFood < _foodList.size()) {
      auto p = _foodList[currFood++];
      board[p] = currFood - 1;
    }

    board[make_pair(0, 0)] = -2;
    snake.emplace_back(0, 0);
    currentScore = 0;
  }

  /** Moves the snake.
      @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
      @return The game's score after the move. Return -1 if game over.
      Game over when snake crosses the screen boundary or bites its body. */
  int move(string direction) {
    // cout << direction << endl;
    auto d = directionMap[direction];
    auto snakeHead = snake.front();
    int snakeHeadRow = snakeHead.first;
    int snakeHeadCol = snakeHead.second;

    int snakeHeadNewRow = snakeHeadRow + d.first;
    int snakeHeadNewCol = snakeHeadCol + d.second;
    auto snakeNewHead = make_pair(snakeHeadNewRow, snakeHeadNewCol);

    if (!valid(snakeNewHead)) return -1;

    if (board.find(snakeNewHead) != board.end() &&
        board[snakeNewHead] == currFood - 1) {
      board[snakeNewHead] = -2;
      snake.push_front(snakeNewHead);
      if (currFood < _foodList.size()) {
        auto p = _foodList[currFood++];
        board[p] = currFood - 1;
      }
      currentScore++;
      // outputSnake();
      return currentScore;
    }

    auto snakeTail = snake.back();
    board.erase(snakeTail);  // clear tail as unoccupied
    snake.pop_back();

    if (board.find(snakeNewHead) != board.end() && board[snakeNewHead] == -2)
      return -1;

    snake.push_front(snakeNewHead);
    board[snakeNewHead] = -2;  // mark new head as occupied
    // outputSnake();
    return currentScore;
  }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */