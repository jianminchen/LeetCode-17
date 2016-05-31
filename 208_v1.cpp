/*
  208_v1.cpp
  Implement Trie (Prefix Tree)

  My first two submissions got CE.
*/

class TrieNode {
 public:
  TrieNode* child[26];
  bool isWord;

  // Initialize your data structure here.
  TrieNode() {
    for (int i = 0; i < 26; i++) child[i] = NULL;
    isWord = false;
  }
};

class Trie {
 public:
  Trie() { root = new TrieNode(); }

  // Inserts a word into the trie.
  void insert(string word) {
    TrieNode* curr = root;
    for (int i = 0; i < word.size(); i++) {
      int idx = word[i] - 'a';
      if (curr->child[idx] == NULL) {
        TrieNode* node = new TrieNode();
        curr->child[idx] = node;
      }
      curr = curr->child[idx];
    }
    curr->isWord = true;
  }

  // Returns if the word is in the trie.
  bool search(string word) {
    TrieNode* curr = root;
    for (int i = 0; i < word.size(); i++) {
      int idx = word[i] - 'a';
      if (curr->child[idx] == NULL) return false;
      curr = curr->child[idx];
    }
    return curr->isWord;
  }

  // Returns if there is any word in the trie
  // that starts with the given prefix.
  bool startsWith(string prefix) {
    TrieNode* curr = root;
    for (int i = 0; i < prefix.size(); i++) {
      int idx = prefix[i] - 'a';
      if (curr->child[idx] == NULL) return false;
      curr = curr->child[idx];
    }
    return true;
  }

 private:
  TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");