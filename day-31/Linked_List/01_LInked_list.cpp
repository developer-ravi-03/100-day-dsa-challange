#include <iostream>
using namespace std;
class Node
{
public:
  int data;
  Node *next;

  Node(int val)
  {
    data = val;
    next = NULL;
  }
};

class List
{
  Node *head;
  Node *tail;

public:
  List()
  {
    head = tail = NULL;
  }

  // for push front operation
  void push_front(int val) // O(1)
  {
    Node *newNode = new Node(val); // dynamic allocation
    // Node newNode(val); // static allocation (not recommended for linked lists because it will not be freed automatically)
    if (head == NULL)
    {
      head = tail = newNode;
    }
    else
    {
      newNode->next = head;
      head = newNode;
    }
  }

  // for push front operation
  void push_back(int val) // O(1) -> if use tail pointer  if not use tail pointer O(n)
  {
    Node *newNode = new Node(val);
    if (head == NULL)
    {
      head = tail = newNode;
    }
    else
    {
      tail->next = newNode;
      tail = newNode;
    }
  }

  // pop front operation
  void pop_front() // O(1)
  {
    if (head == NULL)
    {
      cout << "List is empty!" << endl;
      return;
    }
    Node *temp = head;
    head = head->next;
    temp->next = NULL; // disconnect the node from the list
    delete temp;       // free memory
    if (head == NULL)  // if the list becomes empty
      tail = NULL;
  }

  // pop back operation
  void pop_back() // O(n) -> if use tail pointer O(1)
  {
    if (head == NULL)
    {
      cout << "List is empty!" << endl;
      return;
    }

    // if (head == tail) // only one element
    // {
    //   delete head;
    //   head = tail = NULL;
    //   return;
    // }
    Node *temp = head;
    while (temp->next != tail) // find the second last node
    {
      temp = temp->next;
    }
    temp->next = NULL; // disconnect the last node
    delete tail;       // free memory of the last node
    tail = temp;       // update tail to the second last node
  }

  // print linkedlist
  void printll() // O(n)
  {
    Node *temp = head;
    while (temp != NULL)
    {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
};

int main()
{
  List ll;
  // push front operation
  ll.push_front(1);
  ll.push_front(2);
  ll.push_front(3);

  // push back operation
  ll.push_back(4);
  ll.push_back(5);
  ll.push_back(6);

  ll.printll();

  // pop front operation
  ll.pop_front();
  ll.pop_front();

  ll.printll();

  // pop back operation
  ll.pop_back();
  ll.pop_back();
  ll.printll();
  return 0;
}