/*
  288_v1.cpp
  Unique Word Abbreviation

  I received my first WA because I did not expect the dictionary vector would
  contain repetitive words. My second submission got a CE.
*/

class ValidWordAbbr {
  unordered_map<string, pair<int, string>> m;
  string abbreviate(string str) {
    if (str.size() <= 2) return str;
    return str[0] + to_string(str.size() - 2) + str[str.size() - 1];
  }

 public:
  ValidWordAbbr(vector<string> &dictionary) {
    set<string> s(dictionary.begin(), dictionary.end());
    for (auto it : s) {
      string abbreviatedStr = abbreviate(it);
      if (m.find(abbreviatedStr) == m.end())
        m[abbreviatedStr] = make_pair(1, it);
      else {
        int cnt = m[abbreviatedStr].first + 1;
        m[abbreviatedStr] = make_pair(cnt, it);
      }
    }
  }

  bool isUnique(string word) {
    string abbreviatedWord = abbreviate(word);
    if (m.find(abbreviatedWord) == m.end()) return true;
    int cnt = m[abbreviatedWord].first;
    if (cnt > 1) return false;
    if (cnt == 1 && m[abbreviatedWord].second != word) return false;
    return true;
  }
};

// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");