#include <stdio.h>

struct bank
{
    unsigned long int acc_num;
    char name[25];
    unsigned int balance;
} C[50];

void less_balance(int);
void withdraw(int);

int main()
{
    int n;
    printf("Enter the number of customers whose details you wanna enter:");
    scanf("%d", &n);
    fflush(stdin);

    for (int i = 0; i < n; i++)
    {
        printf("\nDetails of Client %d:\n", i + 1);
        printf("Enter the name: ");
        gets(C[i].name);

        printf("Enter the Account Number of %s :", C[i].name);
        scanf("%d", &C[i].acc_num);

        printf("Enter the balance in %s's account:", C[i].name);
        scanf("%d", &C[i].balance);
        fflush(stdin);
    }

    less_balance(n);
    withdraw(n);
    return 0;
}

void less_balance(int n)
{
    printf("\nDetails of Customers having balance less than Rs.100:\n");
    printf("NAME \t ACC.NO. \t BALANCE\n");

    for (int i = 0; i < n; i++)
    {
        if (C[i].balance < 100)
        {
            printf("%s \t %d \t %d\n", C[i].name, C[i].acc_num, C[i].balance);
        }
        else
            continue;
    }
}

void withdraw(int n)
{
    int code;
    int acc;
    int amount = 0;

    printf("\nEnter 0 for withdrawal.\n");
    printf("Enter 1 to deposit.\n");
    printf("Code:");
    scanf("%d", &code);

    printf("Enter the Account Number:");
    scanf("%d", &acc);
    fflush(stdin);

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (C[i].acc_num == acc)
        {
            k = i;
        }
    }
    switch (code)
    {
    case 0:
        printf("Enter the amount you want to withdraw:");
        scanf("%d", &amount);
        fflush(stdin);
        if (C[k].balance - amount < 100)
        {
            printf("Insufficient Balance");
        }
        else
            C[k].balance = C[k].balance - amount;
        break;

    case 1:
        printf("Enter the amount you want to deposit:");
        scanf("%d", &amount);
        fflush(stdin);
        C[k].balance = C[k].balance + amount;
        break;

    default:
        printf("*Invalid Input*\n");
        break;
    }

    printf("\nNAME \t ACC.NO. \t BALANCE\n");
    for (int i = 0; i < n; i++)
    {

        printf("%s \t %d \t %d\n", C[i].name, C[i].acc_num, C[i].balance);
    }
}
