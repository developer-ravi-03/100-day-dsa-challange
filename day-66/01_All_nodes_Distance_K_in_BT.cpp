// All_nodes_Distance_K_in_BT
// Leetcode : 863
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
  void markParent(TreeNode *root,
                  unordered_map<TreeNode *, TreeNode *> &parent_track)
  {
    queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty())
    {
      TreeNode *curr = queue.front();
      queue.pop();
      if (curr->left)
      {
        queue.push(curr->left);
        parent_track[curr->left] = curr;
      }
      if (curr->right)
      {
        queue.push(curr->right);
        parent_track[curr->right] = curr;
      }
    }
  }

public:
  vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
  {
    unordered_map<TreeNode *, TreeNode *> parent_track; // node->parent;
    markParent(root, parent_track);

    unordered_map<TreeNode *, bool> visited;
    queue<TreeNode *> queue;
    queue.push(target);
    visited[target] = true;
    int curr_lvl = 0;
    while (!queue.empty())
    {
      int size = queue.size();
      if (curr_lvl++ == k)
        break;

      for (int i = 0; i < size; i++)
      {
        TreeNode *curr = queue.front();
        queue.pop();

        if (curr->left && !visited[curr->left])
        {
          queue.push(curr->left);
          visited[curr->left] = true;
        }

        if (curr->right && !visited[curr->right])
        {
          queue.push(curr->right);
          visited[curr->right] = true;
        }

        if (parent_track.count(curr) && !visited[parent_track[curr]])
        {
          queue.push(parent_track[curr]);
          visited[parent_track[curr]] = true;
        }
      }
    }

    vector<int> result;
    while (!queue.empty())
    {
      TreeNode *curr = queue.front();
      queue.pop();
      result.push_back(curr->val);
    }
    return result;
  }
};

int main()
{
  // build example tree: [3,5,1,6,2,0,8,null,null,7,4]
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);

  TreeNode *target = root->left; // node with value 5
  int k = 2;

  Solution sol;
  vector<int> ans = sol.distanceK(root, target, k);

  // print result
  for (int v : ans)
    cout << v << ' ';
  cout << endl;
  return 0;
}