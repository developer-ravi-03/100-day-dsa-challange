#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                     right(right) {}
};

class Solution
{
  void addLeftBoundry(TreeNode *root, vector<int> &ans)
  {
    TreeNode *curr = root->left;
    while (curr)
    {
      if (!isLeaf(curr))
      {
        ans.push_back(curr->val);
      }

      if (curr->left)
      {
        curr = curr->left;
      }
      else
      {
        curr = curr->right;
      }
    }
  }

  void addRightBoundry(TreeNode *root, vector<int> &ans)
  {
    TreeNode *curr = root->right;
    vector<int> tmp;
    while (curr)
    {
      if (!isLeaf(curr))
      {
        tmp.push_back(curr->val);
      }

      if (curr->right)
      {
        curr = curr->right;
      }
      else
      {
        curr = curr->left;
      }
    }

    for (int i = tmp.size() - 1; i >= 0; --i)
    {
      ans.push_back(tmp[i]);
    }
  }

  void addLeaf(TreeNode *root, vector<int> &ans)
  {
    if (isLeaf(root))
    {
      ans.push_back(root->val);
      return;
    }

    if (root->left)
    {
      addLeaf(root->left, ans);
    }

    if (root->right)
    {
      addLeaf(root->right, ans);
    }
  }

  bool isLeaf(TreeNode *root)
  {
    return root != NULL && root->left == NULL && root->right == NULL;
  }

public:
  vector<int> PrintBoundry(TreeNode *root)
  {
    vector<int> ans;
    if (!root)
    {
      return ans;
    }
    if (!isLeaf(root))
    {
      ans.push_back(root->val);
    }

    addLeftBoundry(root, ans);
    addLeaf(root, ans);
    addRightBoundry(root, ans);
    return ans;
  }
};

int main()
{
  // Create a binary tree
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(3);
  root->left->left->right = new TreeNode(4);
  root->left->left->right->left = new TreeNode(5);
  root->left->left->right->right = new TreeNode(6);
  root->right->right = new TreeNode(8);
  root->right->right->left = new TreeNode(9);
  root->right->right->left->left = new TreeNode(10);
  root->right->right->left->right = new TreeNode(11);

  Solution solution;
  vector<int> boundry = solution.PrintBoundry(root);
  for (int val : boundry)
  {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}