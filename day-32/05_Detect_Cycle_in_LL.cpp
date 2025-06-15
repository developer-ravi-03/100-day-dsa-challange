// Leetcode : 876
// Problem: Find the middle of a linked list
// Slow and Fast Approach
// TC: O(n)
// SC: O(1)
#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
  bool hasCycle(ListNode *head)
  {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
        return true;
    }
    return false;
  }
};

int main()
{
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  // Creating a cycle for testing
  head->next->next->next->next->next = head->next->next; // 5 points to 3

  Solution sl;
  bool hasCycle = sl.hasCycle(head);
  if (hasCycle)
  {
    cout << "The linked list has a cycle." << endl;
  }
  else
  {
    cout << "The linked list does not have a cycle." << endl;
  }

  return 0;
}