#include "linkedlist.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

LinkedList:: ~LinkedList(){
     // Standard linear-time destruction:
     // walk from head, delete nodes one-by-one.
     Node* current = head;
     while (current!= nullptr){
          Node* next = current ->next; // save next before deleting current
          delete current;
          current = next;
     }
     // If you ever (incorrectly) call the destructor manually, resetting these
     // would reduce the chance of accidental use-after-free:
     // head = nullptr; tail = nullptr; count = 0;
}


bool LinkedList::isEmpty() const {
     // Empty list is represented by head == nullptr
     if(head == nullptr){
          return true;
     }
     else{
          return false;
     }
}

int LinkedList::size() const {
     // O(1) because we maintain a running count
     return count;
}

string LinkedList::toString(){
     // Build a string from list contents by streaming node data in order.
     // Note: no separators, so multi-digit values can be ambiguous.
     stringstream ss;
     Node* current = head;
     while(current != nullptr){
          ss << "[";
          ss << current->data;
          current = current -> next;
          ss << "] ";
     }
     return ss.str();

}

void LinkedList:: displayAll(){
     // Centralizing formatting in toString() keeps displayAll() simple.
     cout << toString() << endl;
}


void LinkedList::append(T data) {
     // First node: head and tail should both point to it.
     if( head == nullptr){
          head = new Node(data);
          tail = head;
          count++;
     }
     // Normal case: link new node after tail, then advance tail.
     else if(tail != nullptr){
          Node* newNode = new Node(data);
          tail->next = newNode;
          tail = newNode;
          count++;
     }
     // Defensive check: tail should never be null if head isn't.
     else{
          cerr << "Error: Tail is null while head is not null." << endl;
     }
}

void LinkedList::prepend(T data) {
     if(head == nullptr){
           // First node: head and tail should both point to it.
          head = new Node(data);
          tail = head;
          count++;
     }
     else{
          // Insert before head: newNode points to old head, then head updates.
          Node* newNode = new Node(data);
          newNode -> next = head;
          head = newNode;
          count++;
     }
}

bool LinkedList::deleteHead(T &data){
     if(head == nullptr){
          return false;
     }
     else{
          // Save value before deleting node, then advance head.
          Node* temp = head;
          data = head -> data;
          head = head -> next;
          delete temp;
          count--;
          return true;
     }
}

bool LinkedList:: deleteTail(T &data){
     if(head == nullptr){
          return false;
     }
     else if(head-> next == nullptr){
          // Single-node list: removing tail also removes head.
          data = head -> data;
          delete head;
          head = nullptr;
          tail = nullptr;
          count--;
          return true;
     }
     else{
          // Singly-linked list: to delete tail, we must find the node *before* tail.
          Node* current = head;
          while(current != nullptr && current-> next != tail){
               current = current -> next;
          }
          if(current != nullptr){
               data = tail -> data;
               delete tail;
               tail = current;
               tail -> next = nullptr;
               count--;
               return true;
          }    
     return false;
     }
}

bool LinkedList:: deleteNode(int pos, T &data){
     if(pos < 0 || pos >= count){
          return false;
     }
     if(pos == 0){
          // Reuse existing logic for head deletion
          return deleteHead(data);
     }
     else{
          // Stop at node right before the one being removed.
          Node* current = head;
          for(int i = 0; i < pos -1; i++){
               current = current -> next;
          }
          if(current != nullptr && current->next != nullptr){
               Node* temp = current->next;
               data = temp->data;
               current->next = temp->next;
               if (temp == tail) {
                    // Update tail if we removed the last node
                    tail = current;
               }
               delete temp;
               count--;
               return true;
          }
          return false;
     }
}

bool LinkedList::insertAt(int pos, T data){
     if(pos < 0 || pos >= count){
          return false;
     }
     if(pos == 0){
          prepend(data);
          return true;
     }
     else{
          // Stop at node right before insertion point.
          Node* current = head;
          for(int i = 0; i < pos -1; i++){
               current = current -> next;
          }
          Node* newNode = new Node(data);
          newNode -> next = current -> next;
          current -> next = newNode;
          count++;
          return true;
          }
     return false;
}

LinkedList::LinkedList(const LinkedList &otherList){
     head = nullptr;
     tail = nullptr;
     count = 0;

     // Deep copy by iterating other list and appending values in order.
     Node* current = otherList.head;
     while(current != nullptr){
          append(current -> data);
          current = current -> next;
     }
}

LinkedList & LinkedList::operator=(const LinkedList &otherList){
     if(this != &otherList) {                            
        this->~LinkedList();                       
        new (this) LinkedList(otherList);               
    }                                               
    
    return *this;

}

bool LinkedList::search(T key){
     // Linear search: walk the list until key is found or we hit nullptr.
     Node* current = head;
     while(current != nullptr){
          if( current -> data == key){
               return true;
          }
          current = current -> next;
     }
     return false;
}