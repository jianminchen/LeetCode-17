/*
  336_v1.cpp
  Palindrome Pairs

  My submission got MLE.
*/

class TrieNode {
 public:
  int idx;
  TrieNode* child[26];
  TrieNode() {
    idx = -1;
    for (int i = 0; i < 26; i++) child[i] = NULL;
  }
};

TrieNode* root;

void insert(string str, int idx) {
  TrieNode* curr = root;
  for (int i = 0; i < str.size(); i++) {
    int offset = str[i] - 'a';
    if (curr->child[offset])
      curr = curr->child[offset];
    else {
      TrieNode* tmp = new TrieNode();
      curr->child[offset] = tmp;
      curr = tmp;
    }
  }
  curr->idx = (short)idx;
}

TrieNode* search(string prefix) {
  TrieNode* curr = root;
  for (int i = 0; i < prefix.size(); i++) {
    int offset = prefix[i] - 'a';
    if (curr->child[offset])
      curr = curr->child[offset];
    else
      return NULL;
  }
  return curr;
}

bool isPalindrome(string str) {
  int l = 0, r = str.size() - 1;
  while (l < r) {
    if (str[l] == str[r])
      l++, r--;
    else
      return false;
  }
  return true;
}

vector<int> ans;

void dfs(TrieNode* curr, string str) {
  if (curr->idx != -1) {
    if (isPalindrome(str)) ans.push_back(curr->idx);
  }
  for (int i = 0; i < 26; i++) {
    if (curr->child[i]) {
      str += (char)(i + 'a');
      dfs(curr->child[i], str);
    }
  }
}

class Solution {
 public:
  vector<vector<int>> palindromePairs(vector<string>& words) {
    root = new TrieNode();
    vector<string> v = words;
    for (int i = 0; i < v.size(); i++) {
      reverse(v[i].begin(), v[i].end());
      insert(v[i], i);
    }
    vector<vector<int>> ret;
    for (int i = 0; i < words.size(); i++) {
      ans.clear();
      TrieNode* tmp = search(words[i]);
      if (tmp) dfs(tmp, "");
      for (int j = 0; j < ans.size(); j++)
        if (i != ans[j]) ret.push_back(vector<int>{i, ans[j]});
    }
    return ret;
  }
};