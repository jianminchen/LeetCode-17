/*
  165_v1.cpp
  Compare Version Numbers

  I did not read the problem carefully. It was specified very clearly that "The
  . character does not represent a decimal point and is used to separate number
  sequences.". I thought 1.2 should be larger than 1.10 but based on this
  description 1.10 should be larger. Thus, solving the problem is easier and we
  only need to convert each number sequence to integer. One special tricky case
  is "1" == "1.0".

  My two submissions got WA because I thought 1.2 > 1.10. Then I got another WA
  and RTE because I didn't know 1.0 == 1.
*/

class Solution {
  vector<string> convertVersionStringToVector(string version) {
    vector<string> ret;
    string versionStr = "";
    for (int i = 0; i < version.size(); i++) {
      if (version[i] != '.')
        versionStr += version[i];
      else {
        ret.push_back(versionStr);
        versionStr = "";
      }
    }
    if (versionStr != "") ret.push_back(versionStr);
    return ret;
  }
  int compare(vector<string>& a, vector<string>& b) {
    int i;
    for (i = 0; i < max(a.size(), b.size()); i++) {
      int va = i >= a.size() ? 0 : stoi(a[i]);
      int vb = i >= b.size() ? 0 : stoi(b[i]);
      if (va < vb) return -1;
      if (va > vb) return 1;
    }
    return 0;
  }

 public:
  int compareVersion(string version1, string version2) {
    vector<string> vs1 = convertVersionStringToVector(version1);
    vector<string> vs2 = convertVersionStringToVector(version2);
    return compare(vs1, vs2);
  }
};