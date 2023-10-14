#include <stdio.h>
#define size 20
#include <string.h>
void push(char ch);
void pop();
char in[size], s[size], top = -1;
int main() {
  char ch;
  printf("Enter the infix operation\n");
  scanf("%s", in);
  top = top + 1;
  s[top] = '#';
  for (int i = 0; i < strlen(in); i++) {
    ch = in[i];
    // printf("%d")
    if (ch == '(') {
      push(ch);
    }
    if (ch == ')') {
      if (s[top] != '#') {
        pop();
      } else {
        printf("closing parenthesis are not balanced\n");
        return 0;
      }
    }
  }
  if (s[top] == '#') {
    printf("parenthesis are balanced\n");
  } else {
    printf("Opening parenthesis are not balanced\n");
  
  }
}

void push(char ch) {
  top = top + 1;
  s[top] = ch;
  // printf("%c",s[top]);
}

void pop() { top = top - 1; }
