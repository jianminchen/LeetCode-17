/*
  20_v1.cpp
  Valid Parentheses
*/

class Solution {
 public:
  bool isValid(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
        st.push(s[i]);
      } else {
        if (st.empty()) return false;
        char ch = st.top();
        if (s[i] == ')' && ch != '(') return false;
        if (s[i] == '}' && ch != '{') return false;
        if (s[i] == ']' && ch != '[') return false;
        st.pop();
      }
    }
    if (!st.empty()) return false;
    return true;
  }
};