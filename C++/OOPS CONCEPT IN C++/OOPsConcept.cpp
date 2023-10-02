// // object and class & mmemory allocation



// #include <iostream>
// using namespace std;
// // class
// class animal{
//     public:
//     int wild ;
// };
// int main()
// {
//     // creating object 
//     // static memoey allocation
//     animal lion;
//     //dynamic memory allocation
//    animal *tiger = new animal;
//   // to get access
//     lion.wild=5;
//     (*tiger).wild = 8;
// cout<< "Properties : " <<lion.wild<<endl;
// //dynamically print
// cout<< "Properties : " <<(*tiger).wild<<endl;
// return 0;
// }






// getter and setter

// #include <iostream>
// using namespace std;
// // class
// class animal{
//     private:
//     int wild ;
// public:
//  // // constructor 
// // animal(){
// //     cout<<"constructor called"<<endl;
// // }
// // // parameterized constructor
// // animal(int wild){
// //     cout<<"constructor called"<<endl;
// //     this->wild=wild;
// // }
//     int getwild(){
//         return wild;
//     }
//     void setwild(int h){
//         wild = h;
//     }
// };
// int main()
// {
//     // creating object 
//     animal lion; 
//     // to get access
//     lion.setwild(10);

// cout<< " print"<<lion.getwild()<<endl;
// return 0;
// }

 



//   copy constructor

// #include <iostream>
// using namespace std;
// // class
// class animal{
//     public:
//     int wild ;
// animal(){
//     cout<<"default constructor called"<<endl;
// }

// // copy constructor by user
//      animal(animal& temp){
//         cout<<"Copy constructor called"<<endl;
//         this->wild= temp.wild;
//     }

//     // distructor called
//     ~animal(){
//         cout<<"destructor"<<endl;
//     }
// };
// int main()
// {
   
//     // creating object 
//     animal lion; 
//   // to get access
//      lion.wild=6;

//      // copy constructor default
//     // animal tiger(lion); 


//      animal temp(lion); 

// cout<< " print"<<temp.wild<<endl;
// return 0;
// }





// ENCAPSULATION


// #include <iostream>
// using namespace std;
// // class
// class student{
//     private:
//     string name;
//     int age;
//     int height;

//     public:
//     // functions
//     int getAge(){
//         return this->age;
//     }
// };
// int main()
// {
// student first;

// cout<<"Encapsulation called"<<endl;
// return 0;
// }


// INHERITANCE

// #include <iostream>
// using namespace std;
// // human class (Parents class)
// class Human{
//    public:
//     int weight;
//     int age;
//     int height;

//     public:
//     // functions
//     int getAge(){
//         return this->age;
//     }
//     void setweight(int w){
//         this->weight=w;
//     }
// };
// // Male class inheriting human class (child class)

// class Male:public Human {
// public:
//  string color;
//  // function
//  void sleep(){
//     cout<<"Male is sleeping"<<endl;
//  }
// };
// int main()
// {
    
// Male object1;

// // getting access from parent class
// cout<<object1.age<<endl;
// cout<<object1.weight<<endl;
// cout<<object1.height<<endl;

// cout<<object1.color<<endl;

//   // function
// object1.sleep();
// return 0;
// }






//SINGLE INHERITANCE

// #include <iostream>
// using namespace std;
// class Animal{
// public:
// int age;
// int weight;

// public:
// void speak(){
//     cout<<"speaking"<<endl;
// }
// };
// class Dog:public Animal{
// };
// int main()
// {
// Dog d;
// d.speak();
// cout<<d.age<<endl;
// return 0;
// }





// MULTILEVEL INHERITANCE

// #include <iostream>
// using namespace std;
// class Animal{
// public:
// int age;
// int weight;

// public:
// void speak(){
//     cout<<"speaking"<<endl;
// }
// };
// // inherited to Animal
// class Dog:public Animal{
// };
// // inherited to Dog
// class GermanShepherd:public Dog{

// };
// int main()
// {
// GermanShepherd d;
// d.speak();
// cout<<d.age<<endl;
// return 0;
// }





// MULTIPLE INHERITANCE

// #include <iostream>
// using namespace std;
// class Animal{
// public:
// int age;
// int weight;

// public:
// void bark(){
//     cout<<"barking"<<endl;
// }
// };
// class Human{
// public:
// string color;

// void speak(){
//   cout<<"speaking"<<endl;  
// }
// };
// // multiple inheritance
// class Hybrid:public Animal,public Human{
// };
// int main()
// {
// Hybrid h;
// h.speak();
// h.bark();
// return 0;
// }




// Heirarchical inheritance

// #include <iostream>
// using namespace std;
// class A{
// public:
// void func1(){
//     cout<<"Inside function 1"<<endl;
// }
// };
// // inherit A
// class B:public A{
// public:
// void func2(){
//     cout<<"Inside function 2"<<endl;
// }
// };
// // inherit A
// class C:public A{
// public:
// void func3(){
//     cout<<"Inside function 3"<<endl;
// }
// };
// int main()
// {
// B obj1;
// C obj2;
// obj1.func1();
// obj1.func2();

// obj2.func1();
// obj2.func3();

// return 0;
// }




// POLYMORPHISM


// FUNCTION OVERLOADING

// #include <iostream>
// using namespace std;
// class A{
//     public:
//     void sayHello(){
//         cout<<"Hello"<<endl;
//     }

//     void sayHello(char name,int n){
//         cout<<"Hello A"<<endl;
//     }

//     void sayHello(string name){
//         cout<<"Hello B"<<endl;
//     }
// };
// int main()
// {
//     A obj;
//     obj.sayHello();

// return 0;
// }




// METHOD OVERRIDING

#include <iostream>
using namespace std;
class Animal{
    public:
    // same function and argument
    void speak(){
      cout<<"Speaking";
    }
};

class Dog:public Animal{
    public:
     // same function and argument
    void speak(){
      cout<<"Barking";
    }
};
int main()
{
Dog obj;
obj.speak();
return 0;
}