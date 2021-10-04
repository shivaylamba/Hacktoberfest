/*
••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
         SINGLY LINKED LISTS IN C++ WITH OOP APPROACH
 ****************************************************************
    BAIMAM BOUKAR JEAN JACQUES
    baimam.jeanjaque@ictuniversity.edu.cm
    (+237) 690 53 57 59 / 6 79 78 22 55
••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
*/

#include "node.h"
#include <string>
#include <iostream>
using namespace std;


    /*
                                CONTRUCTORS
            ○ Node(): constructor that creates an empty object of type Node
            ○ Node(string): parametrized constructor. It creates object of type Node with data inside it

    */

    Node::Node(){
        std::cout << "Constructing an empty node...." << std::endl;
        this->data = "";
        this->next = NULL;
        std::cout << "The node has been successfully constructed!" << std::endl;
    }
    Node::Node(string value){
        std::cout << "Constructing a node..." << std::endl;
        this->data = value;
        this->next = NULL;
        std::cout << "The node containing " << value << "has been successfully constructed! " << std::endl;
    }


    /*
                                    GETTERS AND SETTERS

            ----------------------------------GETTERS--------------------------------------
            ○ string GetData(): returns the data inside the node
            ○ Node *GetNext(): returns the pointer to the next node
             ----------------------------------SETTERS--------------------------------------
            ○ void SetData(string): updates the data kept in the node
            ○ void SetNext(Node*): updates the pointer to the next node
             
    */

    string Node::GetData(){
        return this->data;
    }
    Node *Node::GetNext(){
        return this->next;
    }

    void Node::SetData(string value){
        this->data = value;
    }
    void Node::SetNext(Node *next){
        this->next = next;
    }