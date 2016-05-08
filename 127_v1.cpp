/*
  127_v1.cpp
  Word Ladder

  My first two submissions got CE because I used add() for unordered_set instead
  of insert() and top() for queue instead of front(). My third submission
  received TLE because I forgot to check visited.find(word) == visited.end() in
  BFS. My fourth submission got WA because of an off-by-one mistake.
*/

class Solution {
 public:
  int ladderLength(string beginWord, string endWord,
                   unordered_set<string>& wordList) {
    queue<pair<string, int>> q;
    q.push(make_pair(beginWord, 0));
    unordered_set<string> visited;
    visited.insert(beginWord);
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      string word = p.first;
      int len = p.second;
      if (word == endWord) return len + 1;
      for (int i = 0; i < word.size(); i++) {
        char tmp = word[i];
        for (char ch = 'a'; ch <= 'z'; ch++) {
          if (ch == tmp) continue;
          word[i] = ch;
          if (wordList.find(word) != wordList.end() &&
              visited.find(word) == visited.end()) {
            q.push(make_pair(word, len + 1));
            visited.insert(word);
          }
        }
        word[i] = tmp;
      }
    }
    return 0;
  }
};