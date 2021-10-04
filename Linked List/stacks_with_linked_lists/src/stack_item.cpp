/*
••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
         STACKS USNING LINKED LISTS IN C++ WITH OOP APPROACH
 ****************************************************************
    BAIMAM BOUKAR JEAN JACQUES
    baimam.jeanjaque@ictuniversity.edu.cm
    (+237) 690 53 57 59 / 6 79 78 22 55
••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
*/


#include "stack_item.h"
#include <string>
#include <iostream>
using namespace std;


    /*
        CONTRUCTORS:
            ♦ StackItem(): default constructor, it creates an empty object of type StackItem
            ♦ StackItem(string): parametrized constructor, creates object of type StackItem with data inside

    */

    StackItem::StackItem(){
        std::cout << "building item with default constructor..." << std::endl;
        this->data = "";
        this->next = NULL;
        std::cout << "Item successfully built..." << std::endl;
    }
    StackItem::StackItem(string value){
        std::cout << "building item with parametrized constructor..." << std::endl;
        this->data = value;
        this->next = NULL;
        std::cout << "Item built with paramater " << value  << std::endl;
    }


    /*
        ACCESSORS(GETTERS AND SETTERS):
            ----------------------------------GETTERS--------------------------------------
            ♦ string GetData(): default constructor, it creates an empty object of type StackItem
            ♦ StackItem *GetNext(): parametrized constructor, creates object of type StackItem with data inside
             ----------------------------------SETTERS--------------------------------------
            ♦ void SetData(string): updates the data kept in the StackItem
            ♦ void SetNext(StackItem*): updates the next StackItem
             
    */

    string StackItem::GetData(){
        return this->data;
    }
    StackItem* StackItem::GetNext(){
        return this->next;
    }

    void StackItem::SetData(string value){
        this->data = value;
    }
    void StackItem::SetNext(StackItem *next){
        this->next = next;
    }
