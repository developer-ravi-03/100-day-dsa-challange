#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *reverseLL(ListNode *head)
  {

    ListNode *currp = head;
    ListNode *nextp = NULL;
    ListNode *prevp = NULL;

    while (currp != NULL)
    {
      nextp = currp->next;
      currp->next = prevp;
      prevp = currp;
      currp = nextp;
    }
    return prevp;
  }
};

int main()
{
  // Create a sample linked list: 1->2->3->4->5
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  Solution sol;
  ListNode *newHead = sol.reverseLL(head);

  // Print the reversed list
  ListNode *curr = newHead;
  while (curr)
  {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;
  return 0;
}