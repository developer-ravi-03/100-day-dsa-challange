// Leetcode - 141
#include <iostream>
using namespace std;
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
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
  // Create a cycle: 1 -> 2 -> 3 -> 4 -> 2 ...
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = head->next; // cycle

  Solution sol;
  if (sol.hasCycle(head))
    cout << "Cycle detected\n";
  else
    cout << "No cycle\n";

  // Note: This leaks memory due to the cycle.
  return 0;
}