// bottom view
#include <iostream>
#include <vector>
#include <queue>
#include <map>
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
  vector<int> bottomView(TreeNode *root)
  {
    // your code goes here
    queue<pair<TreeNode *, int>> Q;
    map<int, int> mp;
    Q.push({root, 0});

    while (!Q.empty())
    {
      TreeNode *curr = Q.front().first;
      int currHD = Q.front().second;
      Q.pop();

      mp[currHD] = curr->data;

      if (curr->left)
      {
        Q.push({curr->left, currHD - 1});
      }

      if (curr->right)
      {
        Q.push({curr->right, currHD + 1});
      }
    }

    vector<int> ans;
    for (auto it : mp)
    {
      ans.push_back(it.second);
    }
    return ans;
  }
};
int main()
{
  // Create a binary tree
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  // Create solution object and get bottom view
  Solution solution;
  vector<int> result = solution.bottomView(root);

  // Print the bottom view
  cout << "Bottom view of binary tree: ";
  for (int val : result)
  {
    cout << val << " ";
  }
  cout << endl;
  return 0;
}