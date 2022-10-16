//check wheather paranthesis are balanced or not
#include<iostream>
#include<stack>
using namespace std;

bool is_valid_exp(char *s){
	stack<int> stk;
	for(int i=0;s[i]!='\0';i++){
		char ch=s[i];
		if(ch=='('){
			stk.push(ch);
		}
		else if(ch==')'){
			if(stk.empty() or stk.top()!='('){
				return false;
			}
			stk.pop();
		}
	}
	return stk.empty();
}

int main(){
	char s[100]="((a+b)-(c+d)))";
	if(is_valid_exp(s)){
		cout<<"Yes ";
	}
	else{
		cout<<"No ";
	}
	return 0;
}
