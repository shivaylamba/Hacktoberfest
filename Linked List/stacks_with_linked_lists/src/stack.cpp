/*
••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
         STACKS USNING LINKED LISTS IN C++ WITH OOP APPROACH
 ****************************************************************
    BAIMAM BOUKAR JEAN JACQUES
    baimam.jeanjaque@ictuniversity.edu.cm
    (+237) 690 53 57 59 / 6 79 78 22 55
••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
*/

#include <iostream> 
#include <string>
#include "stack.h"
#include "stack_item.h"
using namespace std;   
    /*
        CONTRUCTORS AND DESTRUCTOR:
            ------------------------CONSTRUCTORS-----------------------------

            ♦ Stack(): default constructor, it creates an empty object of type Stack
            ♦ Stack(string): parametrized constructor, creates object of type Stack with
                data inside the first element

            ----------------------DESTRUCTOR---------------------------------

            ♦ ~Stack(): destroys the stack

    */
    
    Stack::Stack(){
        this->top = NULL;
        this->size = 0;
    } 

    Stack::Stack(string data){
        StackItem *item = new StackItem(data);
        item->SetNext(NULL);
        this->top = item;
        this->size = 1;
    }

    Stack::~Stack(){
         std::cout << "Destroying the stack...." << std::endl;
        StackItem *ptr = this->GetTop(), *next = NULL;
        while( ptr!= NULL)
        {
            next = ptr->GetNext();
            delete(ptr);
            ptr = next;
        }
        std::cout << "Stack destroyed...." << std::endl;
    }


    /*
        ACCESSORS(GETTERS AND SETTERS):
            ----------------------------------GETTERS--------------------------------------
            ♦ StackItem* GetTop(): returns the top element of the stack
            ♦ int GetSize(): returns the size of the stack
             ----------------------------------SETTERS--------------------------------------
            ♦ void SetTop(StackItem*): updates the top of the stack
            ♦ void SetSize(int): updates the size of the stack
             
    */

    StackItem* Stack::GetTop(){
        return this->top;
    }
    int Stack::GetSize(){
        return this->size;
    }

    void Stack::SetTop(StackItem *top){
        this->top = top;
    }
    void Stack::SetSize(int size){
        this->size = size;
    }


    /*
        METHODS OF THE CLASS STACK:
            ♦ void Info(): give some informations about stacks
            ♦ void Push(string): add element in the stack
            ♦ void Pop(): remove element from the stack
            ♦ bool IsEmpty(): returns true if the stack is empty
            ♦ bool Search(string): search a specific target in the stack
            ♦ Display(): traverse the stack an print each element


    */

    void Stack::Info(){
        std::cout << "---------------WHAT ARE STACKS ?----------------" << std::endl;
        std::cout 
            <<"Stacks are LIFO(Last In First Out) data structures \n"
            << "When dealing with stacks, we have generally three methods \n"
            <<"* A method to push element in the stack: It insert element at the top most of the stack \n"
            <<"* A method to delete element from the stack: It removes the topmost element of the stack"
            <<"i.e the most recently inserted element \n"
            <<"* A method to check if the stack is empty"
        <<std::endl;
        std::cout << "------------------------------------------------------" << std::endl;
    }

    void Stack::Push(string data){
        /*
            Push(): inserts the [data] passed as argument at the top of the stack
            It first of all move the top of stack to next
            Then it fits the new element at topmost of the stack
        */

        std::cout << endl << "Inserting " << data << " in the stack...." << std::endl;
        StackItem *item = new StackItem(data);

        if(this->GetTop() == NULL){
            item->SetNext(NULL);
        }
        else{
            item->SetNext(this->GetTop());
        }
        this->SetTop(item); //updating the top of the stack
        this->SetSize(this->GetSize() + 1); //incrementing the size of the stack

        std::cout << data << " has been inserted in the stack..." << std::endl;
        std::cout << "The new Stack is: " << std::endl;
        this->Display();
    }
    void Stack::Pop(){
        //Preventing to pop an empty stack
        if(this->GetTop() == NULL){
            std::cout << "|||***Cannot pop empty stack***|||" << std::endl;
        }

        //poping-up the stack
        std::cout << endl << "Poping-up the stack......" << std::endl;

        StackItem *item = this->GetTop();
        this->SetTop(item->GetNext());
        delete(item);

        this->SetSize(this->GetSize() - 1);
        std::cout << "Stack pop has been successful...." << std::endl;
        std::cout << "The new Stack is: " << std::endl;
        this->Display();
    }
    bool Stack::IsEmpty(){
        //check if the size of the stack is less than 1(i.e it is empty)
        if(this->GetSize() < 1){
            return true;
        }
        else{
            return false;
        }
    }

    bool Stack::Search(string target){
         if (this->IsEmpty())
        {
            std::cout << "|||*** This stack is empty ***|||" << std::endl;
            return false;
        }
        StackItem *ptr = this->GetTop();
        int index = 1;
        while (ptr->GetNext() != NULL)
        {
            if(ptr->GetData() == target){
                std::cout << target << " found in the stack at position " << index << std::endl;
                return true;
            }
             //Mooving the pointer to the next item
             ptr = ptr->GetNext();
             index++;
        }
        //check if the lastest elemet of the stack is the target
        if(ptr->GetData() == target){
                std::cout << target << " found in the stack at position " << index << std::endl;
                return true;
            }
            
        std::cout << "---------------------------------------------------" << std::endl;

    }

    void Stack::Display(){
        //Preventing to traverse an empty stack
        if (this->IsEmpty())
        {
            std::cout << "|||*** This stack is empty ***|||" << std::endl;
            return;
        }

        //Traversing the satck and printing each item
        std::cout << "This stack has " << this->GetSize() << " items" << std::endl;
        StackItem *ptr = this->GetTop();
        int index = 1;
        while (ptr->GetNext() != NULL)
        {
            //Printing the item
            std::cout 
                << index
                << " - "
                << ptr->GetData()
             <<std::endl;

             //Moving the pointer to the next item
             ptr = ptr->GetNext();
             index++;
        }
        //Printing the lastest item
            std::cout 
                << index
                << " - "
                << ptr->GetData()
             <<std::endl;
        std::cout << "---------------------------------------------------" << std::endl;

    }
