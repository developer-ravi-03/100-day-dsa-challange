// Leetcode : 138
// Problem: Copy List with Random Pointer
// TC: O(n)
// SC: O(n)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val)
  {
    val = _val;
    next = NULL;
    random = NULL;
  }
};
class Solution
{
public:
  Node *copyRandomList(Node *head)
  {
    if (head == NULL)
    {
      return NULL;
    }

    unordered_map<Node *, Node *> m;

    Node *newHead = new Node(head->val);
    Node *oldTemp = head->next;
    Node *newTemp = newHead;
    m[head] = newHead;

    while (oldTemp != NULL)
    {
      Node *copyNode = new Node(oldTemp->val);
      m[oldTemp] = copyNode; // store the value in map
      newTemp->next = copyNode;

      oldTemp = oldTemp->next;
      newTemp = newTemp->next;
    }

    oldTemp = head;
    newTemp = newHead;
    while (oldTemp != NULL)
    {
      newTemp->random = m[oldTemp->random];
      oldTemp = oldTemp->next;
      newTemp = newTemp->next;
    }
    return newHead;
  }
};
int main()
{
  // Example usage:
  Node *head = new Node(7);
  head->next = new Node(13);
  head->next->next = new Node(11);
  head->next->next->next = new Node(10);
  head->next->next->next->next = new Node(1);

  head->next->random = head;                               // 13's random points to 7
  head->next->next->random = head->next->next->next->next; // 11's random points to 1
  head->next->next->next->random = head->next->next;       // 10's random points to 11
  head->next->next->next->next->random = head;             // 1's random points to 7

  // before copying
  cout << "Original list:" << endl;
  Node *temp = head;
  while (temp != NULL)
  {
    cout << "Value: " << temp->val;
    if (temp->random)
      cout << ", Random: " << temp->random->val;
    else
      cout << ", Random: NULL";
    cout << endl;
    temp = temp->next;
  }
  // Copy the list
  Solution solution;
  Node *copiedList = solution.copyRandomList(head);
  // after copying
  cout << "Copied list:" << endl;
  Node *newtemp = copiedList;
  while (newtemp != NULL)
  {
    cout << "Value: " << newtemp->val;
    if (newtemp->random)
      cout << ", Random: " << newtemp->random->val;
    else

      cout << ", Random: NULL";
    cout << endl;
    newtemp = newtemp->next;
  }
  return 0;
}