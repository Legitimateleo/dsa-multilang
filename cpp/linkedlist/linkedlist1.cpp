#include "linkedlist.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

LinkedList:: ~LinkedList(){
     Node* current = head;
     while (current!= nullptr){
          Node* next = current ->next;
          delete current;
          current = next;
     }
}

bool LinkedList::isEmpty() const {
     if(head == nullptr){
          return true;
     }
     else{
          return false;
     }
}

int LinkedList::size() const {
     return count;
}

string LinkedList::toString(){
     stringstream ss;
     Node* current = head;
     while(current != nullptr){
          ss << current->data;
          current = current -> next;
     }
     return ss.str();

}

void LinkedList:: displayAll(){
     cout << toString() << endl;
}


void LinkedList::append(T data) {
     if( head == nullptr){
          head = new Node(data);
          tail = head;
          count++;
     }
     else if(tail != nullptr){
          Node* newNode = new Node(data);
          tail->next = newNode;
          tail = newNode;
          count++;
     }
     else{
          cerr << "Error: Tail is null while head is not null." << endl;
     }
}

void LinkedList::prepend(T data) {
     if(head == nullptr){
          head = new Node(data);
          tail = head;
          count++;
     }
     else{
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
          data = head -> data;
          delete head;
          head = nullptr;
          count--;
          return true;
     }
     else{
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
     }
}

bool LinkedList:: deleteNode(int pos, T &data){
     if(pos < 0 || pos >= count){
          return false;
     }
     if(pos == 0){
          return deleteHead(data);
     }
     else{
          Node* current = head;
          for(int i = 0; i < pos -1; i++){
               current = current -> next;
          }
          if(current != nullptr && current->next != nullptr){
               Node* temp = current->next;
               data = temp->data;
               current->next = temp->next;
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

     Node* current = otherList.head;
     while(current != nullptr){
          append(current -> data);
          current = current -> next;
     }
     count = otherList.count;
}

LinkedList & LinkedList::operator=(const LinkedList &otherList){
     if(this != &otherList) {                            
        this->~LinkedList();                       
        new (this) LinkedList(otherList);               
    }                                               
    
    return *this;

}
