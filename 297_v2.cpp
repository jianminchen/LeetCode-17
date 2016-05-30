/*
  297_v2.cpp
  Serialize and Deserialize Binary Tree
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
  void serialize(TreeNode* root, ostringstream& out) {
    if (root == NULL)
      out << "null ";
    else {
      out << root->val << " ";
      serialize(root->left, out);
      serialize(root->right, out);
    }
  }

  TreeNode* deserialize(istringstream& in) {
    string node;
    in >> node;
    TreeNode* root;
    if (node == "null")
      root = NULL;
    else {
      root = new TreeNode(stoi(node));
      root->left = deserialize(in);
      root->right = deserialize(in);
    }
    return root;
  }

 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    ostringstream out;
    serialize(root, out);
    return out.str();
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    istringstream in(data);
    return deserialize(in);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));