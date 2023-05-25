//Guess The Number / Number Guessing Game in C++
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
back:
    int number, guess, nguesses = 1;
    ;
    srand(time(0));
    number = rand() % 100 + 1; // Generates a random number between 1 and 100
                               // cout<<"The number is "<<number<<endl;
    // Keep running the loop until the number is guessed

    // cout<<"The number is "<<number<<endl;
    do
    {
        cout << "Guess the number between 1 to 100" << endl;
        cin >> guess;
        if (guess > number)
        {
            cout << "Lower number please!" << endl;
        }
        else if (guess < number)
        {
            cout << "Higher number please!" << endl;
        }
        else
        {
            cout << "You guessed it in " << nguesses << " attempts" << endl;
        }
        nguesses++;
    } while (guess != number);

    char restart;
    cout << "press R for play again:";
    cin >> restart;
    if (restart == 'R' || restart == 'r')
    {
        goto back;
    }
    else
    {
        cout << "INVALID CODE" << endl;
    }

    return 0;
}
