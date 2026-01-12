// Linked List Cycle II
//  Leetcode: 142
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
  ListNode *detectCycle(ListNode *head)
  {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (fast == slow)
      {
        slow = head;
        while (fast != slow)
        {
          slow = slow->next;
          fast = fast->next;
        }
        return slow;
      }
    }
    return NULL;
  }
};
int main()
{
  // Create a linked list with a cycle
  ListNode *head = new ListNode(3);
  head->next = new ListNode(2);
  head->next->next = new ListNode(0);
  head->next->next->next = new ListNode(-4);
  head->next->next->next->next = head->next; // Create cycle

  Solution sol;
  ListNode *cycleStart = sol.detectCycle(head);

  if (cycleStart != NULL)
  {
    cout << "Cycle starts at node with value: " << cycleStart->val << endl;
  }
  else
  {
    cout << "No cycle found" << endl;
  }
  return 0;
}