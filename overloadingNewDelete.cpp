#include <iostream>
using namespace std;
struct value
{
    int t;
    void* operator new(size_t n)                        // definition of new
    {
        cout << "Overloaded new" << "\n";
        void *ptr=malloc(n);                            // memory allocated to ptr
        return ptr;
    }
    void operator delete(void *p)                       // definition of delete
    {
        cout << "Overloaded delete" << "\n";
        free(p);                                        // deallocated memory
    }
};
int main()
{
    value *p=new value;                    // calling overloaded operator new
    delete p;                              // calling overloaded operator delete
    return 0;
}
