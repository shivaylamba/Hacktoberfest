// Valid Credit Cards
// Amex - 378282246310005
// MsterCard - 5404000000000001
// Visa - 4242424242424242



#include <stdio.h>
#include <cs50.h>

int main(void)
{
    
    long long number, check1, check2;
    
    // prompt for user input of credit card number
    do
    {
        number = get_long("Enter Credit Card number: ");
    }
    while (number < 0);
    
    
    int n1, n2, sum_of_n1, sum_of_n2_products;
    sum_of_n1 = 0;
    sum_of_n2_products = 0;
    
    check1 = number;
    check2 = number;
    
    // Validate checksum using Luhn's algorithm
    while (check1 > 0)
    {
        n1 = check1 % 10;
        sum_of_n1 += n1;
        check1 -= n1;
        check1 /= 10;
        
        n2 = check1 % 10;
        
        if ( (n2 * 2) > 9)
        {
            int n2_t2 = n2 * 2;
            sum_of_n2_products += n2_t2 % 10;
            sum_of_n2_products += (n2_t2 - (n2_t2 % 10)) / 10;
        }
        else{
            sum_of_n2_products += (n2 * 2);
        }
            
        check1 -= n2;
        check1 /= 10;
    }
    
    
    // Validate Credit Card company
    // Validate number's length
    if ( (sum_of_n1 + sum_of_n2_products) % 10 == 0)
    {
        bool amex, mc, visa;
        
        amex = 
            (check2 >= 340000000000000 && check2 < 350000000000000) || 
            (check2 >= 370000000000000 && check2 < 380000000000000);
            
        mc = 
            (check2 >= 5100000000000000 && check2 < 5600000000000000);
            
        visa = 
            (check2 >= 4000000000000 && check2 < 5000000000000) || 
            (check2 >= 4000000000000000 && check2 < 5000000000000000);
        
        if (amex)
            printf("AMEX\n");
        else if (mc)
            printf("MASTERCARD\n");
        else if (visa)
            printf("VISA\n");
        else
            printf("INVALID\n");

    }
    else
    {
        printf("INVALID\n");
    }
    
}
