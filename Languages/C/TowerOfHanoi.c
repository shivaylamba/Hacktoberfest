#include <stdio.h>

void moveTower(int n, char src, char dst, char spare, int moves[]) {
  //moves[] added so that it can count number of moves
  if (n==1) {moves[0]+=1; printf("Move from %c to %c\n", src, dst);}
  else {
    moveTower(n-1, src, spare, dst, moves);
    moves[0]+=1;
    printf("Move from %c to %c\n", src, dst);
    moveTower(n-1, spare, dst, src, moves);
  }
  return;
}

int main(void) {
  int n, moves[1]={0};
  printf("Give no of disks (>0) = ");
  scanf("%d", &n);
  printf("\nMOVES\n");
  moveTower(n, 'A', 'B', 'C', moves);
  printf("No. of moves = %d\n", moves[0]);
  return 0;
}
