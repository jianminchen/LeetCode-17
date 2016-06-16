/*
  211_v1.cpp
  Add and Search Word - Data structure design

  My first submission got WA because I forgot to add "return false;" after the
  for loop in the case when (word[i] == '.'). My second submission got WA
  because I didn't check whether curr -> isWord == true when word.size() == 0.
*/

class TrieNode {
 public:
  bool isWord;
  TrieNode* child[26];
  TrieNode() {
    isWord = false;
    memset(child, 0, sizeof(child));
  }
};

class WordDictionary {
 private:
  TrieNode* root;

  bool search(TrieNode* curr, string word) {
    if (curr->isWord && word.size() == 0) return true;

    for (int i = 0; i < word.size(); i++) {
      if (word[i] != '.') {
        int idx = word[i] - 'a';
        if (curr->child[idx] == NULL) return false;
        curr = curr->child[idx];
      } else {
        for (int j = 0; j < 26; j++) {
          TrieNode* next = curr->child[j];
          if (next == NULL) continue;
          if (search(next, word.substr(i + 1))) return true;
        }
        return false;
      }
    }
    return curr->isWord;
  }

 public:
  WordDictionary() { root = new TrieNode(); }

  // Adds a word into the data structure.
  void addWord(string word) {
    TrieNode* curr = root;
    for (int i = 0; i < word.size(); i++) {
      int idx = word[i] - 'a';
      if (curr->child[idx] == NULL) {
        TrieNode* newNode = new TrieNode();
        curr->child[idx] = newNode;
      }
      curr = curr->child[idx];
    }
    curr->isWord = true;
  }

  // Returns if the word is in the data structure. A word could
  // contain the dot character '.' to represent any one letter.
  bool search(string word) { return search(root, word); }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");