/*
  71_v1.cpp
  Simplify Path

  My first submission got RTE because I didn't handle test cases like this
  "/..": in fact I don't understand why this is a valid input. My second case
  got WA because I directly used "continue;" after "if (directoryName == "" ||
  directoryName == ".")" which means I didn't clear the directoryName string for
  such cases.
*/

class Solution {
 public:
  string simplifyPath(string path) {
    vector<string> directories;
    string directoryName = "";
    path = "/" + path + "/";
    for (int i = 0; i < path.size(); i++) {
      if (path[i] != '/')
        directoryName += path[i];
      else {
        if (directoryName == "" || directoryName == ".")
          ;
        else if (directoryName == "..") {
          if (directories.size() > 0) directories.pop_back();
        } else
          directories.push_back(directoryName);
        directoryName = "";
      }
    }
    if (directories.size() == 0) return "/";
    string ret = "";
    for (int i = 0; i < directories.size(); i++) ret += "/" + directories[i];
    return ret;
  }
};