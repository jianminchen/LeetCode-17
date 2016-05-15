/*
  299_v2.cpp
  Bulls and Cows
*/

class Solution {
 public:
  string getHint(string secret, string guess) {
    int num[10] = {0}, bull = 0, cow = 0;
    for (int i = 0; i < guess.size(); i++) {
      int s = secret[i] - '0', g = guess[i] - '0';
      if (s == g)
        bull++;
      else {
        if (num[g] > 0) cow++;
        if (num[s] < 0) cow++;
        num[s]++;
        num[g]--;
      }
    }
    return to_string(bull) + "A" + to_string(cow) + "B";
  }
};