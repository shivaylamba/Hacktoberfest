import java.util.*;
public class FunctionQuestions {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		System.out.println(isPrime(n));

	}
	
	//best method to check whether prime or not
	
//	static boolean isPrime(int n) {
//      if(n<= 1) {
//    	  return false;
//      }
//      int c = 2;
//      while(c*c <= n) {
//    	  if(n%c == 0) {
//    		  return false;
//    	  }
//    	  c++;
//      }
//      return c * c > n;
//	}
	
	//Another method
	static boolean isPrime(int n) {
	    int c = 0;
	    for(int i = 2; i<=n-1; i++) {
	    	if(n%i==0) {
	    		c++;
	    	}
	    }
	    	if(c > 0) {
	    		return false;
	    	}
	    	else {
	    		return true;
	    		
	    	}
	      }
	     
	}



