/*
••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
         STACKS USNING LINKED LISTS IN C++ WITH OOP APPROACH
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


class StackItem{
    /*
        DATA ATTRIBUTES:
            data: stores the data that will be kept in the StackItem
            next: stores the address of the next StackItem

    */
    string data;
    StackItem *next;

    /*
        CONTRUCTORS:
            ♦ StackItem(): default constructor, it creates an empty object of type StackItem
            ♦ StackItem(string): parametrized constructor, creates object of type StackItem with data inside

    */
public:
    StackItem();
    StackItem(string);


    /*
        ACCESSORS(GETTERS AND SETTERS):
            ----------------------------------GETTERS--------------------------------------
            ♦ string GetData(): returns the data kept in the StackItem
            ♦ StackItem *GetNext(): returns the next StackItem
             ----------------------------------SETTERS--------------------------------------
            ♦ void SetData(string): updates the data kept in the StackItem
            ♦ void SetNext(StackItem*): updates the next StackItem
             
    */

    string GetData();
    StackItem* GetNext();

    void SetData(string);
    void SetNext(StackItem*);

};