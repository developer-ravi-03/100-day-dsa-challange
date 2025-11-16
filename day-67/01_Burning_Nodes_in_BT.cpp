// Minimum Time to taken Burn all nodes in BT
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
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
  void parentFind(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track)
  {
    queue<TreeNode *> Q;
    Q.push(root);
    while (!Q.empty())
    {
      TreeNode *curr = Q.front();
      Q.pop();
      if (curr->left)
      {
        Q.push(curr->left);
        parent_track[curr->left] = curr;
      }

      if (curr->right)
      {
        Q.push(curr->right);
        parent_track[curr->right] = curr;
      }
    }
  }

  TreeNode *burnStart(TreeNode *root, int start)
  {
    queue<TreeNode *> Q;
    Q.push(root);
    while (!Q.empty())
    {
      TreeNode *curr = Q.front();
      Q.pop();

      if (curr->data == start)
        return curr;

      if (curr->left)
      {
        Q.push(curr->left);
      }

      if (curr->right)
      {
        Q.push(curr->right);
      }
    }
    return NULL;
  }

public:
  int timeToBurnTree(TreeNode *root, int start)
  {
    // your code goes here
    unordered_map<TreeNode *, TreeNode *> parent_track;
    parentFind(root, parent_track);

    TreeNode *pos = burnStart(root, start);
    queue<TreeNode *> Q;
    unordered_map<TreeNode *, bool> visited;
    Q.push(pos);
    visited[pos] = true;
    int ans = 0;
    bool burned = false;
    while (!Q.empty())
    {
      int size = Q.size();

      for (int i = 0; i < size; i++)
      {
        TreeNode *curr = Q.front();
        Q.pop();

        if (curr->left && !visited[curr->left])
        {
          burned = true;
          visited[curr->left] = true;
          Q.push(curr->left);
        }

        if (curr->right && !visited[curr->right])
        {
          burned = true;
          visited[curr->right] = true;
          Q.push(curr->right);
        }

        if (parent_track[curr] && !visited[parent_track[curr]])
        {
          burned = true;
          visited[parent_track[curr]] = true;
          Q.push(parent_track[curr]);
        }
      }
      if (burned)
        ans++;
    }

    return ans - 1;
  }
};

int main()
{
  Solution sol;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(6);

  int start = 5;
  cout << sol.timeToBurnTree(root, start) << endl;
  return 0;
}