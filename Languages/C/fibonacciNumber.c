// fibonacci sequence
int main(){
  // test number
  int n = 6;
  int fib[n+2];

  // beginning of fibonacci sequence
  fib[0] = 0;
  fib[1] = 1;

  // perform sequence and populate array
  for (int i = 2; i <= n; i++){
    fib[i] = fib[i-1] + fib[i-2];
  }

  // the n-th number in the sequence
  int result = fib[n];

  printf("The %dth number is %d\n", n, result);
}
