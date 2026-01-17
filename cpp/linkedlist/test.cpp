//=============================================================================
/**
 * @file test.cpp
 * @brief Driver program for testing the LinkedList class.
 *
 * This program provides a menu-driven interface that allows a user
 * to interactively test various LinkedList operations, including
 * insertion, deletion, searching, copying, and assignment.
 *
 * Each menu option constructs a LinkedList instance and exercises
 * a specific method to verify correctness and behavior.
 *
 * @author Leonardo Solorzano
 * @date   01/16/2026
 */
//=============================================================================
#include "linkedlist.h"
#include <iostream>
using namespace std;


int main() {
    int value;

    // Display menu of available LinkedList operations
    std::cout << "1) Push Front" << std::endl << "2) Push Back" << std::endl 
              << "3) Pop Front" << std::endl << "4) Pop Back "  << std::endl 
              << "5) Insert At Index" << std::endl << "6) Remove At Index" << std::endl
              << "7) Find" << std::endl << "8) Clear" << std::endl << "9) Copy Test" << std::endl 
              << "10)Assign Test" << std::endl<< "11) Exit" << std::endl;
    
    // Read user’s menu selection
    std::cin >> value;

    // Exit early if the user chooses to quit
    if (value == 11){
        std::cout << "have a nice day!" << std::endl;
        return 0;
    }
    else if(value == 1){
        LinkedList list;
        int node;
         std::cout << "First make your list (enter 5 single digit numbers) :";
        for(int i = 0; i < 5; i++){
            std::cin >> node;
            list.append(node);
        }
        std::cout << "Your list: " << std::endl;
        list.displayAll();
        std::cout << "Enter number to push to front: ";
        std::cin >> node;
        list.prepend(node);
        std::cout << "Your new list: " << std::endl;
        list.displayAll();
    }
    else if (value == 2){
        LinkedList list;
        int node;
         std::cout << "First make your list (enter 5 single digit numbers) :";
        for(int i = 0; i < 5; i++){
            std::cin >> node;
            list.append(node);
        }
        std::cout << "Your list: " << std::endl;
        list.displayAll();
        std::cout << "Enter number to push to back: ";
        std::cin >> node;
        list.append(node);
        std::cout << "Your new list: " << std::endl;
        list.displayAll();
    }
    else if (value == 3){
        LinkedList list;
        int node;
        std::cout << "First make your list (enter 5 single digit numbers) :";
        for(int i = 0; i < 5; i++){
            std::cin >> node;
            list.append(node);
        }
        
        std::cout << "Your list before popping: " << std::endl;
        list.displayAll();
        std::cout << "Popping front element..." << std::endl;
        list.deleteHead(node);
        std::cout << "Your list after popping: " << std::endl;
        list.displayAll();
    }
    else if (value == 4){
        LinkedList list;
        int node;
         std::cout << "First make your list (enter 5 single digit numbers) :";
        for(int i = 0; i < 5; i++){
            std::cin >> node;
            list.append(node);
        }
        std::cout << "Your list before popping: " << std::endl;
        list.displayAll();
        std::cout << "Popping back element..." << std::endl;
        list.deleteTail(node);
        std::cout << "Your list after popping: " << std::endl;
        list.displayAll();
    }
    else if (value == 5){
        LinkedList list;
        int node;
         std::cout << "First make your list (enter 5 single digit numbers) :";
        for(int i = 0; i < 5; i++){
            std::cin >> node;
            list.append(node);
        }
        std::cout << "Your List: " << std::endl;
        list.displayAll();
        std::cout << "Enter index to insert at: ";
        int index;
        std::cin >> index;
        std::cout << "Enter value to insert: ";
        std::cin >> node;
        list.insertAt(index, node);
        std::cout << "Your List after insertion: " << std::endl;
        list.displayAll();
    }
    else if (value == 6){
        LinkedList list;
        int node;
        std::cout << "First make your list (enter 5 single digit numbers) :";
        for(int i = 0; i < 5; i++){
            std::cin >> node;
            list.append(node);
        }
        std::cout << "Your List: " << std::endl;
        list.displayAll();
        std::cout << "Enter index to delete at: ";
        int index;
        std::cin >> index;
        list.deleteNode(index, node);
        std::cout << "Your List after deletion: " << std::endl;
        list.displayAll();
    }
    else if(value == 7){
        LinkedList list;
        int node;
        std::cout << "First make your list (enter 5 single digit numbers) :";
        for(int i = 0; i < 5; i++){
            std::cin >> node;
            list.append(node);
        }
        std::cout << "Your List: " << std::endl;
        list.displayAll();
        std::cout << "Enter number you want to search for: ";
        int key;
        std::cin >> key;
        if(list.search(key)){
            std::cout << key << " was found in list";
        }
        else{
            std::cout << key << " was not found in the list... sorry";
        }
        ;

    }
    else if (value == 8){
        LinkedList list;
        int node;
         std::cout << "First make your list (enter 5 single digit numbers) :";
        for(int i = 0; i < 5; i++){
            std::cin >> node;
            list.append(node);
        }
        std::cout << "Your List: " << std::endl;
        list.displayAll();
        std::cout << "deleting linkedlist..." << std::endl;
        list.~LinkedList();
        list.displayAll();
    }
    else if (value == 9){
        LinkedList list1;
        int node;
         std::cout << "First make your list (enter 5 single digit numbers) :";
        for(int i = 0; i < 5; i++){
            std::cin >> node;
            list1.append(node);
        }
        std::cout << "Your List 1: " << std::endl;
        list1.displayAll();
        LinkedList list2 = list1; //copy constructor
        std::cout << "Copied List 2 from List 1: " << std::endl;
        list2.displayAll();
    }
    else if (value == 10){
        LinkedList list1;
        int node;
         std::cout << "First make your list (enter 5 single digit numbers) :";
        for(int i = 0; i < 5; i++){
            std::cin >> node;
            list1.append(node);
        }
        std::cout << "Your List 1: " << std::endl;
        list1.displayAll();
        LinkedList list2;
        list2 = list1; //assignment operator
        std::cout << "Assigned List 2 from List 1: " << std::endl;
        list2.displayAll();
    }
    else{
        std::cout << "Invalid choice." << std::endl;
    }

}