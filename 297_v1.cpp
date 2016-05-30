/*
  297_v1.cpp
  Serialize and Deserialize Binary Tree

  Although I've solved this problem but the way I'm doing serialization is far
  more complicated than the "normal" approach - preorder traversal and store the
  value of null nodes.
*/

/**
*Definition for a binary tree node.
*struct TreeNode {
*    int val;
*    TreeNode *left;
*    TreeNode *right;
*    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
*};
*/
class Codec {
 private:
  TreeNode* stringToTreeNode(string str) {
    if (str == "null") return NULL;
    return new TreeNode(stoi(str));
  }

 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    vector<string> serializedNodes;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode* curr = q.front();
      q.pop();
      if (!curr)
        serializedNodes.push_back("null");
      else {
        serializedNodes.push_back(to_string(curr->val));
        q.push(curr->left);
        q.push(curr->right);
      }
    }
    string ret = "";
    ret += serializedNodes[0];
    for (int i = 1; i < serializedNodes.size(); i++)
      ret += ',' + serializedNodes[i];
    return ret;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    data += ',';
    vector<string> nodes;
    string node = "";
    for (int i = 0; i < data.size(); i++) {
      if (data[i] != ',')
        node += data[i];
      else {
        nodes.push_back(node);
        node = "";
      }
    }

    TreeNode* root = NULL;
    if (nodes[0] == "null") {
      TreeNode* root = NULL;
      return root;
    } else {
      root = new TreeNode(stoi(nodes[0]));
      queue<pair<TreeNode*, int>> q;
      q.push(make_pair(root, 0));
      q.push(make_pair(root, 1));
      int currIdx = 1;
      while (!q.empty()) {
        auto p = q.front();
        q.pop();
        TreeNode* curr = p.first;
        int order = p.second;
        if (order == 0) {
          curr->left = stringToTreeNode(nodes[currIdx++]);
          if (curr->left != NULL) {
            q.push(make_pair(curr->left, 0));
            q.push(make_pair(curr->left, 1));
          }
        } else {
          curr->right = stringToTreeNode(nodes[currIdx++]);
          if (curr->right != NULL) {
            q.push(make_pair(curr->right, 0));
            q.push(make_pair(curr->right, 1));
          }
        }
      }
    }
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
