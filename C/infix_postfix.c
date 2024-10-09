#include<stdio.h>
#include<string.h>
char stack[50];
int top=-1;
void in_to_post( char infix[]);
void push(char);
char pop();
int main()
{
	char infix[25];
	printf("enter infix expression:");
	gets(infix);
	in_to_post(infix);
}
void push(char symbol)
{
	if(top>=49)
	{
		printf("stack overflow:");
		return;
	}
	else
	{
		top=top+1;
		stack[top]=symbol;
	}
}
char pop()
{
	char item;
	if(top==-1)
	{
		printf("stack is empty:");
		return(0);
	}
	else
	{
		item=stack[top];
		top--;
	}
	return(item);
}
int precedence(char ch)
{
	if(ch=='^')
	{
		return(3);
	}
	else if(ch=='/'|| ch=='*')
	{
		return(2);
	}
	else if(ch=='+'|| ch=='-')
	{
		return(1);
	}
	else
	return(-1);
}
void in_to_post(char infix[])
{
	 static int i=0,j=0;
	 char symbol,temp;
	 char postfix[40];
	 for(i=0;i<strlen(infix);i++)
	 {
	 	symbol=infix[i];
	 	switch(symbol)
	 	{
	 		case '(' :push(symbol);
	 		           break;
	 		case  ')':
			 while((temp=pop()) !='(')
			 {
			 	postfix[j++]=temp;
		    }
		    break;
		    case '+':
		    case '-':
			case  '*':
			case  '/':
			case '^':
			while( precedence(stack[top]>=precedence(symbol)))
			{
				postfix[j++]=pop();
		    }
		    push(symbol);
		    break;
		    default:postfix[j++]=symbol;
		    break;
		 }
	 }
	 while(top>0)
	 {
	 	postfix[j++]=pop();
	 }
	 postfix[j]='\0';
	 puts(postfix);
	 return;
}
