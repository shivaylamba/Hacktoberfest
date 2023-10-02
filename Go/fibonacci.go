package main

import "fmt"

func main(){
	var num int
	fmt.Print("Enter the number of terms: ")
	fmt.Scanf("%d",&num)
	for i :=1; i<=num;i++{
		result := fibonacci(i)
		fmt.Println(i," : ",result)

	}

	fmt.Println(fibonacci_arrays(20))
}

func fibonacci(n int ) int {
	if n <=2 {
		return n
	}else{
		return fibonacci(n-1)+fibonacci(n-2)
	}
}

func fibonacci_arrays(n int) []int{
	if n<=2{
		return make([]int,0)
	}
	fib := make([]int,n)
	fib[0], fib[1] = 1,1
	for i:=2;i<n;i++{
		fib[i]=fib[i-1]+fib[i-2]
	} 
	return fib
}