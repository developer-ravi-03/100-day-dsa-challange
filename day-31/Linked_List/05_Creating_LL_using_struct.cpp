// Linked List Node Creation using stack
// with pointers

#include <iostream>
using namespace std;
struct ListNode
{
  int val;
  ListNode *next;
  // type 1: Default constructor
  //  Default constructor initializes val to 0 and next to nullptr
  ListNode() : val(0), next(nullptr) {}

  // type 2: Parameterized constructor
  // Parameterized constructor to initialize with a specific value
  ListNode(int x) : val(x), next(nullptr) {}

  // type 3: Constructor with value and next pointer
  ListNode(int x, ListNode *nextNode) : val(x), next(nextNode) {}
};
int main()
{
  // type 1

  // ListNode *head = new ListNode();
  // head->next = new ListNode();
  // cout << "Linked List Node created with default constructor." << endl;
  // cout << "Node value: " << head->val << endl;
  // cout << "Node value: " << head->next->val << endl;
  // delete head->next; // Clean up memory
  // delete head;       // Clean up memory

  // type 2

  // ListNode *head = new ListNode(10);
  // head->next = new ListNode(20);
  // cout << "Linked List Node created with parameterized constructor." << endl;
  // cout << "Node value: " << head->val << endl;
  // cout << "Node value: " << head->next->val << endl;
  // delete head->next; // Clean up memory
  // delete head;       // Clean up memory

  // type 3
  ListNode *second = new ListNode(20);
  ListNode *first = new ListNode(10, second);
  cout << "first node value: " << first->val << endl;
  cout << "Linked List second Node value: " << second->val << endl;
  // Clean up memory
  delete first;
  delete second;

  return 0;
}