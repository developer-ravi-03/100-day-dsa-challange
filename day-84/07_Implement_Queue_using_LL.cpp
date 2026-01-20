// Implement Queue using LL
// Striver
#include <iostream>
#include <stack>
using namespace std;
class LinkedListQueue {
private:
    struct Node{
        int data;
        Node* next;
        Node(int x){
            data=x;
            next=NULL;
        }
    };
    // Node* front;

public:
    Node* start;
    Node* end;
    LinkedListQueue() {
        start=end=NULL;
    }
    
    void push(int x) {
        Node* temp=new Node(x);
        if(start==NULL){
            start=end=temp;
        }else{
            end->next=temp;
            end=temp;
        }
    }
    
    int pop() {
        if(isEmpty()){
            return -1;
        }
        int poped=start->data;
        Node* temp=start;
        start=start->next;
        delete temp;
        return poped;
    }
    
    int peek() {
        if(isEmpty()){
            return -1;
        }
        return start->data;
    }
    
    bool isEmpty() {
        return start==NULL;
    }
};
int main()
{
  LinkedListQueue q;
    
  q.push(10);
  q.push(20);
  q.push(30);

  cout << "Queue peek: " << q.peek() << endl;
  cout << "Queue pop: " << q.pop() << endl;
  cout << "Queue pop: " << q.pop() << endl;
  cout << "Queue peek: " << q.peek() << endl;
  cout << "Queue pop: " << q.pop() << endl;
  cout << "Is empty: " << q.isEmpty() << endl;
  return 0;
}