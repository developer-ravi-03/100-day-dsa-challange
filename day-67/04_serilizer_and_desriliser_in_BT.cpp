#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Codec
{
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root)
  {
    if (!root)
      return "";

    string res = "";
    queue<TreeNode *> Q;
    Q.push(root);

    while (!Q.empty())
    {
      TreeNode *node = Q.front();
      Q.pop();
      if (node)
      {
        res += to_string(node->data) + ",";
        Q.push(node->left);
        Q.push(node->right);
      }
      else
      {
        res += "#,";
      }
    }
    return res;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data)
  {
    if (data.size() == 0)
      return NULL;

    // Converts the entire serialized string into a stream-like object
    stringstream ss(data);

    string token;

    // Reads characters until it sees a comma.
    getline(ss, token, ',');

    // stoi("1") converts it to integer 1
    TreeNode *root = new TreeNode(stoi(token));
    queue<TreeNode *> Q;
    Q.push(root);

    while (!Q.empty())
    {
      TreeNode *node = Q.front();
      Q.pop();

      getline(ss, token, ',');
      if (token == "#")
      {
        node->left = NULL;
      }
      else
      {
        node->left = new TreeNode(stoi(token));
        Q.push(node->left);
      }

      getline(ss, token, ',');
      if (token == "#")
      {
        node->right = NULL;
      }
      else
      {
        node->right = new TreeNode(stoi(token));
        Q.push(node->right);
      }
    }

    return root;
  }
};

int main()
{

  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  Codec codec;
  string serialized = codec.serialize(root);
  cout << "Serialized: " << serialized << endl;

  TreeNode *deserialized = codec.deserialize(serialized);
  string reserialized = codec.serialize(deserialized);
  cout << "Deserialized and reserialized: " << reserialized << endl;

  return 0;
}
