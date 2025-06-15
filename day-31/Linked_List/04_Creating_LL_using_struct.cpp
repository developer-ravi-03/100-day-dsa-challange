// Linked List Node Creation using structure
// in static memory

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
  // ListNode node;
  // cout << "Linked List Node created with default constructor." << endl;
  // // The node is created with val = 0 and next = nullptr
  // cout << "Node value: " << node.val << endl;

  // type 2
  // ListNode node(10);
  // cout << "Linked List Node created with parameterized constructor." << endl;
  // cout << "Node value: " << node.val << endl;

  // type 3
  ListNode second(20);
  ListNode first(10, &second);

  cout << "first node value: " << first.val << endl;
  cout << "Linked List second Node  value: " << second.val << endl;

  return 0;
}