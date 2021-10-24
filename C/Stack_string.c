// Harshit Paneri 
#include<stdio.h>
void push(char);
void pop();
int top;
char str[50], stack[50];

int main()
{
    int i;
    printf("Enter the string:\n");
    gets(str);
    for(i=0;str[i]!='\0';i++)
        push(str[i]);
    for (i=top;i>=0;i--)
        pop();

    return 0;
}

void push(char x)
{
    if(top==49)
    {
        printf("\n\tSTACK is over flow");
        
    }
    else
    {
        top++;
        stack[top]=x;
    }
}

void pop()
{
    if(top==-1)
    {
        printf("\n\t Stack is under flow");
    }
    else
    {
        printf("%c",stack[top]);
        //printf("%c",str[top]);
        top--;  
    }
}
