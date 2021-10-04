#include<string>
#include<iostream>
#include "utils_functions.h"
using namespace std;


string getData(bool isTarget){
    string data;
    if(!isTarget){
        std::cout << "Enter the data of the node => ";
        std::cin>>data;
    }
    else{
        std::cout << "Which target are you looking for? ";
        std::cin>>data;
    }

    return data;
}