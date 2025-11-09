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
  bool getAllPath(TreeNode *root, vector<int> &ans, int B)
  {
    if (!root)
      return false;
    ans.push_back(root->data);
    if (root->data == B)
    {
      return true;
    }
    if (getAllPath(root->left, ans, B) || getAllPath(root->right, ans, B))
    {
      return true;
    }
    ans.pop_back();
    return false;
  }

  vector<int> allRootToLeaf(TreeNode *root, int B)
  {
    // your code goes here
    vector<int> ans;
    if (root == NULL)
      return ans;
    getAllPath(root, ans, B);
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
  int B = 5;
  vector<int> paths = sol.allRootToLeaf(root, B);

  // print paths

  for (int i = 0; i < paths.size(); ++i)
  {
    cout << paths[i] << " ";
  }

  // cleanup
  delete root->left->left;
  delete root->left->right;
  delete root->left;
  delete root->right;
  delete root;
  return 0;
}