
#pragma once
// =======================================================
// File type: headher file  linkedlist.h
// Name: Leonardo Solorzano 
// Compiler:  g++ 
//=======================================================
#include <iostream>
#include <string>
using namespace std;


//define datatype T for linked list.
typedef int T;

//node structure
struct Node {
    T data;      //stored value
    Node* next;  //pointer to the next node

    //constructor
    Node(T data = 0, Node *next = nullptr){
        this->data = data;
        this->next = next;
    }
};
//----------------------------------------------------------

class LinkedList{ 
private:
    Node* head;
    Node* tail;
    int count;

 public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    ~LinkedList();

    LinkedList(const LinkedList &otherList);

    LinkedList &operator=(const LinkedList &otherList);

    void append(T data);

    void prepend(T data);

    bool deleteHead(T &data);

    bool deleteTail(T &data);

    int size() const;

    bool isEmpty() const;

    string toString();

    void displayAll();

    bool deleteNode(int pos, T &data);

    bool insertAt(int pos, T data);

    bool search(T key);

};



