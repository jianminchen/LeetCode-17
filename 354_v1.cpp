/*
  354_v1.cpp
  Russian Doll Envelopes

  My first submission got WA since I didn't init each f[i] to be 1 and I
  returned f[n - 1] directly.
*/

class Solution {
 public:
  int maxEnvelopes(vector<pair<int, int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end());
    int n = envelopes.size();
    if (n == 0) return 0;
    int f[n];
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (int i = 1; i < n; i++) {
      f[i] = 1;
      int width_i = envelopes[i].first;
      int height_i = envelopes[i].second;
      for (int j = 0; j < i; j++) {
        int width_j = envelopes[j].first;
        int height_j = envelopes[j].second;
        if (width_j < width_i && height_j < height_i && f[j] + 1 > f[i])
          f[i] = f[j] + 1;
      }
    }
    int ans = 1;
    for (int i = 0; i < n; i++) ans = max(ans, f[i]);
    return ans;
  }
};