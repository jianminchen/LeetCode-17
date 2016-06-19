/*
  135_v2.cpp
  Candy
*/

class Solution {
 public:
  int candy(vector<int>& ratings) {
    if (ratings.size() == 0) return 0;
    int n = ratings.size();
    int assigned[n];
    fill(assigned, assigned + n, 1);
    for (int i = 1; i < n; i++) {
      if (ratings[i] > ratings[i - 1]) assigned[i] = assigned[i - 1] + 1;
    }
    for (int i = n - 2; i >= 0; i--) {
      if (ratings[i] > ratings[i + 1])
        assigned[i] = max(assigned[i], assigned[i + 1] + 1);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans += assigned[i];
    return ans;
  }
};