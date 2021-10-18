class Fibonacci
{
    public static void main(String args[]) 
    {
        int num1=0, num2=1, num3, i, count=10 ;
        System.out.print(num1 + " " +num2); // i=0 and i=1 i.e. num1 and num2 will be printed 

        for(i=2; i<count; ++i)  //loop starts
        {
           num3 = num1 + num2;
           System.out.print(" " + num3);
           num1= num2;
           num2 = num3;
        }
    }
}




/////////////we can do it using recursion also////////////////////


public class Fibonacci{
	public static int fibonacciRecursion(int n){
        if(n == 0){
            return 0;
        }
        if(n == 1 || n == 2){
                return 1;
            }
     return fibonacciRecursion(n-2) + fibonacciRecursion(n-1);
	}
    public static void main(String args[]) {
	int count = 10;
	
	for(int i = 0; i < count; i++){
			System.out.print(fibonacciRecursion(i) +" ");
		}
	}
}
