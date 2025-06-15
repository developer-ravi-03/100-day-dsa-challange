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
  ListNode *mergeTwoLists(ListNode *head1, ListNode *head2)
  {
    if (head1 == NULL || head2 == NULL)
      return head1 == NULL ? head2 : head1;

    if (head1->val <= head2->val)
    {
      head1->next = mergeTwoLists(head1->next, head2);
      return head1;
    }
    else
    {
      head2->next = mergeTwoLists(head1, head2->next);
      return head2;
    }
  }
};
int main()
{
  ListNode *head1 = new ListNode(1);
  head1->next = new ListNode(3);
  head1->next->next = new ListNode(5);

  ListNode *head2 = new ListNode(2);
  head2->next = new ListNode(3);
  head2->next->next = new ListNode(6);
  // before merging
  ListNode *temp1 = head1;
  ListNode *temp2 = head2;
  cout << "List 1: ";
  while (temp1 != NULL)
  {
    cout << temp1->val << " ";
    temp1 = temp1->next;
  }
  cout << endl;
  cout << "List 2: ";
  while (temp2 != NULL)
  {
    cout << temp2->val << " ";
    temp2 = temp2->next;
  }
  cout << endl;
  // merging the linked lists
  cout << "Merging the linked lists..." << endl;
  Solution sl;
  ListNode *mergedHead = sl.mergeTwoLists(head1, head2);
  ListNode *temp = mergedHead;
  cout << "Merged List: ";
  while (temp != NULL)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;

  return 0;
}