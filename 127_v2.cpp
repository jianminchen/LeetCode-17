/*
  127_v2.cpp
  Word Ladder

  One minor issue is I've forgot to add a trailing "- 1" in the return statement
  thus I've got my second WA. I didn't add "word[i] = tmp" and got my 3rd and
  4th WA.
*/

class Solution {
 public:
  int ladderLength(string beginWord, string endWord,
                   unordered_set<string>& wordList) {
    queue<pair<string, int>> q[2];
    unordered_map<string, int> visited[2];
    q[0].push(make_pair(beginWord, 1));
    visited[0][beginWord] = 1;
    q[1].push(make_pair(endWord, 1));
    visited[1][endWord] = 1;
    int flag = 0;
    while (!q[flag].empty()) {
      auto p = q[flag].front();
      q[flag].pop();
      string word = p.first;
      int len = p.second;
      if (visited[1 - flag].find(word) != visited[1 - flag].end()) {
        cout << word << " " << visited[flag][word] << " "
             << visited[1 - flag][word] << endl;
        return visited[flag][word] + visited[1 - flag][word] - 1;
      }
      for (int i = 0; i < word.size(); i++) {
        char tmp = word[i];
        for (char ch = 'a'; ch <= 'z'; ch++) {
          if (ch == tmp) continue;
          word[i] = ch;
          if (wordList.find(word) != wordList.end() &&
              visited[flag].find(word) == visited[flag].end()) {
            visited[flag].insert(make_pair(word, len + 1));
            q[flag].push(make_pair(word, len + 1));
          }
        }
        word[i] = tmp;
      }
      flag = 1 - flag;
    }
    return 0;
  }
};