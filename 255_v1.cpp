/*
  255_v1.cpp
  Verify Preorder Sequence in Binary Search Tree
*/

class Solution {
 public:
  bool verifyPreorder(vector<int>& preorder) {
    stack<int> st;
    int low = INT_MIN;
    for (int val : preorder) {
      if (val < low) return false;
      while (!st.empty() && val > st.top()) {
        low = st.top();
        st.pop();
      }
      st.push(val);
    }
    return true;
  }
};