// Prints the count of numbers that are multiples of 3 or 5 up to 1000.

#include <iostream>

int main()
{
    int sum = 0;
    for (int x = 1; x < 1000; x++)
    {
        if (x % 3 == 0 || x % 5 == 0)
        {
            sum += x;
        }
    }

    std::cout << sum << std::endl;
}