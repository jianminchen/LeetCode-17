/*
  291_v1.cpp
  Word Pattern II

  My first submission got WA because I didn't notice the part of "bijection" in
  the problem statement. Basically if the pattern is "ab" and the str is "aa",
  then we should return false since 'a' and 'b' cannot both map to "a".
*/

class Solution {
 private:
  bool search(int patternIdx, int strIdx, string pattern, string str,
              unordered_map<char, string>& m1,
              unordered_map<string, char>& m2) {
    if (patternIdx == pattern.size()) {
      if (strIdx == str.size()) {
        /*
        for (auto it : mapping)
            cout << it.first << " " << it.second << endl;
        */
        return true;
      }
      return false;
    }

    char ch = pattern[patternIdx];
    if (m1.count(ch)) {
      string mappedCh = m1[ch];
      if (strIdx + mappedCh.size() > str.size()) return false;
      string partialStr = str.substr(strIdx, mappedCh.size());
      if (mappedCh != partialStr) return false;
      return search(patternIdx + 1, strIdx + mappedCh.size(), pattern, str, m1,
                    m2);
    } else {
      string mappedCh = "";
      for (int i = strIdx; i < str.size(); i++) {
        mappedCh += str[i];
        if (!m2.count(mappedCh)) {
          m1[ch] = mappedCh;
          m2[mappedCh] = ch;
          if (search(patternIdx + 1, i + 1, pattern, str, m1, m2)) return true;
          m2.erase(mappedCh);
        }
      }
      m1.erase(ch);
      return false;
    }
  }

 public:
  bool wordPatternMatch(string pattern, string str) {
    unordered_map<char, string> m1;
    unordered_map<string, char> m2;
    return search(0, 0, pattern, str, m1, m2);
  }
};