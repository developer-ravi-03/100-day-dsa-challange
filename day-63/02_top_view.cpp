#include <bits/stdc++.h>
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
  vector<int> topView(TreeNode *root)
  {
    // your code goes here
    vector<int> ans;
    if (!root)
      return ans;

    queue<pair<TreeNode *, int>> Q;
    map<int, int> mp;
    Q.push({root, 0});
    while (Q.size() > 0)
    {
      TreeNode *curr = Q.front().first;
      int currHD = Q.front().second;
      Q.pop();

      if (mp.find(currHD) == mp.end())
      {
        mp[currHD] = curr->data;
      }

      if (curr->left)
      {
        Q.push({curr->left, currHD - 1});
      }

      if (curr->right)
      {
        Q.push({curr->right, currHD + 1});
      }
    }

    for (auto it : mp)
    {
      ans.push_back(it.second);
    }

    return ans;
  }
};

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->left->right->right = new TreeNode(5);
  root->left->right->right->right = new TreeNode(6);

  Solution sol;
  vector<int> result = sol.topView(root);

  cout << "Top view of binary tree: ";
  for (int val : result)
  {
    cout << val << " ";
  }
  cout << endl;

  // Free memory
  delete root->left->right->right->right;
  delete root->left->right->right;
  delete root->left->right;
  delete root->left;
  delete root->right;
  delete root;

  return 0;
}