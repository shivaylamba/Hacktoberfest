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

class Stack{
    /*
        DATA ATTRIBUTES:
            ♦ top: stores the address of the first element of the stack
            ♦ size: stores the number of elements of the stack

    */

    StackItem *top;
    int size;

    /*
        CONTRUCTORS AND DESTRUCTOR:
            ------------------------CONSTRUCTORS-----------------------------

            ♦ Stack(): default constructor, it creates an empty object of type Stack
            ♦ Stack(string): parametrized constructor, creates object of type Stack with
                data inside the first element

            ----------------------DESTRUCTOR---------------------------------

            ♦ ~Stack(): destroys the stack

    */
public:
    Stack();
    Stack(string data);
    ~Stack();


    /*
        ACCESSORS(GETTERS AND SETTERS):
            ----------------------------------GETTERS--------------------------------------
            ♦ StackItem* GetTop(): returns the top element of the stack
            ♦ int GetSize(): returns the size of the stack
             ----------------------------------SETTERS--------------------------------------
            ♦ void SetTop(StackItem*): updates the top of the stack
            ♦ void SetSize(int): updates the size of the stack
             
    */

    StackItem* GetTop();
    int GetSize();

    void SetTop(StackItem *top);
    void SetSize(int size);


    /*
        METHODS OF THE CLASS STACK:
            ♦ void Info(): give some informations about stacks
            ♦ void Push(string): add element in the stack
            ♦ void Pop(): remove element from the stack
            ♦ bool IsEmpty(): returns true if the stack is empty
            ♦ bool Search(string): search a specific target in the stack
            ♦ Display(): traverse the stack an print each element


    */
    void Info();
    void Push(string data);
    void Pop();
    bool IsEmpty();

    bool Search(string target);

    void Display();

};