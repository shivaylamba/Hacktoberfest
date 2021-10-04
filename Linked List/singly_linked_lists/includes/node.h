/*
••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
         SINGLY LINKED LISTS IN C++ WITH OOP APPROACH
 ****************************************************************
    BAIMAM BOUKAR JEAN JACQUES
    baimam.jeanjaque@ictuniversity.edu.cm
    (+237) 690 53 57 59 / 6 79 78 22 55
••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
*/

#pragma once
/*The #pragma once preprocessor ensures a header file is included only once in a cpp file */
#include <string>
using namespace std;


class Node{
    /*
        DATA ATTRIBUTES OF Node:
            ○ data: stores the data that will be kept in the node
            ○ next: stores the address of the next node

    */
    string data;
    Node *next;

    /*
                                CONTRUCTORS
            ○ Node(): constructor that creates an empty object of type Node
            ○ Node(string): parametrized constructor. It creates object of type Node with data inside it

    */

public:
    Node();
    Node(string);


    /*
                                    GETTERS AND SETTERS

            ----------------------------------GETTERS--------------------------------------
            ○ string GetData(): returns the data inside the node
            ○ Node *GetNext(): returns the pointer to the next node
             ----------------------------------SETTERS--------------------------------------
            ○ void SetData(string): updates the data kept in the node
            ○ void SetNext(Node*): updates the pointer to the next node
             
    */

    string GetData();
    Node* GetNext();

    void SetData(string);
    void SetNext(Node*);

};