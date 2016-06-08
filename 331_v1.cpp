/*
  331_v1.cpp
  Verify Preorder Serialization of a Binary Tree
*/

class Solution {
 private:
  vector<string> nodes;
  int idx;
  bool valid;
  void preorderTraversal() {
    if (idx >= nodes.size()) {
      valid = false;
      return;
    }
    if (nodes[idx++] != "#") {
      preorderTraversal();
      preorderTraversal();
    }
  }

 public:
  bool isValidSerialization(string preorder) {
    nodes.clear();
    string tmp = "";
    for (int i = 0; i < preorder.size(); i++) {
      if (preorder[i] == ',') {
        nodes.push_back(tmp);
        tmp = "";
      } else {
        tmp += preorder[i];
      }
    }
    nodes.push_back(tmp);
    idx = 0;
    valid = true;
    preorderTraversal();
    return valid && idx == nodes.size();
  }
};