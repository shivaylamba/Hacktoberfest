import java.util.Scanner;

 class Calculator implements Arithmetic,Scientific{

	@Override
	public int add(int a, int b) {
		return a + b;
	}

	@Override
	public int sub(int a, int b) {
		return a - b;
	}

	@Override
	public double div(double a, double b) {
		return a/b;
	}

	@Override
	public long mul(long a,long b) {
		return a*b;
	}
	
	@Override
	public long pow(int a, int b) {
		if(b == 0) return 1L;
		long p = pow(a,b/2);
		p = p*p;
		if((b&1) == 1) p = a*p;
		return p;
	}
	
	@Override
	public long fac(int n) {
		if(n <= 1) return 1L;
		return n*fac(n-1);
	}
	
	@Override
	public double log(int a, int b) {
		return Math.log(a)/Math.log(b);
	}
	
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		Calculator c = new Calculator();
      System.out.println("Welcome to Your Calculator :- ");
      
      System.out.println("1. Addition");
      System.out.println("2. Subtraction");
      System.out.println("3. Multiplication");
      System.out.println("4. Division");
      System.out.println("5. Factorial");
      System.out.println("6. Power");
      System.out.println("7. Log");
      String ques = "Enter two numbers : ";
      
      char ch = 'n';
      int a = 0,b = 0;
      do {
      if(ch == 'y' || ch == 'Y') 
      System.out.println("--------------------------------------------------------------");
      System.out.println("Enter the your choice : ");
      int n = sc.nextInt();
      switch(n) {
      case 1: System.out.println(ques);
      a = sc.nextInt();  b = sc.nextInt();
      System.out.println(a+"+"+b+" = "+c.add(a, b));
      break;
      case 2 : System.out.println(ques);
      a = sc.nextInt();  b = sc.nextInt();
      System.out.println(a+"-"+b+" = "+c.sub(a, b));
      break;
      case 3 : System.out.println(ques);
      a = sc.nextInt();  b = sc.nextInt();
      System.out.println(a+"x"+b+" = "+c.mul(a, b));
      break;
      case 4 : System.out.println(ques);
      a = sc.nextInt();  b = sc.nextInt();
      System.out.println(a+"/"+b+" = "+c.div(a, b));
      break;
      case 5 : System.out.println("Enter the number: ");
      a = sc.nextInt();
      System.out.println(a+"! = "+c.fac(a));
      break;
      case 6 : System.out.print(ques);
      a = sc.nextInt(); b = sc.nextInt();
      System.out.println(a+" raise to "+b+" = "+c.pow(a, b));
      break;
      case 7 : System.out.println("Enter the number and the base : ");
      a = sc.nextInt(); b = sc.nextInt();
      System.out.println("Result is : "+c.log(a, b));
      break;
      default : System.out.print("Invalid choice !!! Press (y/n) to proceed further : ");
      ch = sc.next().charAt(0);
      }
      System.out.println("Press (y/n) to Enter more : ");
      ch = sc.next().charAt(0);
      }while(ch == 'y' || ch == 'Y');

	}

	

}

interface Arithmetic{
	int add(int a,int b);
	int sub(int a,int b);
	double div(double a,double b);
	long mul(long a,long b);
	
}
interface Scientific{
	long fac(int n);
	long pow(int a,int b);
	double log(int a,int b);
	
}
