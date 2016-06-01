/*
  271_v1.cpp
  Encode and Decode Strings

  This problem does not have a "Run Code" functionality so my first four
  submissions got WA. Actually they are stupid mistakes related to the usage of
  substr() and not setting back len to 0.
*/

class Codec {
 public:
  // Encodes a list of strings to a single string.
  string encode(vector<string>& strs) {
    string ret = "";
    for (int i = 0; i < strs.size(); i++)
      ret += to_string(strs[i].size()) + "|" + strs[i];
    return ret;
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s) {
    vector<string> ret;
    int len = 0;
    for (int i = 0; i < s.size(); i++) {
      if (isdigit(s[i]))
        len = len * 10 + s[i] - '0';
      else if (s[i] == '|') {
        ret.push_back(s.substr(i + 1, len));
        i += len;
        len = 0;
      }
    }
    return ret;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));