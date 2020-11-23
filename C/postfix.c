/*This is a c program to convert a infix expression to postfix form and evaluvate the expression
The program takes an infix expression from the user and gives the corresponding postfix form and evaluvates the expression and gives the result. 
*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>
#include<ctype.h>
#include <math.h>
#define size 20
int it=0;
//fumction to pop an element
char pop(char s[20],int top){
	char item;
	item=s[top];
	return item;
}
//function to push an element
void push(char s[20],int top,char item){
	if(top<size){
		s[top]=item;
	}
	else{
		printf("\nThe stack is full");
	}
}
//this function returns the next character
char nexttoken(char ch[20]){
	
	return ch[it];
	//it++;
}
//this function contains the in-stack priority
int isp(char c){
	switch(c){
		case '+':
		case '-':return 1;break;
		case '*':
		case '%':
		case '/':return 2;break;
		case '^':return 3;break;
		case '(':return 0;break;
		case '#':return -1;break;
		default: return 0;break;
	}
}
//this function returns the incoming priority
int icp(char c){
	switch(c){
		case '+':
		case '-':return 1;break;
		case '*':
		case '%':
		case '/':return 2;break;
		case '^':return 3;break;
		case '(':return 4;break;
		case ')':return 5;break;
		case '#':return -1;break;
		default: return 0;break;
	}
}
//this function gives the postfix form
int postfix(char a[20],int a_top){
	int i,top=0;
	char x,y,stack[20],ch[20];
	stack[top]='#';
	top++;
	printf("\nEnter the Expression");
	printf("\nThe operands are from 0-9 and operators are +,-,*,/,^\n");
	scanf("%s",ch);
	x=nexttoken(ch);
	printf("\nThe postfix form is\t");
	while(x!='\0'){
		if(isdigit(x)!=0){
			printf("%c",x );
			a_top++;
			push(a,a_top,x);
		}
		else if(x==')'){
			while(stack[top]!='('){
				y=pop(stack,top);
				top--;
				printf("%c",y);
				a_top++;
				push(a,a_top,y);
			}
			y=pop(stack,top);
			top--;
		}
		else{
			while(isp(stack[top])>=icp(x)){
				y=pop(stack,top);
				top--;
				printf("%c",y);
				a_top++;
				push(a,a_top,y);
			}
			top++;
			push(stack,top,x);
		}
		it++;
		x=nexttoken(ch);
	}
	while(top>0){
		y=pop(stack,top);
		top--;
		printf("%c",y);
		a_top++;
		push(a,a_top,y);
	}
	return a_top;
}
//this function returns the value after performing the operation
char evaluvate(char y,char x,char z){
	int a,b;
	a=y-'0';
	b=z-'0';
	switch(x){
		case '+':return ((a+b)+'0');break;
		case '-':return ((a-b)+'0');break;
		case '*':return ((a*b)+'0');break;
		case '/':return ((a/b)+'0');break;
		case '^':return ((pow(a,b))+'0');break;
		case '%':return ((a%b)+'0');break;
	}
}
//this function performs the evaluvation and returns the final value
void eval(char ch[20]){
	int top=-1;
	it=0;
	char x,stack[20],y,z;
	x=nexttoken(ch);
	while(x!='\0'){
		if(isdigit(x)!=0){
			top++;
			push(stack,top,x);
		}
		else{
			z=pop(stack,top);
			top--;
			y=pop(stack,top);
			top--;
			y=evaluvate(y,x,z);
			top++;
			push(stack,top,y);
		}
		it++;
		x=nexttoken(ch);
	}
	printf("\nThe result of the Expression is \t%d",stack[top]-'0');
}
//main function
int main(){
	char a[20];
	int i,a_top=-1;
	a_top=postfix(a,a_top);
	//printf("\n%s",a);
	eval(a);
	getch();
}