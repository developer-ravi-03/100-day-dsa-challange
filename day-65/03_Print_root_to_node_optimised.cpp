#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
  void getAllPath(TreeNode *root, vector<vector<int>> &ans, vector<int> &tmp)
  {
    if (!root)
      return;
    tmp.push_back(root->data);

    if (!root->left && !root->right)
    {
      ans.push_back(tmp);
    }
    else
    {
      getAllPath(root->left, ans, tmp);
      getAllPath(root->right, ans, tmp);
    }
    tmp.pop_back();
  }

  vector<vector<int>> allRootToLeaf(TreeNode *root)
  {
    // your code goes here
    vector<vector<int>> ans;
    vector<int> tmp;
    if (root == NULL)
      return ans;
    getAllPath(root, ans, tmp);
    return ans;
  }
};

int main()
{
  // build a sample tree:
  //        1
  //       / \
  //      2   3
  //     / \
  //    4   5
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  Solution sol;
  vector<vector<int>> paths = sol.allRootToLeaf(root);

  // print paths
  for (const auto &p : paths)
  {
    for (size_t i = 0; i < p.size(); ++i)
    {
      cout << p[i] << (i + 1 < p.size() ? " " : "");
    }
    cout << "\n";
  }

  // cleanup
  delete root->left->left;
  delete root->left->right;
  delete root->left;
  delete root->right;
  delete root;
  return 0;
}