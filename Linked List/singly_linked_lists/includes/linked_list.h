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


class LinkedList{
    /*
        DATA ATTRIBUTES:
            ♦ head: stores the address of the first node of the list
            ♦ size: stores the number of elements of the list

    */

    Node *head;
    int size;

    /*
        CONTRUCTORS AND DESTRUCTOR:
            ------------------------CONSTRUCTORS-----------------------------

            ♦ List(): default constructor, it creates an empty object of type List
            ♦ List(string): parametrized constructor, creates object of type List with
                data inside the first node

            ----------------------DESTRUCTOR---------------------------------

            ♦ ~List(): destroys the list

    */
public:
    LinkedList();
    LinkedList(string data);
    ~LinkedList();


    /*
        ACCESSORS(GETTERS AND SETTERS):
            ----------------------------------GETTERS--------------------------------------
            ♦ Node* GetHead(): returns the head of the list
            ♦ int GetSize(): returns the size of the list
             ----------------------------------SETTERS--------------------------------------
            ♦ void SetHead(Node*): updates the head of the list
            ♦ void SetSize(int): updates the size of the list
             
    */

    Node* GetHead();
    int GetSize();

    void SetHead(Node *head);
    void SetSize(int size);


    /*
        METHODS OF THE CLASS LIST:
        -----------------------INSERTIONS-----------------------------------
            ♦ void HeadInsert(string): add node at the head of the list
            ♦ void TailInsert(string): add node at the tail of the list
            ♦ void PositionInsert(string, int): add node at position k in the list

            ♦ bool Search(string): search a specific target in the list
            ♦ void DeleteNode(string): delete a node whose data is the target


    */

    void InsertAtHead(string data);
    void InsertAtTail(string data);
    void InsertAtPosition(string data, int position);

    bool Search(string target);
    void DeleteNode(string target);

    void Display();

};