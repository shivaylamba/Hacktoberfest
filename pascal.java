// Pascal's Triangle 

import java.util.*; 

class pascal { 
	
	// Function to print the triangle...
	static void runpascal(int nm) 
	{  
	for (int i = 0; i < nm; i++) 
	{ 
		for (int j = 0; j <= i; j++) 
		{
		   System.out.print(bincoff(i, j)+" "); 
		 }  
						
		System.out.println(); 
	} 
	} 
    
    //to obtain the factorial
	static int fact(int x) 
	{  
		int f=1;
		for(int i = 1; i <= x; i++)
		{
		  f*=i;
		}
		return f;
	} 
	
	//to get the binomial coefficient
	static int bincoff(int a, int b) 
	{  
		
		if (b > a - b) 
		{
		  b = a - b; 
		 }
			

		int nume = fact(a);
		int deno = fact(b) * fact(a-b);
		int r = nume / deno;
				return r; 
	} 
	
	//main function 
	public static void main(String args[]) 
	{ 
		Scanner ob = new Scanner(System.in);
	int n = ob.nextInt();
	runpascal(n); 
	} 
} 


