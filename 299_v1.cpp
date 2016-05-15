/*
  299_v1.cpp
  Bulls and Cows

  My solution uses two pass and initially I got WA since in this solution I
  basically need to handle bull first and then handle cow. Previously I've tried
  to handle these two cases in one loop.
*/

class Solution {
 public:
  string getHint(string secret, string guess) {
    int bull = 0, cow = 0;
    vector<bool> used(secret.size(), false);
    for (int i = 0; i < guess.size(); i++) {
      if (guess[i] == secret[i]) {
        bull++;
        used[i] = true;
      }
    }
    for (int i = 0; i < guess.size(); i++) {
      if (guess[i] != secret[i]) {
        for (int j = 0; j < secret.size(); j++) {
          if (guess[i] == secret[j] && !used[j]) {
            used[j] = true;
            cow++;
            break;
          }
        }
      }
    }
    return to_string(bull) + "A" + to_string(cow) + "B";
  }
};