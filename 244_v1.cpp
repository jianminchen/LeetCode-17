/*
  244_v1.cpp
  Shortest Word Distance II

  I was quite retarded in my first submission in that I'm trying to directly
  compare p1 and p2 instead of v1[p1] and v2[p2].
*/

class WordDistance {
 public:
  unordered_map<string, vector<int>> m;
  WordDistance(vector<string>& words) {
    for (int i = 0; i < words.size(); i++) m[words[i]].push_back(i);
  }

  int shortest(string word1, string word2) {
    auto v1 = m[word1], v2 = m[word2];
    int p1 = 0, p2 = 0, ans = INT_MAX;
    while (p1 < v1.size() && p2 < v2.size()) {
      ans = min(ans, abs(v1[p1] - v2[p2]));
      if (v1[p1] < v2[p2])
        p1++;
      else
        p2++;
    }
    return ans;
  }
};

// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");