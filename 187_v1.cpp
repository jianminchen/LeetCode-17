/*
  187_v1.cpp
  Repeated DNA Sequences
*/

class Solution {
 private:
  unordered_map<char, int> c2i = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
  unordered_map<int, char> i2c = {{0, 'A'}, {1, 'C'}, {2, 'G'}, {3, 'T'}};

  string conv(int bitmask) {
    string str;
    while (bitmask) {
      int val = bitmask % 4;
      str += i2c[val];
      bitmask /= 4;
    }
    while (str.size() < 10) str += 'A';
    reverse(str.begin(), str.end());
    return str;
  }

 public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> ret;
    unordered_set<int> appearedMultipleTimes;
    if (s.size() <= 10) return ret;
    unordered_set<int> bitSet;
    int bitmask = 0;
    for (int i = 0; i < 10; i++) bitmask = bitmask * 4 + c2i[s[i]];
    bitSet.insert(bitmask);
    for (int i = 1; i + 9 < s.size(); i++) {
      bitmask -= c2i[s[i - 1]] * (1 << 18);
      bitmask *= 4;
      bitmask += c2i[s[i + 9]];
      if (bitSet.find(bitmask) != bitSet.end())
        appearedMultipleTimes.insert(bitmask);
      bitSet.insert(bitmask);
    }
    for (int bitmask : appearedMultipleTimes) ret.push_back(conv(bitmask));
    return ret;
  }
};