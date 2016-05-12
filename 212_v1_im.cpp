/*
  212_v1_im.cpp
  Word Search II

  I've basically added some optimization in this version to reduce the running
  time. Some key tricks: 1) visited is not needed as we can use board array to
  directly track this information; 2) no need to use an unordered_set<string>
  ret as we can "remove" the word from Trie after added it once; 3) no need to
  write a search function for Trie as we can add TrieNode* in the DFS parameter
  list.
*/

class TrieNode {
 public:
  string word;
  TrieNode* child[26];
  TrieNode() {
    word = "";
    for (int i = 0; i < 26; i++) child[i] = NULL;
  };
};

TrieNode* root;

void insert(string str) {
  TrieNode* curr = root;
  for (int i = 0; i < str.size(); i++) {
    int idx = str[i] - 'a';
    if (curr->child[idx])
      curr = curr->child[idx];
    else {
      TrieNode* node = new TrieNode();
      curr->child[idx] = node;
      curr = node;
    }
  }
  curr->word = str;
}

class Solution {
  int R, C;
  vector<string> ret;
  void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node) {
    char ch = board[r][c];
    node = node->child[ch - 'a'];
    if (node == NULL) return;
    board[r][c] = '#';
    if (node->word != "") {
      ret.push_back(node->word);
      node->word = "";
    }
    if (r - 1 >= 0 && board[r - 1][c] != '#') dfs(board, r - 1, c, node);
    if (r + 1 < R && board[r + 1][c] != '#') dfs(board, r + 1, c, node);
    if (c - 1 >= 0 && board[r][c - 1] != '#') dfs(board, r, c - 1, node);
    if (c + 1 < C && board[r][c + 1] != '#') dfs(board, r, c + 1, node);
    board[r][c] = ch;
  }

 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    root = new TrieNode();
    for (int i = 0; i < words.size(); i++) insert(words[i]);
    ret.clear();
    R = board.size();
    if (R == 0) return vector<string>();
    C = board[0].size();
    for (int i = 0; i < R; i++)
      for (int j = 0; j < C; j++) dfs(board, i, j, root);
    return ret;
  }
};