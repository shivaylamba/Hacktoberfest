/*
••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
         SINGLY LINKED LISTS IN C++ WITH OOP APPROACH
 ****************************************************************
    BAIMAM BOUKAR JEAN JACQUES
    baimam.jeanjaque@ictuniversity.edu.cm
    (+237) 690 53 57 59 / 6 79 78 22 55
••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
*/


#include <iostream>
#include <string>
#include "node.h"
#include "linked_list.h"
#include "utils_functions.h"

using namespace std;


int main(int arguments_count, char** arguments_list)
{
    int choice;
    string menu[8] = {
        "*************OPERATIONS WITH SINGLY LINKED LISTS************",
        "1. Insert node on the head",
        "2. Insert node at a position",
        "3. Insert node at tail",
        "4. Search data in the list",
        "5. Delete data from the list",
        "6. Display the list",
        "7. EXIT"
    };

    //Creating a new object of type list
    LinkedList *List = new LinkedList();

    /*
        checking if there are arguments passed from the terminal:
            ♣ if true: nodes will be constructed with those value and added to the list
            ♣ if !true: no nodes will be contructed
    */

    if(arguments_count < 2){
        std::cout << "No arguments passed... ! No node to build..." << std::endl;
        std::cout << "*********************************************" << std::endl;
    }
    else{
        std::cout << "**********************************************" << std::endl;
        std::cout << "Generating " << arguments_count - 1 << " nodes elements with the passsed parameters..." << std::endl;
           
           //traversing the arguments values and inserting nodes at tail of the list with nodes built with each item of arguments_list
            for (int i = 1; i < arguments_count; i++) {
                std::cout << arguments_list[i] << " ==> ";
                List->InsertAtTail(arguments_list[i]);

        }

        std::cout << "The list has been built with the arguments..." << std::endl;
        std::cout << "*********************************************" << std::endl;

    }

    while (true)
    {
        //displaying to menu to the user
        std::cout<<std::endl;
            for (int i = 0; i < 8; i++)
            {
                 std::cout << menu[i] << std::endl;   
            }
        std::cout<<std::endl;
            std::cout << "Press the corresponding key to your choice: ";
            std::cin>>choice;

            

            /*
                switch(choice) call the corresponding method to the user's
                choice......
            */

            switch (choice)
            {
                case 1:
                    List->InsertAtHead(getData(false));
                    break;
                case 2:
                    int position;
                    std::cout << "Please enter the position where you want to insert data: ";
                    std::cin>>position;
                    List->InsertAtPosition(getData(false), position);
                    break;
                case 3:
                    List->InsertAtTail(getData(false));
                    break;
                case 4:
                    List->Search(getData(true));
                    break;
                case 5:
                    List->DeleteNode(getData(true));
                    break;
                case 6:
                    List->Display();
                    break;
                case 7:
                    exit(0);
                default:
                    std::cout << "Please press a valid key: ";
                    exit(0);
                    break;
            }

    }    
    system("pause");
    return 0;
}
