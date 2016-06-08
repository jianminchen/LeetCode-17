/*
  267_v1.cpp
  Palindrome Permutation II

  My first two submissions both failed on a simple case: handling characters
  that appeared an odd number of times. For instance, for the string "aabbccc",
  we should save "aabbcc" in string tmp. My first two submissions made a mistake
  and just saved "aabb".
*/

class Solution {
 public:
  vector<string> generatePalindromes(string s) {
    int cnt[256];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < s.size(); i++) cnt[s[i]]++;
    string tmp = "";
    int numOdd = 0;
    char oddCh;
    for (int i = 0; i < 256; i++) {
      if (cnt[i] == 0) continue;
      if (cnt[i] % 2 == 0) {
        for (int j = 0; j < cnt[i] / 2; j++) tmp += (char)i;
      } else {
        for (int j = 0; j < cnt[i] / 2; j++) tmp += (char)i;
        numOdd++;
        oddCh = (char)i;
      }
    }
    vector<string> ret;
    if (numOdd > 1) return ret;
    sort(tmp.begin(), tmp.end());
    do {
      string t = tmp;
      reverse(t.begin(), t.end());
      if (numOdd == 0)
        ret.push_back(tmp + t);
      else
        ret.push_back(tmp + oddCh + t);
    } while (next_permutation(tmp.begin(), tmp.end()));
    return ret;
  }
};