#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
};

// build tree
static int idx = -1;
Node *buildTree(vector<int> preorder)
{
  idx++;
  if (idx >= preorder.size() || preorder[idx] == -1)
  {
    return NULL;
  }

  Node *root = new Node(preorder[idx]);
  root->left = buildTree(preorder);  // left
  root->right = buildTree(preorder); // right

  return root;
}

// LevelOrder
void levelOrder(Node *root)
{
  queue<Node *> Q;

  Q.push(root);
  Q.push(NULL);

  while (Q.size() > 0)
  {
    Node *curr = Q.front();
    Q.pop();

    if (curr == NULL)
    {
      if (!Q.empty())
      {
        cout << endl;
        Q.push(NULL);
        continue;
      }
      else
      {
        break;
      }
    }

    cout << curr->data << " ";

    if (curr->left != NULL)
    {
      Q.push(curr->left);
    }

    if (curr->right != NULL)
    {
      Q.push(curr->right);
    }
  }
}

int main()
{
  vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

  Node *root = buildTree(preorder);
  levelOrder(root);

  return 0;
}