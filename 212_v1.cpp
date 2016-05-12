/*
  212_v1.cpp
  Word Search II

  My first submission got TLE since I've basically enumerated all words and then
  for I've performed DFS individually for each word. So I've changed the
  solution to Trie. My second submission got WA because I've implemented
  something like this: if (search(curr, isPrefix: false)) {ret.insert(curr);
  return;}. Apparently I should not add a "return" here since we can possibly
  still create longer strings that still is part of the word list.
*/

class TrieNode {
 public:
  char val;
  bool isEnd;
  TrieNode* child[26];
  TrieNode(){};
  TrieNode(char ch) {
    val = ch;
    isEnd = false;
    for (int i = 0; i < 26; i++) child[i] = NULL;
  }
};

TrieNode* root;

bool search(string str, bool isPrefix) {
  TrieNode* curr = root;
  for (int i = 0; i < str.size(); i++) {
    if (curr->child[str[i] - 'a'])
      curr = curr->child[str[i] - 'a'];
    else
      return false;
  }
  return isPrefix || curr->isEnd;
}

void insert(string str) {
  TrieNode* curr = root;
  for (int i = 0; i < str.size(); i++) {
    if (curr->child[str[i] - 'a'])
      curr = curr->child[str[i] - 'a'];
    else {
      TrieNode* node = new TrieNode(str[i]);
      curr->child[str[i] - 'a'] = node;
      curr = node;
    }
  }
  curr->isEnd = true;
}

class Solution {
  int R, C;
  bool valid(int r, int c) { return 0 <= r && r < R && 0 <= c && c < C; }
  const int dx[4] = {-1, 1, 0, 0};
  const int dy[4] = {0, 0, -1, 1};
  set<string> ret;
  void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int r,
           int c, string curr) {
    curr += board[r][c];
    if (!search(curr, true)) return;
    if (search(curr, false)) ret.insert(curr);
    for (int i = 0; i < 4; i++) {
      int nr = r + dx[i], nc = c + dy[i];
      if (valid(nr, nc) && !visited[nr][nc]) {
        visited[nr][nc] = true;
        dfs(board, visited, nr, nc, curr);
        visited[nr][nc] = false;
      }
    }
  }

 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    root = new TrieNode(' ');
    for (int i = 0; i < words.size(); i++) insert(words[i]);
    ret.clear();
    R = board.size();
    if (R == 0) return vector<string>();
    C = board[0].size();
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        visited[i][j] = true;
        dfs(board, visited, i, j, "");
        visited[i][j] = false;
      }
    }
    vector<string> vs(ret.begin(), ret.end());
    return vs;
  }
};