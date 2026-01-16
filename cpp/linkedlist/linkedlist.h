
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

/**Linked List class */
class LinkedList{ 
// data members
private:
    Node* head;
    Node* tail;
    int count;
 public:
 //constructor
    LinkedList(){
        head = nullptr;
        tail = nullptr;
        count = 0;
    }


    /**
    * @brief Destroys the LinkedList and releases all allocated resources.
     *
     * Deallocates all nodes in the list to prevent memory leaks.
     * After destruction, the list is no longer usable.
     */
    ~LinkedList();


    /**
    * @brief Copy constructor.
    * Creates a deep copy of another LinkedList.
    * Each node in otherList is duplicated so that the two lists
    * do not share memory.
    * @param otherList The LinkedList to copy from.
    */
    LinkedList(const LinkedList &otherList);


    /**
    * @brief Assignment operator overload.
    * Replaces the contents of this list with a deep copy of another list.
    * Properly handles self-assignment and frees existing resources
    * before copying.
    * @param otherList The LinkedList to assign from.
    * @return Reference to this LinkedList after assignment.
    */
    LinkedList &operator=(const LinkedList &otherList);


    /**
    * @brief Appends a new element to the end of the list.
    * Creates a new node containing the provided data and places it
    * after the current tail of the list.
    * @param data The value to be added to the list.
    */
    void append(T data);


    /**
    * @brief Prepends a new element to the beginning of the list.
    * Creates a new node containing the provided data and places it
    * before the current head of the list.
    * @param data The value to be added to the list.
    */
    void prepend(T data);


    /**
    * @brief Removes the first element of the list.
    * If the list is not empty, the head node is removed and its data
    * is returned via the reference parameter.
    * @param data Reference used to store the removed element's value.
    * @return true if a node was removed, false if the list was empty.
    */
    bool deleteHead(T &data);


    /**
    * @brief Removes the last element of the list.
    * If the list is not empty, the tail node is removed and its data
    * is returned via the reference parameter.
    * @param data Reference used to store the removed element's value.
    * @return true if a node was removed, false if the list was empty.
    */
    bool deleteTail(T &data);


    /**
    * @brief Returns the number of elements in the list.
    * @return The total number of nodes currently in the list.
    */
    int size() const;


    /**
    * @brief Checks whether the list is empty.
    * @return true if the list contains no nodes, false otherwise.
    */
    bool isEmpty() const;


    /**
    * @brief Converts the list contents into a string representation.
    * The format of the string is implementation-defined, but typically
    * represents elements in sequential order.
    * @return A string containing all list elements.
    */
    string toString();


    /**
    * @brief Displays all elements in the list.
    *
    * Outputs the contents of the list in order, typically to standard output.
    * Intended primarily for debugging or demonstration purposes.
    */
    void displayAll();


    /**
    * @brief Deletes the node at a specified position.
    * Positions are assumed to be zero-based. If the position is valid,
    * the node is removed and its data is returned.
    * @param pos Zero-based index of the node to delete.
    * @param data Reference used to store the removed element's value.
    * @return true if the node was successfully deleted, false otherwise.
    */
    bool deleteNode(int pos, T &data);


    /**
    * @brief Inserts a new element at a specified position.
    * Positions are assumed to be zero-based. If the position is valid,
    * a new node is inserted at that location.
    * @param pos Zero-based index at which to insert the new element.
    * @param data The value to be inserted into the list.
    * @return true if the insertion was successful, false otherwise.
    */
    bool insertAt(int pos, T data);


    /**
    * @brief Searches the list for a given key.
    * Traverses the list and checks whether any node contains the given key.
    * @param key The value to search for.
    * @return true if the key is found, false otherwise.
    */
    bool search(T key);

};



