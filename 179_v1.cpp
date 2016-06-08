/*
  179_v1.cpp
  Largest Number

  My first submission failed on the case of {0, 0} and the expected output is 0
  instead of 00.
*/

bool cmp(string a, string b) { return a + b > b + a; }

class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    vector<string> vs;
    for (int i = 0; i < nums.size(); i++) vs.push_back(to_string(nums[i]));
    sort(vs.begin(), vs.end(), cmp);
    string ret = "";
    for (int i = 0; i < vs.size(); i++) ret += vs[i];
    int idx = -1;
    for (int i = 0; i < ret.size(); i++) {
      if (ret[i] != '0') {
        idx = i;
        break;
      }
    }
    if (idx == -1)
      return "0";
    else
      return ret.substr(idx);
  }
};