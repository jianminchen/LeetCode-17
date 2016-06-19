/*
  84_v1.cpp
  Largest Rectangle in Histogram
*/

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    if (n == 0) return 0;
    stack<pair<int, int>> st;
    st.emplace(INT_MIN, 0);
    int l[n + 1], r[n + 1];
    for (int i = 1; i <= n; i++) {
      while (heights[i - 1] <= st.top().first) st.pop();
      l[i] = st.top().second + 1;
      st.push(make_pair(heights[i - 1], i));
    }
    while (!st.empty()) st.pop();
    st.emplace(INT_MIN, n + 1);
    for (int i = n; i >= 1; i--) {
      while (heights[i - 1] <= st.top().first) st.pop();
      r[i] = st.top().second - 1;
      st.push(make_pair(heights[i - 1], i));
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
      ans = max(ans, heights[i - 1] * (r[i] - l[i] + 1));
    return ans;
  }
};