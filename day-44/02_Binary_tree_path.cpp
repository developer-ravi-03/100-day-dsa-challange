#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  void allPath(TreeNode *root, string path, vector<string> &ans)
  {
    if (root->left == NULL && root->right == NULL)
    {
      ans.push_back(path);
      return;
    }

    if (root->left)
    {
      allPath(root->left, path + "->" + to_string(root->left->val), ans);
    }

    if (root->right)
    {
      allPath(root->right, path + "->" + to_string(root->right->val), ans);
    }
  }

  vector<string> binaryTreePaths(TreeNode *root)
  {
    vector<string> ans;
    string path = to_string(root->val);

    allPath(root, path, ans);
    return ans;
  }
};

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(4);

  Solution sol;
  vector<string> paths = sol.binaryTreePaths(root);

  for (const string &path : paths)
  {
    cout << path << endl;
  }
  return 0;
}