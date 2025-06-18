#include <iostream>
using namespace std;
class Node
{
public:
  int data;
  Node *next;
  Node *prev;

  Node(int val)
  {
    data = val;
    next = prev = NULL;
  }
};
class DoublyLinkedList
{
public:
  Node *head;
  Node *tail;
  DoublyLinkedList()
  {
    head = tail = NULL;
  }

  // push a new node at the front of the list
  void push_front(int val)
  {
    Node *newNode = new Node(val);
    if (head == NULL)
    {
      head = tail = newNode;
    }
    else
    {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
  }

  // push a new node at the back of the list
  void push_back(int val)
  {
    Node *newNode = new Node(val);
    if (head == NULL)
    {
      head = tail = newNode;
    }
    else
    {
      newNode->prev = tail;
      tail->next = newNode;
      tail = newNode;
    }
  }

  // pop a node from the front of the list
  void pop_front()
  {
    Node *temp = head;
    if (head == NULL)
    {
      cout << "List is empty, nothing to pop." << endl;
      return;
    }

    head = head->next;
    if (head != NULL)
    {
      head->prev = NULL; // Update the new head's prev pointer
    }
    temp->next = NULL; // Clear the popped node's next pointer
    delete temp;       // Free the memory of the popped node
  }

  // pop a node from the back of the list
  void pop_back()
  {

    if (tail == NULL)
    {
      cout << "List is empty, nothing to pop." << endl;
      return;
    }
    Node *temp = tail;
    tail = tail->prev;
    if (tail != NULL)
    {
      tail->next = NULL; // Update the new tail's next pointer
    }

    temp->prev = NULL; // Clear the popped node's prev pointer
    delete temp;       // Free the memory of the popped node
  }

  // print the list from head to tail
  void printList()
  {
    Node *temp = head;
    cout << "Doubly Linked List: " << endl;
    cout << "NULL <=> ";
    while (temp != NULL)
    {
      cout << temp->data << " <=> ";
      temp = temp->next;
    }
    cout << " NULL" << endl;
  }
};
int main()
{
  DoublyLinkedList dll;
  dll.push_front(10);
  dll.push_front(20);
  dll.push_front(30);
  dll.push_front(40);

  dll.printList();

  cout << "After pushing back elements:" << endl;
  dll.push_back(50);
  dll.push_back(60);

  dll.printList();

  cout << "After popping front element:" << endl;
  dll.pop_front();
  dll.pop_front();

  dll.printList();

  cout << "After popping back element:" << endl;
  dll.pop_back();
  dll.pop_back();
  dll.printList();

  return 0;
}